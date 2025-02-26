#include"includes.hpp"

void dfs(int r, int c,vector<vector<char>>& board)
{
    if(r<0 or c<0 or r ==board.size() or c==board[0].size() or board[r][c]!='O') return;
    
    board[r][c]='T';
    dfs(r+1,c,board);
    dfs(r-1,c,board);
    dfs(r,c+1,board);
    dfs(r,c-1,board);
}

void solve(vector<vector<char>>& board) {
    int rows=board.size();
    int col= board[0].size();
    
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(board[r][c]=='O' and ((r==0 or r==rows-1)or(c==0 or c==col-1))) dfs(r,c,board);
        }
    }

    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(board[r][c]=='O') board[r][c]='X';
        }
    }

    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(board[r][c]=='T') board[r][c]='O';
        }
    }
}

int main()
{
    std::vector<std::vector<char>> a={  {'X','X','O','X'},
                                        {'X','O','O','X'},
                                        {'X','X','X','X'},
                                        {'X','O','O','X'}
                                    };
    solve(a);
    std::cout<<a;
}