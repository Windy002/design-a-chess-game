#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//��ֹɨ���ʱ��û�п�����������������ǰ��
void Initboard(char board[ROW][COL],int row,int col);
void Displayboard(char board[ROW][COL],int row,int col);
void Playermove(char board[ROW][COL],int row ,int col);
void Computermove(char board[ROW][COL],int row,int col);
char Iswin(char board[ROW][COL],int row,int col);
// ISwin function �ܸ���������Ϸ������״̬
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
  	// ���顪������߳���������Ϣ 
  	char board[ROW][COL]={0}; // all is zero
  	//��ʼ������  initialize the palyboard
	Initboard(board,ROW,COL);
  	/* ��ӡ����  print playboard                   |   |   
  	 											---|---|---
												   |   |   
												---|---|---
												   |   |     */  
  	Displayboard(board,ROW,COL);
  	// Play ����
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
		ret=Iswin(board,ROW,COL); //[Error] too few arguments to function 'Iswin' ���󣺺����Ĳ���ûдȫ
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

		//1. data ��ӡ������ 
        for(j=0;j<col;j++)
         {
        	printf(" %c ",board[i][j]);
        	if(j<col-1)
			   printf("|");   
	   	 }
	   	
	   	 printf("\n");
	
		//2. dividing line ��ӡ�ָ��� 
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
	scanf("%d%d",&x,&y);  // �����ǵ������߼�����ƣ���һ�е�һ��Ԫ���±꣨1��1�� �������ǣ�0��0�� 
	  // �ж�����ĺ�����
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
	x=rand()%row; // %row �Ժ�ֻ�ܳ���0��1����row-1  
	y=rand()%col; // ���Բ��õ��ķǷ������� �����һ��     	
       if(board[x][y]==' ') 
          {
          	board[x][y]='#'; //ռ���˿��Բ���else���õ���ѭ�����Ϸ�����Ϊֹ���� 
          	break; 
		  }
     }
}


// return 1:��������  return 0������û��
int Isfull(char board[ROW][COL],int row,int col) 
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	  {
		 for(j=0;j<col;j++)
		 {
		    if(board[i][j]==' ') // ɨ�����е�Ԫ�أ�ֻҪ��' '��û�� scan all element,exist 0 then it's ont full 
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
	srand(time(NULL)); // �������ֵ����ʱ���Ҫ��ͷ�ļ� <time.h> and <stdlib.h> 
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
