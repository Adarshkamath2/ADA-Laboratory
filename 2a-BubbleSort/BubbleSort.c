//Bubble Sort Source Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int n =0;
void Sort(int*,int);

void main()
{
	clock_t et,st;
	double ts,tst;
	FILE *fp,*f;
	fp = fopen("BubData.txt","a");
	f = fopen("BubTime.txt","a");
	int *a;
	srand(time(NULL));
  
	for(n = 10;n<= 30000;n = (n<10000 ? n*= 10: n+10000))
	{
		a = (int*)malloc(n * sizeof(int));
		for(int i =0;i<n;i++)
		{	
			*(a+i) = rand()%n;
			fprintf(fp,"%d\t",*(a+i));
		}
    st = clock();
    Sort(a,n);
    et = clock();
    ts = (double)(et-st);
    tst = (double)ts/CLOCKS_PER_SEC;
    
    printf("No of inputs : %d\nClock : %f\nClocks Per Cycle : %f\n\n",n,ts,tst);
    fprintf(f,"%d\t%f\n",n,tst);
    free(a);
	}
	fclose(fp);
	fclose(f);
//system("gnuplot>load 'cmd.txt'");	
}

void Sort(int *a,int n)
{
	int i,j,temp,count =0;
	for(j = 0;j<n-1;j++)
	{ 
	  count = 0;
		for(int i =0;i<n-j-1;i++)
		{
			if(*(a+i)> *(a+i+1))
			{	
				count++;
				temp = *(a+i);
				*(a+i) = *(a+i+1);
				*(a+i+1) = temp;	
			}
		}
		if(count ==0)
		break;
	}		
}
