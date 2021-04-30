/*Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]] */

class Solution {
public:
    void diagonalBubbleSort(vector<vector<int>>& mat, int start_row, int start_col){
        const int rowSize = mat.size(), colSize = mat[0].size();
        int iteration, row, col, len = max(rowSize - start_row, colSize - start_col);
        for(iteration = 0;iteration < len - 1;iteration++){
            for(row = start_row + 1, col = start_col + 1;
                row < rowSize && col < colSize;
                row++, col++){
                
                if(mat[row - 1][col - 1] > mat[row][col]){
                    int tmp = mat[row][col];
                    mat[row][col] = mat[row - 1][col - 1];
                    mat[row - 1][col - 1] = tmp;
                }
            }
        }
    }
    
    // in-place
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row, col;
        // for the first row
        for(row = 0, col = 0;col < mat[0].size();col++)
            diagonalBubbleSort(mat, row, col);
        
        // for the first column
        for(row = 1, col = 0;row < mat.size();row++)
            diagonalBubbleSort(mat, row, col);
        
        return mat;
    }
};

//Map solution
unordered_map<int, vector<int>> mp;
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            mp[i-j].push_back(mat[i][j]);
        }
    }
    
    for(int k=-(n-1);k<m;k++) {
        sort(mp[k].begin(),mp[k].end());
    }
    
    for(int i=m-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            mat[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
    return mat;
}

//
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rows = mat.size() ;
        int cols = mat[0].size() ;
        
        int i , j , k ;
        
        for( int idx = cols-1 ; idx>=0 ; idx-- ){
            vector<int> dummy ;
            int i = 0 ;
            int j = idx ;
            
            while(i<rows && j<cols){
                dummy.push_back(mat[i][j]) ;
                i++ ;
                j++ ;
            }
            
            sort(dummy.begin(),dummy.end()) ;
            i = 0 ;
            j = idx ;
            k = 0 ;
            while(i<rows && j<cols){
                mat[i][j] = dummy[k] ;
                i++ ;
                j++ ;
                k++ ;
            }
            dummy.clear() ;
        }
        
        for( int idx = 1 ; idx<rows ; idx++ ){
            vector<int> dummy ;
            i = idx ;
            j = 0 ;
            
            while(i<rows && j<cols){
                dummy.push_back(mat[i][j]) ;
                i++ ;
                j++ ;
            }
            
            sort(dummy.begin(),dummy.end()) ;
            i = idx ;
            j = 0 ;
            k = 0 ;
            while(i<rows && j<cols){
                mat[i][j] = dummy[k] ;
                i++ ;
                j++ ;
                k++ ;
            }
            dummy.clear() ;
        }
        return mat ;
        
    }
};

//
class Solution {
private:
    // We want singleIteration to contain all the in diagnal order.
	// For example, if we start at mat[0][0] in the main function below, we collect mat[1][1], mat[2][2] etc.
    void extractNumber(const vector<vector<int>>& mat, int x, int y, int boundaryX, int boundaryY, vector<int>& singleIteration)
    {
        if (x >= boundaryX || y >= boundaryY || x < 0 || y < 0) return; 
        
        singleIteration.push_back(mat[x][y]);
        extractNumber(mat, x + 1, y + 1, boundaryX, boundaryY, singleIteration);
        return;
    }  
    
	// Replace the original matrix numbers with the sorted diagonal numbers
	// held in the vector sortedRows.
    void reconstructVector(vector<vector<int>>& originalMatrix, const vector<int>& sortedRows, 
                           int x, int y, int boundaryX, int boundaryY, int index)
    {
        if (x >= boundaryX || y >= boundaryY || x < 0 || y < 0) return; 
        
        originalMatrix[x][y] = sortedRows[index];
		// The next diagonal number in originalMatrix, if it exists, will be filled with the next index
		// in sortedRows.
        reconstructVector(originalMatrix, sortedRows, x + 1, y + 1, boundaryX, boundaryY, index + 1);
        return;
    }
    
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        if (mat.empty()) return {};
        
        int startingX = mat.size() - 1, startingY = 0;
        vector<vector<int>> sortedRows(mat.size(), vector<int>(mat[0].size(), 0));
        vector<int> singleIteration;
        
        // Move alongside the edges. From the bottom left to the top
        for (int i{startingX}; i >= 0; --i)
        {
            extractNumber(mat, i, 0, mat.size(), mat[0].size(), singleIteration);
            sort(singleIteration.begin(), singleIteration.end());
            sortedRows.push_back(singleIteration);
            singleIteration.clear();
        }
        // Now move from the cell to the right of the top left to the most rightward
		// edge cell
        for (int i{1}; i < mat[0].size(); ++i)
        {
            extractNumber(mat, 0, i, mat.size(), mat[0].size(), singleIteration);
            sort(singleIteration.begin(), singleIteration.end());
            sortedRows.push_back(singleIteration);
            singleIteration.clear();
        }
        // Work our way backwards to edit the original vector, from the rightwards
		// top edge to 1 cell to the right of cell  [0][0]
        for (int i{mat[0].size() - 1}; i > 0; --i)
        {
            reconstructVector(mat, sortedRows.back(), 0, i, mat.size(), mat[0].size(), 0);      
            // This respective diagonal of the matrix is now sorted, we can get rid
			// of the sorted order held in sortedRows.
			sortedRows.pop_back();
        }
        // Starting at cell 0,0 move down one.
        for (int i{}; i < mat.size() - 1; ++i)
        {
            reconstructVector(mat, sortedRows.back(), i, 0, mat.size(), mat[0].size(), 0); 
            sortedRows.pop_back();
        }
		
        return mat;
    }
};