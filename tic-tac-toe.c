#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void menu();
void game();
void test();
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下
char IsWin(char board[ROW][COL], int row, int col);//判断是否赢
int IsFull(char board[ROW][COL], int row, int col);//判断棋盘是否下满

void menu()
{
    printf("*****************************************\n");
    printf("*******  1.play            0.exit *******\n");
    printf("*****************************************\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            board[i][j] = ' ';
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0; 
    for(i = 0; i < row; i++)
    {
        //1.打印列
        int j = 0;
        for(j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col - 1)
                printf("|");
        }
        printf("\n");
        //2.打印分割行
        if(i < row - 1)
        {
            for(j = 0; j < col; j++)
            {
                printf("---");
                if(j < col - 1)
                    printf("|");
            }
            printf("\n");
        }

    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家下:\n");
    printf("请输入要下的坐标:>");
    while(1)
    {
        scanf("%d %d", &x, &y);
        //判断坐标是否合法
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }    
            else
                printf("此坐标被占用\n");
        }
        else
            printf("输入坐标错误，请重新输入");
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("电脑下:\n");

    while(1)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        } 
    }
}

//四种游戏状态-玩家赢'*' 电脑赢'#'平局'Q'继续'C'
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //判断三行
    for(i = 0; i < row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
            return board[i][0];
    }
    //判断三列
    for(i = 0; i < col; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[0][i];
    }
    //判断主对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[0][0];
    //判断反对角线
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return board[2][0];
    //判断是否平局
    if(1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
        return 'C';
}

//判断棋盘是否下满，0没满，1满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
                return 0;//没满
        }
    }
    return 1;//满了
}
//游戏的实现
void game()
{
    char ret = 0;
    //数组-存放走出的信息
    char board[ROW][COL] = { 0 };
    //初始化棋盘
    InitBoard(board, ROW, COL);
    //打印棋盘信息
    DisplayBoard(board, ROW, COL);
    //整个游戏实现的算法
    while(1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断玩家是否赢
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
        //电脑下
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断电脑是否赢
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
    }
    if(ret == '*')
        printf("玩家赢!\n");
    else if(ret == '#')
        printf("电脑赢!\n");
    else
        printf("平局!\n");
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请输入：>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择！\n");
                break;
        }
    }while(input);
    
}
int main()
{
    test();
    return 0;
}