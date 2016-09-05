/*  74. Search a 2D Matrix  

    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return 0;
        
        int colsize= matrix[0].size();
        int startrow=0, endrow= matrix.size()-1, col= colsize-1, foundrow=0;
        
        while(startrow <= endrow){              //first find the row
        
            int midrow= startrow + (endrow-startrow)/2;
            
            if(matrix[midrow][col] == target)
                return 1;
                
            else if(matrix[midrow][col] > target){
                foundrow= midrow;
                endrow = midrow-1;
            }
            
            else startrow= midrow+1;
        }
        
        int startcol=0, endcol= colsize-1;
        
        while(startcol <= endcol){              //now find the column in that row
            
            int midcol= startcol + (endcol-startcol)/2;
            
            if(matrix[foundrow][midcol]==target)
                return 1;
                
            else if(matrix[foundrow][midcol] < target)
                startcol= midcol+1;
                
            else endcol= midcol-1;
        }
        return 0;
    }
};