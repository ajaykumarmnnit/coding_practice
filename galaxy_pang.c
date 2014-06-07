#include<stdio.h>

int final_max,a[100],get[100],n,k;
void shift_left(int index,int gi);
void shift_right(int index);
int no_match();
int find_max();
void set_max(int get_index);
void print(int j)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("   Items in pick-up array  ");
	for(i=j;i<k;i++)
		printf("%d ",get[i]);
	printf("\n");
}
int main()
{
	int tc,i;
	scanf("%d",&tc);
	while(tc--)
	{
		final_max=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&get[i]);
		}
		
		set_max(0);
		printf("MAX is %d\n",final_max);
	}
}
int no_match()
{
	int i;
	for(i=0;i<n-1;i++)
		if(a[i]==a[i+1])
			return 0;
	return 1;
}
int find_max()
{
	int i,m=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>m)
			m=a[i];
	}
	return m;
}
void set_max(int get_index)
{
	int m,i;
	if(get_index>=k || no_match())
	{
printf("Reached in final condition\n");
print(get_index);
		m=find_max();
		if(m>final_max)
			final_max=m;
		return;
	}
	
	for(i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1])
		{
printf("calling a[%d]=%d get_index=%d\nBefore modifying\n",i,a[i],get_index);
print(get_index);
			a[i]=a[i]+1;
			shift_left(i,get_index);
			//Calling Recursive
			set_max(get_index+1);
			//backtracking to same array
			a[i]=a[i]-1;
			shift_right(i);
		}
	}
}
void shift_left(int index,int gi)
{
	int i;
	for(i=index+1;i<n-1;i++)
		a[i]=a[i+1];
	a[n-1]=get[gi];
}
void shift_right(int index)
{
	int i;
	for(i=n-1;i>index;i--)
		a[i]=a[i-1];
}						


		
