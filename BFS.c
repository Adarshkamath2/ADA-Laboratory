#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int v,flag;
}n;


typedef struct queue{
	n items[100];
	int f;
	int r;
}Q;

Q q;
int V[100],cyclic,connected,count;

void dequeue(){
	q.f++;
}

void enqueue(int v)
{
	q.r = (q.r +1);
	q.items[q.r].v = v;
	q.items[q.r].flag = 0;
}

void dfs(int *a[],int v,int n)
{
	count++;
	V[v] = count;
	printf("%d-%d\n",v,count);
	enqueue(v);
	while(q.f<= q.r)
	{
		q.items[q.f].flag = 1;
		for(int i = 0;i<n;i++)
		{
			if(a[q.items[q.f].v][i] == 1)
			{
				if(V[i] == 0)
				{
					count++;
					V[i] = count;
					printf("%d-%d\n",i,count);
					enqueue(i);
				}
				else if(V[v] < V[i])
					cyclic++;

			}
			else if(q.items[q.items[i].v].flag == 0)
				cyclic++;
		}		
	
	dequeue();
	}
}

void BFS(int *a[],int n)
{
	for(int i = 0;i<n;i++)
		V[i] = 0;
	cyclic = 0;
	connected = -1;
	count = 0;
	q.r = -1;
	q.f = 0;
	for(int i = 0;i<n;i++)
		if(V[i] == 0)
		{
			dfs(a,i,n);
			connected++;
		}
		if(cyclic > 0)
			printf("Cyclic\n");
}

int main()
{
	int v;
	q.f = 0;q.r = -1;
	printf("Enter the Number of Vertices \n");
		scanf("%d",&v);
	int *a[v];
	for(int i = 0;i<v;i++)
	{
		a[i] = (int *)malloc(sizeof(int)*v);
		q.items[i].flag = -1;
	}
	printf("Enter the Adjacency Matrix : \n");
	for(int i = 0;i<v;i++)
	{
		for(int j = 0;j<v;j++)
			scanf("%d",&a[i][j]);
	}
	BFS(a,v);
}



