//Source Code
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n =0;
int Search(int*,int,int);

void main()
{
	FILE *fp,*f;
	f = fopen("Lin.txt","a");
	int *a,s,search;
	srand(time(NULL));

	for(n = 100;n<= 30000;n = (n<10000 ? n*10: n+10000))
	{
		a = (int*)malloc(n * sizeof(int));
		for(int i =0;i<n;i++)
		{
			*(a+i) = rand()%n;
			fprintf(fp,"%d\t",*(a+i));
		}
		s = -1;
		search = Search(a,s,n);
		fprintf(f,"%d\t%fms\n",n,search);
		free(a);
	}
	fclose(fp);
	fclose(f);
	//system("gnuplot>load 'cmd.txt'");
}

int Search(int *a,int s,int n)
{
	for(int i = 0;i<n;i++)
	{	
		if(*(a+i)== s)	
			return i+1;
	}
	printf("Count : %d\n",i);
	return -1;	
}
