#include<stdio.h>
int search(int *p,int low,int high,int key)   
{ 
    int f,m;
    m=(low+high)/2;
    if(low>high)
        f=-1;
    else if(p[m]==key)
        f=m;
    else if(p[m]>key)
        f= search(p, low, m-1, key);
    else
        f= search(p, m+1, high, key);
    return f;
}
int main()
{
    int a[6]={8,12,16,59,35,29};
    int i, p, m;
    for(i=0; i<2; i++){
        printf("input m:");
        scanf("%d", &m); //ÊäÈë13»ò35
        p= search(a, 0, 5, m);
        if(p>=0)
            printf("found:  %d = a[%d]\n", m, p);
        else
            printf("no found:  %d \n", m);
    }
    return 0;
}

