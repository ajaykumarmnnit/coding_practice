#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define W 0
#define G 1
#define R 2
#define B 3
#define O 4
#define Y 5

char color[6]={'W','G','R','B','O','Y'};
int cube[6][3][3];
int correct_cube[6][3][3]= { { {  0, 10, 20},{100,110,120},{200,210,220} },
			     { {  1, 11, 21},{101,111,121},{201,211,221} },
			     { {  2, 12, 22},{102,112,122},{202,212,222} },
			     { {  3, 13, 23},{103,113,123},{203,213,223} },
			     { {  4, 14, 24},{104,114,124},{204,214,224} },
			     { {  5, 15, 25},{105,115,125},{205,215,225} }
			   };
int search_index(char c)
{
	switch(c)
	{
		case 'W': return 0;
		case 'G': return 1;
		case 'R': return 2;
		case 'B': return 3;
		case 'O': return 4;
		case 'Y': return 5;
		default: return -1;
	}
}
int set_index(char c)
{
	c = toupper(c);
	return search_index(c);
}
void print_color(char c)
{
	switch(c)
	{
		case 'W': printf("\033[0;37m¤");break;
		case 'G': printf("\033[1;32m¤");break;
		case 'R': printf("\033[1;31m¤");break;
		case 'B': printf("\033[1;34m¤");break;
		case 'O': printf("\033[1;35m¤");break;
		case 'Y': printf("\033[1;33m¤");break;
	}
	printf("\e[0m");
}
int print_cube(int rcube[6][3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("    ");
		for(j=0;j<3;j++)
		{
			print_color(color[rcube[0][i][j]%10]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<12;j++)
		{
			if(j%3==0 && j!=0)
				printf(" ");
			print_color(color[rcube[j/3 +1][i][j%3]%10]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		printf("    ");
		for(j=0;j<3;j++)
		{
			print_color(color[rcube[5][i][j]%10]);
		}
		printf("\n");
	}
	printf("\n");
}

int find_connected_two(int rcube[6][3][3],int cube_no,int row,int col)
{
	if( cube_no==0)
	{
		if(row==0 && col==1)
			return rcube[4][0][1]%10;
		if(row==1 && col==0)
			return rcube[1][0][1]%10;
		if(row==1 && col==2)
			return rcube[3][0][1]%10;
		if(row==2 && col==1)
			return rcube[2][0][1]%10;
	}
	if( cube_no==1)
	{
		if(row==0 && col==1)
			return rcube[0][1][0]%10;
		if(row==1 && col==0)
			return rcube[4][1][2]%10;
		if(row==1 && col==2)
			return rcube[2][1][0]%10;
		if(row==2 && col==1)
			return rcube[5][1][0]%10;
	}
	if( cube_no==2)
	{
		if(row==0 && col==1)
			return rcube[0][2][1]%10;
		if(row==1 && col==0)
			return rcube[1][1][2]%10;
		if(row==1 && col==2)
			return rcube[3][1][0]%10;
		if(row==2 && col==1)
			return rcube[5][0][1]%10;
	}
	if( cube_no==3)
	{
		if(row==0 && col==1)
			return rcube[0][1][2]%10;
		if(row==1 && col==0)
			return rcube[2][1][2]%10;
		if(row==1 && col==2)
			return rcube[4][1][0]%10;
		if(row==2 && col==1)
			return rcube[5][1][2]%10;
	}
	if( cube_no==4)
	{
		if(row==0 && col==1)
			return rcube[0][0][1]%10;
		if(row==1 && col==0)
			return rcube[3][1][2]%10;
		if(row==1 && col==2)
			return rcube[1][1][0]%10;
		if(row==2 && col==1)
			return rcube[5][2][1]%10;
	}
	if( cube_no==5)
	{
		if(row==0 && col==1)
			return rcube[2][2][1]%10;
		if(row==1 && col==0)
			return rcube[1][2][1]%10;
		if(row==1 && col==2)
			return rcube[3][2][1]%10;
		if(row==2 && col==1)
			return rcube[4][2][1]%10;
	}
}
void first_step()
{
	int i,j,k,find=0;
	for(i=0;i<6 && !find;i++)
	{
		for(j=0;j<3 && !find;j++)
		{
			for(k=0;k<3 && !find;k++)
			{
				if(cube[i][j][k]==5 && find_connected_two(cube,i,j,k)==1)
				{
					find=1;
				}
			}
		}
				
	}
	zi=i,zj=j;zk=k;	
	
	for(i=0;i<6 && !find;i++)
	{
		for(j=0;j<3 && !find;j++)
		{
			for(k=0;k<3 && !find;k++)
			{
				if(cube[i][j][k]==5 && find_connected_two(cube,i,j,k)==1)
				{
					find=1;
				}
			}
		}
				
	}

}
int main()
{
	int i,j,k;
	char c;
	printf("Hold cube as told and input the colors of each face\n");

	for(i=0;i<6;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				scanf("%c ",&c);
				cube[i][j][k]=set_index(c);
			}
		}
				
	}
	print_cube(cube);
	print_cube(correct_cube);
	//Solve
	first_step();



	return 0;
}





