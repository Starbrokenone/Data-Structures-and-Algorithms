#include <stdio.h>
#include <malloc.h>
#include <conio.h>
typedef struct node{
    int a;
    struct node *link;
}node,*nodelink;
void make(nodelink head,int n){
    int i;
    nodelink p,q;
    p=head;
    for(i=0;i<n;i++){
        q=(nodelink)malloc(sizeof(node));
        q->a=i+1;
        p->link=q;
        q->link=head->link;
        p=p->link;
    }
}
void remake(nodelink head,nodelink link,int n,int m,int s){
    int i;
    nodelink p,q,r;
    p=head->link;
    q=p;
    for(i=1;i<s;i++){
        q=p;
        p=p->link;
    }
    if(p==head->link)
        for(i=1;i<n;i++)
            q=q->link;
        r=link;
        do{
            for(i=1;i<m; i++)
            {
                q=p;
                p=p->link;
            }
            q->link=p->link;
            p->link=NULL;
            r->link=p;
            r=r->link;
            p=q->link;
        }while(p!=p->link);
        r->link=p;
        r->link->link=NULL;
}
void write(nodelink link,int n){
    int i;
    nodelink p;
    p=link->link;
    for(i=0; i<n; i++,p=p->link)
        printf("%d ",p->a);
}
void main()
{
    nodelink head,link;
    int m,n,s;
    head=(nodelink)malloc(sizeof(node));      
    link=(nodelink)malloc(sizeof(node));       //�������˳��
    printf("����������n:");
    scanf("%d",&n);
    make(head,n);
    printf("���뿪ʼ����s:");
    scanf("%d",&s);
    printf("����Ҫ��������m:");
    scanf("%d",&m);
    remake(head,link,n,m,s);
    write(link,n);
    printf("\n\n");
}

