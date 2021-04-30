//Given a list of lists of integers, nums, return all elements of nums in diagonal order

//do numbering of the elements and push them into map then traverse the map
class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
       int m=nums.size(),n=nums[0].size();
       
        int numbering=1;
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++)
        {
            int it=numbering;
            for(int j=0;j<nums[i].size();j++)
            {
                mp[it].push_back(nums[i][j]);
                it++;
            }
            numbering++;
        }
       vector<int>ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            for(int i=it->second.size()-1;i>=0;i--)
                ans.push_back(it->second[i]);
        }
        return ans;
    }
};
//
#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxDiagonalId = 0;
        std::unordered_map<int, std::vector<int>> diagonalBuffer;
        for (std::size_t row = 0; row < nums.size(); ++row) {
            for (std::size_t column = 0; column < nums[row].size(); ++column) {
                const int diagonalId = row + column;
                maxDiagonalId = std::max(maxDiagonalId, diagonalId);
                diagonalBuffer[diagonalId].push_back(nums[row][column]);
            }
        }
        std::vector<int> result;
        for (int diagonalId = 0; diagonalId <= maxDiagonalId; ++diagonalId) {
            const auto& buffer = diagonalBuffer[diagonalId];
            for (auto iterator = buffer.rbegin(); iterator != buffer.rend(); ++iterator) {
                result.push_back(*iterator);
            }
        }
        return result;
    }
};