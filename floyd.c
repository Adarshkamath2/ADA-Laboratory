//Floyds

#include<stdio.h>
#include<stdlib.h>

int G[40][40],n,count = 0;

void CreateGraph()
{
	printf("No. of Vertices >> ");
	scanf("%d",&n);
	printf("Enter Adjaceny Matrix : \n");
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}	
}

void main()
{
	int T;
	CreateGraph();
	for(int k = 0;k<n;k++)
	{
		for(int i = 0;i<n;i++)
		{
			T = G[i][k];
			for(int j = 0;j<n;j++)
			{
				count++;
				if(G[i][j] > T)
				//G[i][j] = (G[i][j] | (G[i][k] & G[k][j]));
					if(G[i][k] + G[k][j] < G[i][j])
						G[i][j] = G[i][k] + G[k][j];
			}
		}
	}
	
	printf("Applying Warshalls algorithm.....\n");
	printf("\n\nTransitivr Closure Matrix : \n");
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			printf("%d",G[i][j]);
		}
		printf("\n");
	}
	
	printf("Operation Count : %d\n",count);
	
}
