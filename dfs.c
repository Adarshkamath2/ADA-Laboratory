#include<stdio.h>
#include<stdlib.h>

int a[10][10],visited[10],con,cyc,count,connected[10],cyclic[10];
int cycle = 0,bop = 0;

void dfs(int p,int V)
{
	count += 1;
	visited[p] = count;
	connected[con++] = p+1;
	for(int w = 0;w<V;w++)
	{
		if(a[V][w] == 1 && visited[w] == 1 && (visited[p]-visited[w]!= 1))
		{
			cycle++;
		}
		bop++;
		if(a[p][w] == 1)
		{
			if(visited[w] == 0)
			{
				dfs(w,V);
			}
		}
	}
}

void DFS(int n)
{
	int flag;
	for(int i = 0;i<n;i++)
	{
		flag = 1;
		if(visited[i] == 0)
		{
			con = 0;
			dfs(i,n);
			flag = 0;
		}
		if(con<n && flag == 0)
		{
			printf("Graph is Disconnected anf the Connected Components are : \n");
			for(int j = 0;j<con;j++)
				printf("%d",connected[j]);
			printf("\n");
		}
	}
}

int main()
{
	int n,i,j;
	printf("Enter Number of vertices : ");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix : \n");
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i = 0;i<n;i++)
		visited[i] = 0;
	DFS(n);
	printf("The Order in which the vertices are \n");
	for(i = 0;i<n;i++)
		printf("vertex %d is visited -%d\n",i+1,visited[i]);
	printf("count : %d\n",bop);
	if(cycle>0)
		printf("Cycle Exists \n");
	return 0;
	
}
