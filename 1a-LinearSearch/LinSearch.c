//Source Code
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int n =0;
int Search(int*,int,int);

void main()
{
	clock_t et,st;
	double ts,tst;
	FILE *fp,*f;
	fp = fopen("LinData.txt","a");
	f = fopen("size.txt","a");
	int *a,s,search;
	printf("SIZE : ");
	scanf("%d",&n);
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
		st = clock();
		search = Search(a,s,n);
		et = clock();
		ts = (double)(et-st);
		tst = (double)ts/CLOCKS_PER_SEC;
		printf("Clock : %f\nClocks Per Cycle : %f\n\n",ts,tst);
		fprintf(f,"%d\t%fms\n",n,ts);
		free(a);
	}
	fclose(fp);
	fclose(f);
	//system("gnuplot>load 'cmd.txt'");
}

int Search(int *a,int s,int n)
{
	int i = 0;
	for(i = 0;i<n;i++)
	{	
		if(*(a+i)== s)
		{	
			printf("Count : %d\n",i+1);
			return i+1;
		}
	}
	printf("Count : %d\n",i);
	return -1;	
}
