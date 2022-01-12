/* The board contains non zero and zero values.
Non zero values lie in the range: [1, 9].
Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
*/
#include<bits/stdc++.h>
#include<utility>
using namespace std;
int board[9][9];
int* l=new int[2];
class Pair
{
    public:
    int row;
    int col;

};

int FindEmptyrow()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                return i;
            }
        }
    }

    //Pair ans;
    return -1;

}
int FindEmptycol()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                return j;
            }
        }
    }

    //Pair ans;
    return -1;

}

bool SudokuSolved()
{
    int row=FindEmptyrow();
    int col=FindEmptycol();
    
   
    if(row==-1)
    {
        return true;
        
    }
    //cout<<row<<" "<<col<<endl;

    for(int k=1;k<10;k++)
    {
        int flagrow=0,flagcol=0,flagbox=0;
        for(int j=0;j<9;j++)
        {
            if(board[row][j]==k)
            {
                flagrow=1;
                //break;
            }
        }
        if(flagrow==1)
        {
            continue;
        }
        
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==k)
            {
                flagcol=1;
               // break;
            }
        }
        if(flagcol==1)
        {
            continue;
        }

        int x,y;
        if(row>2 && row<6)
        {
            x=3;
        }
        if(col>2 && col<6)
        {
            y=3;
        }

        if(row<=2 )
        {
            x=0;
        }
        if(col<=2 )
        {
            y=0;
        }

        if(row>=6 )
        {
            x=6;
        }
        if(col>=6 )
        {
            y=6;
        }
        

     
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j]==k)
                {
                    flagbox=1;
                }
            }
         
        }
        if(flagbox==1)
        {
            continue;
        }

        //cout<<"ddddd"<<k<<endl;
        board[row][col]=k;
        bool isSolved=SudokuSolved();
        if(isSolved==true)
        {
            return true;
        }
        board[row][col]=0;
    }
    return false;

}
int main(){
    
    // write your code here
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>board[i][j];
        }
    }
    
    if(SudokuSolved())
    {
  cout<<"Solved Sudoku: "<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
