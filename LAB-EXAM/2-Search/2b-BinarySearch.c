//Binary Search Recursive Analysis

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Search(int,int*,int,int,int);
void analyser(int);

void main()
{
	int i=0;
	for(i=0;i<2;i++)
		analyser(i);
	//system("gnuplot>load 'command.txt'");
}

void analyser(int p)
{
	int *a, n, k, i, o;
	FILE *t;
    if(p==0)
    {
		t=fopen("worst_case_r.txt","w");
		printf("Element not found");
	}
	else
	{
		t=fopen("best_case_r.txt","w");
	}
	srand(time(NULL));

	for(n=100;n<=30000;n=(n<10000?n*10:n+10000))
	{
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			*(a+i)=i+100;
		}
		k=(p==0)?*(a+n-1):*(a+((n-1)/2));
		o=0;
		o=Search(k,a,n-1,0,0);

		if(o!=-1)
		{
			fprintf(t,"%d\t%d\n", n, o);
			printf("\nTime taken is %d\n\n",o);
        }
		else
		printf("Element not found");
		free(a);
	}
	fclose(t);
}

int Search(int key,int *a,int high,int low,int count)
{
    int mid;
  	count++;
  	mid=(high+low)/2;

	if(low>high)return count;
  	if(*(a+mid)==key)
    	 	return count;

  	else if(*(a+mid)>key)
    	return Search(key,a,mid-1,low,count);
  	else
    	return Search(key,a,high,mid+1,count);

}

