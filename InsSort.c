#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define x 10
#define y 100

int isort(int *b,int h)
{
	int v,j,count = 0;
	for(int i=1;i<h;i++)
	{
		v = b[i];
		j = i-1;
		count++;
		while(j>=0 && b[j] > v)
		{
			count++;
			b[j+1] = b[j];
			j = j-1;
		}
		if(j<0) count--;
		b[j+1] = v;
	}
	printf("Sorted..");
	if(h<21)
	{
	for(int i = 0;i<h;i++)
	{
		printf("%d\t",b[i]);
	}
	}
	return count;
}

void analysis(int ch)
{
	int *w,*b,count;
	FILE *fp1;
	srand(time(NULL));
	for(int h =x;h<=y;h+=10)
	{
		count = 0;
		w = (int*)malloc(h*sizeof(int));
		b = (int*)malloc(h*sizeof(int));
		for(int i = 0;i<h;i++)
		{
			w[i] = h-i;
			b[i] = i;
		}
		switch(ch)
		{
			case 1: count = isort(b,h);
					fp1 = fopen("InsSortBest.txt","a");
					fprintf(fp1,"%d\t%d\n",h,count);
					fclose(fp1);
					break;
			case 2: count = isort(w,h);
					fp1 = fopen("InsSortWorst.txt","a");
					fprintf(fp1,"%d\t%d\n",h,count);
					fclose(fp1);
					break;		
		}
		free(b);
		free(w);
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("Enter Choice \n");
		printf("1.Best\n2.Worst\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			case 2: analysis(ch);break;
			default : exit(0);
		}
	}
	return 0;
}
