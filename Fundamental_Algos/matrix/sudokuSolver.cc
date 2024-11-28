#include"includes.hpp"

bool isRowValid(std::vector<std::vector<std::string>>& board)
{
    for(int row=0;row<9;row++)
    {

        for(int col=0;col<9;col++)
        {
            std::string a =board[row][col];
            
        } 
    }
}

bool isColvalid(std::vector<std::vector<std::string>>& board)
{
    for(int row=0;row<9;row++)
    {
        
        for(int col=0;col<9;col++)
        {

        } 
    }
}

bool isCubeValid(std::vector<std::vector<std::string>>& board)
{
    for(int cube=0;cube<9;cube++)
    {
        
        for(int col=0;col<3;col++)
        {
            for(int row=0;row<3;row++)
            {
                board[col*(cube+1)][row*(cube+1)];
            } 

        } 
    }

}

bool isValidSudoku(std::vector<std::vector<std::string>>& board) 
{
    return  ((isRowValid(board) and isColvalid(board) and isCubeValid(board))==true) ? true : false;  
}


int main()
{
    std::vector<std::vector<std::string>> board= { {"6",".",".","1","9","5",".",".","."}
    ,{"5","3",".",".","7",".",".",".","."}
    ,{".","9","8",".",".",".",".","6","."}
    ,{"8",".",".",".","6",".",".",".","3"}
    ,{"4",".",".","8",".","3",".",".","1"}
    ,{"7",".",".",".","2",".",".",".","6"}
    ,{".","6",".",".",".",".","2","8","."}
    ,{".",".",".","4","1","9",".",".","5"}
    ,{".",".",".",".","8",".",".","7","9"}
    };

    std::cout<<isValidSudoku(board);
}