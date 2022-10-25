#include<iostream>
#include<string>
#include<vector>
/*
BOJ1018 problem , algorithm : brute force
체스판 다시 칠하기 문제
*/
using namespace std;

inline int min(int a, int b)
{
    return a <= b ? a : b;
}
//체스보드
class chessBoard
{
    public :
    chessBoard(int col, int row)
        {
            vector<string> v;
            string s;
            m_rowLength = row; m_colLength = col;
            m_posX = 0; m_posY = 0;
            for(int i = 0  ; i < m_colLength ; i++)
            {
                cin >> s;
                v.push_back(s);
            }
            chessBoardColor = v;
        }
    int findMinThatHaveToChange();

    private :
        vector<string> chessBoardColor;
        int m_rowLength; int m_colLength; // 보드의 x,y 길이
        int m_posX, m_posY;// 검수중인 x,y좌표
        int countToChangeBoard(int col , int row); // 바꿔야 하는 보드의 수를 샌다.
        bool isInside(size_t col, size_t row); // 검수중인 좌표가 올바른지
        bool isRightBoardColor(size_t posY, size_t posX, size_t xCounter , size_t yCounter); // 올바른 색인지 판단

};

bool chessBoard::isInside(size_t col, size_t row)
{//체스보드 안이면 TRUE 나머진 FLASE
    return (0 <= col && col < m_colLength) && (0 <= row && row < m_rowLength) ? true : false;
}
bool chessBoard::isRightBoardColor(size_t posY, size_t posX, size_t yCounter, size_t xCounter)
{// 1. m_posX m_posY 좌표의 상하좌우와 색이 달라야함. 2. 좌표가 isInside == false 면 넘긴다
// 동시에 색이 달라야 한다
    if(isInside(posY + 1 , posX) && yCounter != 9)
    {
        if(chessBoardColor[m_posY][m_posX] == chessBoardColor[posY + 1][posX])
            return false;
    } 
    if(isInside(posY - 1 , posX) && yCounter != 0)
    {
        if(chessBoardColor[m_posY][m_posX] == chessBoardColor[posY - 1][posX])
            return false;
    } 
    if(isInside(posY , posX + 1) && xCounter != 9)
    {
        if(chessBoardColor[m_posY][m_posX] == chessBoardColor[posY][posX+1])
            return false;
    } if(isInside(posY , posX - 1) && xCounter != 0)
    {
        if(chessBoardColor[m_posY][m_posX] == chessBoardColor[posY][posX-1])
            return false;
    } 
    return true;
}
int chessBoard::countToChangeBoard(int col , int row)
{//체스판 하나를 카운트한다
    cout << "countToChangeBoar(" << col << ", " << row <<")\n";
    int counter = 0; int x = row + 7; int y = col + 7;
    if( isInside( col, row + 7 ) && isInside( col + 7 , row) )
    { //체스판 크기가 맞아야 한다
        int xCounter = 0; int yCounter = 0;
        while(y > col)
        {
            while(x > row)
            {
                if( !isRightBoardColor(col,row,xCounter,yCounter) )
                { // 체스판 색을 바꿔야 한다면
                    cout << "false (" << col << ", " << row << ")\n";
                    counter = counter + 1;
                    if(xCounter == 9)
                    {
                        xCounter = 0;
                        yCounter++;
                    }
                    else
                        xCounter++;
                }   
                else
                {
                    if(xCounter == 9)
                    {
                        xCounter = 0;
                        yCounter++;
                    }
                    else
                        xCounter++;
                }
                x = x - 1;
            }
            y = y - 1;
        }
        return counter;
    }
    else
        return 999999;
}
int chessBoard::findMinThatHaveToChange()
{
    int count = 99999;
    for(m_posY ; m_posY < m_colLength - 7 ; m_posY++)
    {
        for(m_posX = 0 ; m_posX < m_rowLength - 7 ; m_posX++)
        {
            count = min(count,countToChangeBoard(m_posX , m_posY));
        }
    }
    return count;
}
int main(void)
{
    int row, col;
    cin >> col >> row;

    chessBoard chess(col,row);
    cout << chess.findMinThatHaveToChange();

    cin >> row;
    return 0;
}
