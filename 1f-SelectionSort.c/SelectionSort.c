//Selection Sort source code

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define x 10
#define y 30000

int main()
{
    int *a,count = 0,min,temp,h;
    FILE *fp;
    fp = fopen("Sort.txt","a");
    srand(time(NULL));
    for(h = x;h<=y;h=(h<10000 ? h* 10: h+10000))
    {
        a = (int*)malloc(sizeof(int));
        for(int i =0;i<h;i++)
        {
            *(a+i) = rand()%h;
        }
        for(int i =0;i<h-1;i++)
        {
            min = i;
            for(int j=i+1;j<h;j++)
            {
                count++;
                if(a[j]<a[min])
                    min = j;
            }
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        fprintf(fp,"%d\t%d\n",h,count);
        count = 0;
        free(a);

    }
    fclose(fp);
    return 0;
}
