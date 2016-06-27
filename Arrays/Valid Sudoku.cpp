/*  Leetcode -36 Valid Sudoku
    Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
    The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
    A partially filled sudoku which is valid.
    Note:
    A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for duplicate in row
        for(int i=0; i< board.size(); i++){
            if(hasDuplicate(board,i,i+1,0, board.size()))
                return false;
        }
        //check for duplicate in column
        for(int j=0; j < board.size(); j++){
            if(hasDuplicate(board,0,board.size(),j,j+1))
                return false;
        }
        //check for duplicate in grid
        int grid= sqrt(board.size());
    
        for(int i=0; i < grid; i++){
            for(int j=0; j< grid; j++){
                if(hasDuplicate(board,grid*i,grid*(i+1),grid*j,grid*(j+1))){
                    return false;
                }
            }
        }
       return true; 
    }
    
    
    
    bool hasDuplicate(vector<vector<char>>& board, int rowstart, int rowend, int colstart, int colend){
        vector<bool> present(board.size()+1, false);
        for(int i= rowstart; i < rowend; i++){
            for(int j=colstart; j< colend; j++){
                if(board[i][j] != '.'&& present[board[i][j]])
                    return true;
                present[board[i][j]]= true;
            }
        }
        return false;
    }
};