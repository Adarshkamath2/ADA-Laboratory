//String Matching aslgorithm Naivestring
#include<stdio.h>
#include<stdlib.h>

int StringMatching(char *T,char *p,int n,int m)
{
	int j,count = 0;
	for(int i = 0;i<= n-m;i++)
	{
		j = 0;
		while(j<m && *(p+j)==*(T+i+j))
		{
			count++;
			j++;
		}
		if(j==m) return count;
	}
	return count;
}

int main()
{
	FILE *fp1 = fopen("StringBest.txt","a");
	FILE *fp2 = fopen("StringWorst.txt","a");
	int count = 0,i;
	char *T = (char*)malloc(sizeof(char)*1000);
	for(int i =0;i<1000;i++)
	{
		*(T+i) = 'a';
	}
	for(int m = 10;m<= 1000;m=(m<100)?m*10:m+100)
	{
		count = 0;
		char *p = (char*)malloc(sizeof(char)*m);
		for (int i =0;i<m;i++)
			*(p+i) = 'a';
		count = StringMatching(T,p,1000,m);
		fprintf(fp1,"%d\t%d\n",m,count);
		*(p+m-1) = 'b';
		count = 0;
		count = StringMatching(T,p,1000,m);
		fprintf(fp2,"%d\t%d\n",m,count);
		free(p);
	}
	fclose(fp2);
	fclose(fp1);
}
