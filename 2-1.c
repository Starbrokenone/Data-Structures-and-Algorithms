#include<stdio.h>
#include<malloc.h>
 struct node{
	char info;
	struct node *llink,*rlink;
	};
typedef struct node NODE;
NODE *creat(){
	char x;
	NODE *p;
      scanf("%c",&x);
	printf("%c",x);
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
void run(NODE *t){
	if(t){
		run(t->llink);
		run(t->rlink);
	  }
}
int Leaf(NODE *t)
{
    int count;
    if(t==NULL)
        count=0;
    else if(t->llink==NULL&&t->rlink==NULL)
        count=1;
    else
        count=Leaf(t->llink)+Leaf(t->rlink);
    return count;
}

main()
{   int count;
	NODE *T;
	printf("PLease input a tree:\n");
	T=creat();
	printf("\n");
	if(!T)
		printf("This is a empty binary tree.");
	else
	    { count=Leaf(T);
		printf("The number of leaf nodes is:%d\n",count);
		}
       printf("\n");
}

