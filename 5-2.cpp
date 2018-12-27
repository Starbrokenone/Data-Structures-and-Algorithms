#include<stdio.h>
#include<malloc.h>
void sort(int *a, int n)
{
    int i=0;
    int j=n-1;
    int t;
    while(i<=j)
    {
        while(i<n&&a[i]>=0)
        {
            i++;
        }
        while(j>=0&&a[j]<0)
        {
            j--;
        }
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
}
int main()
{
       int n,i;
       int* p;
       printf("Please input n:\n");
       scanf("%d",&n);
       while(n<2)
{
              printf("The numerical you input is not reasonable, please input again£º\n");
              scanf("%d", &n);
       }
       p=(int*)malloc(n*sizeof(int));
       printf("Please input array:\n");
       for(i=0;i<n; i++)
{
              scanf("%d", &p[i]);
       }
       sort(p,n);
       printf("Adjusted array:\n");
       for(i=0;i<n;i++)
{
              printf("%-4d",p[i]);
       }
       printf("\n");
}

