class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        // Map out each banned word
        // Go through each word, if it isn't in the banned list
        // put it in another map and keep track of how many times it appears
		// Keep two variables to maintain the mostCommonWord and how many times it appeared
			// This prevents us from looping thorugh the map at the end to find the most common word
        
        map<string, int> bannedWords;
        map<string, int> tracker;
        
        string mostCommonWord = "";
        int mostCommonWordCount = 0;
        
        for(int x = 0; x < banned.size(); x++)
        {
            bannedWords[banned[x]] = 0;
        }
        
        for(int x = 0; x < paragraph.length(); x++)
        {
            string temp = "";
            while(x < paragraph.length() && paragraph[x] != ' ')
            {
                if(!isalpha(paragraph[x]))
                {
                    break;
                }
                
                temp += tolower(paragraph[x]);
                x++;
            }

            if(temp == " " || temp == "")
                continue;
            
            if(bannedWords.count(temp) != 0)
                continue;
            else
            {
                tracker[temp]++;
                
                if(mostCommonWordCount < tracker[temp])
                {
                    mostCommonWordCount = tracker[temp];
                    mostCommonWord = temp; 
                }
            }
            
        }
        
        return mostCommonWord; 
    }
};