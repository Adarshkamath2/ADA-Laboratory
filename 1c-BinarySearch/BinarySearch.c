//Source Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int n =0,mid;
int Search(int*,int,int);

void main()
{
	FILE *f1,*f2;
    int b,w;
	f1 = fopen("BinBest.txt","a");
	f2 = fopen("BinWorst.txt","a");
	int *a,search;
	srand(time(NULL));

	for(n = 10;n<= 30000;n = (n<10000 ? n*10: n+10000))
	{
		a = (int*)malloc(n * sizeof(int));
		for(int i =0;i<n;i++)
		{
			*(a+i) = rand()%n;
		}
        
		printf("BEST CASE..");
    	b = *(a+((n-1)/2));
		search = Search(a,b,n);
		fprintf(f1,"%d\t%d\n",n,search);

        printf("Worst Case");
    	w = *(a);
		search = Search(a,*(a),n);
		fprintf(f2,"%d\t%d\n",n,search);
		free(a);
	}
	fclose(f1);
	fclose(f2);
	//system("gnuplot>load 'cmd.txt'");
}

int Search(int *a,int s,int n)
{
    int high = n-1;
    int low = 0;
    int count = 0;
	while(high>low)
	{	
        count++;
        mid = (high+low)/2;
		if(*(a+mid) == s)
		{	
			printf("Count : %d\n",count+1);
			return count;
		}
        else if(*(a+mid)<s)
        {
            low = mid+1;
        }
        else
        high = mid-1;
	}
    return count;	
}
