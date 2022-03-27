#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//防止扫描的时候没有看到，函数声明放最前面
void Initboard(char board[ROW][COL],int row,int col);
void Displayboard(char board[ROW][COL],int row,int col);
void Playermove(char board[ROW][COL],int row ,int col);
void Computermove(char board[ROW][COL],int row,int col);
char Iswin(char board[ROW][COL],int row,int col);
// ISwin function 能告诉我们游戏的四种状态
// player win  --return '*'; 
// computer win--return '#'; 
// a tie       --return 'A'; 
// continue    --return 'C';   
int Isfull(char board[ROW][COL],int row,int col);
// judge a tie

void menu()
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("******** | 1.Play | 0.Exit | ******\n");
	printf("***********************************\n");
	printf("***********************************\n");
}


// inplementation of gaem's algorithm 
void game()
{
	char ret=0;
  	// 数组——存放走出的棋盘信息 
  	char board[ROW][COL]={0}; // all is zero
  	//初始化棋盘  initialize the palyboard
	Initboard(board,ROW,COL);
  	/* 打印棋盘  print playboard                   |   |   
  	 											---|---|---
												   |   |   
												---|---|---
												   |   |     */  
  	Displayboard(board,ROW,COL);
  	// Play 下棋
	 while(1)
	 {
	 	//player move 
		Playermove(board,ROW,COL);
		Displayboard(board,ROW,COL);
		// judge whether to win or not
		ret=Iswin(board,ROW,COL);
		if(ret!='C')
		  {
		  	break;
	 	  }
		//computer move 
		Computermove(board,ROW,COL);
		Displayboard(board,ROW,COL);
		// judge again
		ret=Iswin(board,ROW,COL); //[Error] too few arguments to function 'Iswin' 错误：函数的参数没写全
		if(ret !='C')
		  {
		  	break;
	 	  }
	  } 
 //when is not 'CT',it will skip to there,so we need to judge whats the situation
       if(ret =='*')
  		{
  	   		printf("Congratulations!YOU WIN!\n");
 		 }
 		else if(ret =='#')
 		 {
  	       printf("Sorry,you Lost!\n");
 		 }
		else  
  		{
  	   		printf("Good!It's a Tie\n");	  
  		}
 } 
 
 
void Initboard(char board[ROW][COL],int row,int col)
{
 	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		 {
			board[i][j]=' '; 
		 }
	}	
 } 


void Displayboard(char board[ROW][COL],int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{

		//1. data 打印数据行 
        for(j=0;j<col;j++)
         {
        	printf(" %c ",board[i][j]);
        	if(j<col-1)
			   printf("|");   
	   	 }
	   	
	   	 printf("\n");
	
		//2. dividing line 打印分割行 
		if(i<row-1)
		{
          for(j=0;j<col;j++)
           {
        	 printf("---");
        	 if(j<col-1)
			    printf("|");   
	   	   }
	    }
	    
        printf("\n"); 
	 } 
		
	
}


void Playermove(char board[ROW][COL],int row ,int col)
{
	int x=0;
	int y=0;
	printf("Player move:>\n");
  while(1)
  {
  	printf("Please enter the coordinate you want to put in:>\n");
	scanf("%d%d",&x,&y);  // 按人们的正常逻辑来设计，第一行第一个元素下标（1，1） 而数组是（0，0） 
	  // 判断坐标的合理性
	if(x>=1&&x<=row && y>=1&&y<=col )
	  {
         if(board[x-1][y-1]==' ')
		   { 
		     board[x-1][y-1]='*';
		     break;
		   }
		 else
		   {
		  	 printf("This coordinate is taken,please enter another:>\n");
		   }	  
	  }
	   
	 else
	   {
	    printf("This coordinate is invalid, please re-enter:>\n");
	   }
  }
	 
}


void Computermove(char board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("Computer move:>\n");

   while(1)
     {
	x=rand()%row; // %row 以后只能出现0、1、…row-1  
	y=rand()%col; // 所以不用担心非法坐标与 坐标减一了     	
       if(board[x][y]==' ') 
          {
          	board[x][y]='#'; //占用了可以不用else，让电脑循环到合法坐标为止即可 
          	break; 
		  }
     }
}


// return 1:棋盘满了  return 0：棋盘没满
int Isfull(char board[ROW][COL],int row,int col) 
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	  {
		 for(j=0;j<col;j++)
		 {
		    if(board[i][j]==' ') // 扫描所有的元素，只要有' '就没满 scan all element,exist 0 then it's ont full 
             return 0; // is not full 		 	
		 }
		   
	  }
	 return 1; // is full 
}


char Iswin(char board[ROW][COL],int row,int col)
{
	int i=0;
	// judge three elemet in the row form a line
	for(i=0;i<row;i++)
	  {
		if(board[i][0]==board[i][1]&& board[i][1]==board[i][2]&& board[i][1]!=' ')
		 return board[i][1];
	  }
	// judge three elemet in the column form a line
	for(i=0;i<col;i++)
	  {
	    if(board[0][i]==board[1][i]&& board[1][i]==board[2][i]&& board[1][i]!=' ')
	     return board[1][i];
	  }
    //judge the three elemet on two diagonal line form a line
	    if(board[0][0]==board[1][1]&& board[1][1]==board[2][2]&& board[1][1]!=' ')
	      return board[1][0];
	    if(board[2][0]==board[1][1]&& board[1][1]==board[0][2]&& board[1][1]!=' ')
	      return board[1][1];
	// judge a tie
	if(1==Isfull(board,ROW,COL))
	  {
		return 'A';
	  }
	 else 
	    return 'C';

}



void test()
{
	int input=0;
	srand(time(NULL)); // 设置随机值，用时间戳要引头文件 <time.h> and <stdlib.h> 
	do
	{
		menu();
		printf("Please choose:>\n");
		scanf("%d",&input);
		
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("Exit!\n");
				break;
			default:
				printf("Input error\n");
				break;				
		}
		
	}while(input);
}


int main()
{
	test();
	return 0;
 } 
