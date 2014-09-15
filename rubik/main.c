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
int print_cube()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("   ");
		for(j=0;j<3;j++)
			printf("%c",color[cube[0][i][j]]);
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<12;j++)
			printf("%c",color[cube[j/3 +1][i][j%3]]);
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		printf("   ");
		for(j=0;j<3;j++)
			printf("%c",color[cube[5][i][j]]);
		printf("\n");
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
	print_cube();


	return 0;
}





