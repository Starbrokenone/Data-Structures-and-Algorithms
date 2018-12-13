#include<stdio.h>
#include<malloc.h>
 struct node{
	char info;
	struct node *llink,*rlink;
	};
char a[100];
int i = 0;
typedef struct node NODE;
NODE *creat(){
	char x;
	NODE *p;
      scanf("%c",&x);
	printf("%c",x);
		a[i++] = x;
		if(x!='.'){
		p=(NODE *)malloc(sizeof(NODE));
		p->info=x;
		p->llink=creat();
		p->rlink=creat();
	 }
	else
		p=NULL;
		return p;
}
main()
{	int b;
	NODE *T;
	printf("PLease input a tree:\n");
	T=creat();
	printf("\n");
	if(!T)
		printf("This is a empty binary tree.");
	else
	    {   printf("输入节点位置");
	        scanf("%d",&b);
	        printf("%c\n",a[b-1]);
	
	        printf("The result is:\n ");
	        for(int j = 0; j < i; j++){
	            printf("%c ",a[j]);
	        }
		}
       printf("\n");
}

