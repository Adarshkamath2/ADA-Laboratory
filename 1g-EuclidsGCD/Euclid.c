//Source code of Euclids,consecutive integer checking method,modified euclid

#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100

float Euclid(int m,int n)
{
    int r;
    float count = 0;
    while(n)
    {
        count ++;
        r = m%n;
        m = n;
        n = r;
    }
    return count;
}

float Consec(int m,int n)
{
    int min;
    float count =0;
    min = m;
    if(n<min)
        min = n;
    while(1)
    {
        count++;
        if(m%min == 0)
        {
            count ++;
            if(n%min == 0)
            {
                break;
            }
            min -= 1;

        }
        else
            min -=1;
    }
    return count;
}

float Modified(int m,int n)
{
    int temp;
    float count = 0;
    while(n>0)
    {
        if(n>m)
        {
            temp = m;
            m = n;
            n = temp;
        }
        m = m-n;
        count += 1;
    
    }
    return count;
}

void Analysis(int ch)
{
    int m,n,i,j,k;
    float count,maxcount,mincount;
    FILE *fp1,*fp2;
    for(i=x;i<=y;i+=10)
    {
        maxcount = 0;
        mincount = 30000;
        for(j = 2;j<=i;j++)
        {
            for(k = 2;k<=i;k++)
            {
                count = 0;
                m = j;
                n = k;
                switch(ch)
                {
                    case 1: count = Euclid(m,n);break;
                    case 2: count = Consec(m,n);break;
                    case 3: count = Modified(m,n);break;
                }
                if(count > maxcount)
                    maxcount = count;
                if(count < mincount)
                    mincount = count;
            }
        }
        switch(ch)
        {
            case 1: fp2 = fopen("Euclid_eb.txt","a");
                    fp1 = fopen("Euclid_ew.txt","a");
                    break;
            case 2: fp2 = fopen("Euclid_cb.txt","a");
                    fp1 = fopen("Euclid_cw.txt","a");
                    break;
            case 3: fp2 = fopen("Euclid_mb.txt","a");
                    fp1 = fopen("Euclid_mw.txt","a");
                    break;
        }
        fprintf(fp2,"%d\t%.2f\n",i,mincount);
        fprintf(fp1,"%d\t%.2f\n",i,maxcount);
        fclose(fp1);
        fclose(fp2);
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n\n-----GCD------\n\n");
        printf("1.Euclid\n2.Consecutive integer check method\n3.Modified\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            case 2:
            case 3: Analysis(ch);break;
            default : exit(1);
        }
    }
    return 0;
}
