#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct Graph{
    int v,e;
    int *visited;
    struct node **adj;
};
typedef struct node * NODE;
typedef struct Graph * GRAPH;

int count = 0, iscyclic = 0,i;

NODE CreateNode(int n)
{
    NODE NN = (NODE)malloc(sizeof(struct node));
    NN->info = n;
    NN->next = NULL;
    return NN;
}

GRAPH CreateGraph(int vertices)
{
    GRAPH g = malloc(sizeof(struct Graph));
    g->v = vertices;
    g->adj = malloc(vertices * sizeof(struct node *));
    g->visited = malloc(vertices * sizeof(int));
    int i;
    
    for(i = 0;i<vertices;i++)
    {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

void DFS(GRAPH g,int vertex,int parent)
{
    NODE adj = g->adj[vertex];
    NODE temp = adj;

    count++;
    g->visited[vertex] = 1;
    printf("-->%c",vertex+65);

    while(temp!= NULL)
    {
        int con = temp->info;
        if(g->visited[con] = 1 && con!= parent)
        {
            iscyclic = 1;
        }
        if(g->visited[con]==0)
            DFS(g,con,vertex);

        temp = temp->next;
    }
}

void main()
{
    int n;
    printf("Enter Number of Vertices : \n");
    scanf("%d",&n);
    GRAPH g = CreateGraph(n);
    NODE temp;
    int key;

    printf("Enter The Adjacency List : \n");
    for(int i = 0;i<g->v;i++)
    {
        printf("Enter 1 for the vertices adjacent to vertex %c\n",i+65);
        for(int j = 0;j<g->v;j++)
        {
            l1: printf("\nVertex %c :",g->v-j-1+65);
                scanf("%d",&key);
                if(key == 1)
                {
                    NODE NN = CreateNode(g->v-j-1);
                    NN->next = g->adj[i];
                    g->adj[i] = NN;
                }
                else if(key!=0)
                {
                    printf("Enter 1 to add and 0 to not\n");
                    goto l1;
                }
        }
    }
    printf("\n");

    for(int i = 0;i<g->v;i++)
    {
        temp = g->adj[i];
        printf("The vertex Adjacent to %c : ",i+65);
        while(temp!= NULL)
        {
            printf("%c",temp->info + 65);
            temp = temp->next;
        }
    }

    int dfscount= 0;

    printf("\nDFS Traversal starting from Node %c\n",65);
    DFS(g,0,-1);
    dfscount++;

    if(count == g->v)
    {
        printf("Graph is Connected");
    }
    else
    {
        printf("Graph is not Connected");
        int start = 1;
        while(count != g->v)
        {
            if(g->visited[start] != 1)
            {
                printf("\n");
                DFS(g,start,-1);
                dfscount++;
            }
            start++;
        }
    }
    if(iscyclic == 1)
        printf("The Graph has cycle\n");
    else
        printf("The Graph does not have a cycle\n");
}


