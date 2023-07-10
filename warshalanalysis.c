//Warshal.c

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int G[40][40],w[40][40],count = 0;

void CreateGraph(int n)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			G[i][j] = rand()%2;
			w[i][j] = 1;
		}
	}	
}

void main()
{
srand(time(NULL));
	FILE *a;
a = fopen("WarshalData.txt","a");

	for(int h = 3;h<= 10;h++)
	{
	count = 0;
	CreateGraph(h);
	for(int k = 0;k<h;k++)
	{
		for(int i = 0;i<h;i++)
		{
			if(G[i][k])
			for(int j = 0;j<h;j++)
			{
				count++;
				if(G[k][j])
					G[i][j] = 1;
			}
		}
	}
	printf("Operation Count : %d\n",count);
	fprintf(a,"%d\t%d\n",h,count);
}
	fclose(a);
	
}
