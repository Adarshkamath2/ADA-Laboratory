
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 30

int Poly(int *p, int n,int x)
{
	int pol = 0;
	int px = 1;
	int count = 0;
	for(int i = n;i>=0;i--)
	{
	px = 1;
	for(int j= 1;j<i;j++)
{
	px = px*x;
	count++;
}		
	pol = pol +*(p+i)*px;
		count++;
	}
	return count;
}

int main()
{
	FILE *fp1 = fopen("PolyQuad.txt","a");
	int count,x;
	srand(time(NULL));
	for(int m = 1;m<= 15;m++)
	{
		count = 0;
		x = 5;
		int *p = (int*)malloc(sizeof(int)*m);
		for (int i =0;i<m;i++)
			*(p+i) = rand()%10;
		count = Poly(p,m,x);
		fprintf(fp1,"%d\t%d\n",m,count);
		free(p);
	}
	fclose(fp1);
}
