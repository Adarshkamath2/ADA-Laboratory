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
			if(i == j)
				G[i][j] = 0;
			G[i][j] = rand()%100;
			
		}
	}	
}

void main()
{
srand(time(NULL));
	FILE *a;
a = fopen("FloydData.txt","a");
	int T;
	for(int h = 3;h<= 10;h++)
	{
	count = 0;
	CreateGraph(h);
	for(int k = 0;k<h;k++)
	{
		for(int i = 0;i<h;i++)
		{
			T = G[i][k];
			for(int j = 0;j<h;j++)
			{
				//count++;
				if(G[i][j] > T)
				{
					count++;
				//G[i][j] = (G[i][j] | (G[i][k] & G[k][j]));
					if(G[i][k] + G[k][j] < G[i][j])
						G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
	printf("Operation Count : %d\n",count);
	fprintf(a,"%d\t%d\n",h,count);
}
	fclose(a);
	
}
