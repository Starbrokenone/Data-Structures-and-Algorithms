#include <stdio.h>
#include <malloc.h>
#define MAX 20          //����ʽ�������
typedef struct      //�����Ŷ���ʽ����������
{
    double coef;        //ϵ��
    int exp;            //ָ��
} PolyArray;

typedef struct pnode    //���嵥���������ͣ��������ʽ�е�һ������ɶ���ʽ
{
    double coef;        //ϵ��
    int exp;            //ָ��
    struct pnode *next;
} PolyNode;

void DispPoly(PolyNode *L)  //�������ʽ
{
    bool first=true;        //firstΪtrue��ʾ�ǵ�һ��
    PolyNode *p=L->next;
    while (p!=NULL)
    {
        if (first)
            first=false;
        else if (p->coef>0)
            printf("+");
        if (p->exp==0)
            printf("%g",p->coef);
        else if (p->exp==1)
            printf("%gx",p->coef);
        else
            printf("%gx^%d",p->coef,p->exp);
        p=p->next;
    }
    printf("\n");
}

void DestroyList(PolyNode *&L)  //���ٵ�����
{
    PolyNode *p=L,*q=p->next;
    while (q!=NULL)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
}

void CreateListR(PolyNode *&L, PolyArray a[], int n) //β�巨����
{
    PolyNode *s,*r;
    int i;
    L=(PolyNode *)malloc(sizeof(PolyNode)); //����ͷ���
    L->next=NULL;
    r=L;                        //rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
    for (i=0; i<n; i++)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode));//�����½��
        s->coef=a[i].coef;
        s->exp=a[i].exp;
        r->next=s;              //��*s����*r֮��
        r=s;
    }
    r->next=NULL;               //�ն˽��next����ΪNULL
}

void Sort(PolyNode *&head)      //��exp��ݼ�����
{
    PolyNode *p=head->next,*q,*r;
    if (p!=NULL)                //��ԭ����������һ�������ϵ����ݽ��
    {
        r=p->next;              //r����*p����̽���ָ��
        p->next=NULL;           //����ֻ��һ�����ݽ��������
        p=r;
        while (p!=NULL)
        {
            r=p->next;          //r����*p����̽���ָ��
            q=head;
            while (q->next!=NULL && q->next->exp>p->exp)
                q=q->next;      //����������Ҳ���*p��ǰ�����*q
            p->next=q->next;    //��*p���뵽*q֮��
            q->next=p;
            p=r;
        }
    }
}

void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)  //�������򼯺ϵĲ�����ɼӷ�
{
    PolyNode *pa=ha->next,*pb=hb->next,*s,*tc;
    double c;
    hc=(PolyNode *)malloc(sizeof(PolyNode));        //����ͷ���
    tc=hc;
    while (pa!=NULL && pb!=NULL)
    {
        if (pa->exp>pb->exp)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode)); //���ƽ��
            s->exp=pa->exp;
            s->coef=pa->coef;
            tc->next=s;
            tc=s;
            pa=pa->next;
        }
        else if (pa->exp<pb->exp)
        {
            s=(PolyNode *)malloc(sizeof(PolyNode)); //���ƽ��
            s->exp=pb->exp;
            s->coef=pb->coef;
            tc->next=s;
            tc=s;
            pb=pb->next;
        }
        else                //pa->exp=pb->exp
        {
            c=pa->coef+pb->coef;
            if (c!=0)       //ϵ��֮�Ͳ�Ϊ0ʱ�����½��
            {
                s=(PolyNode *)malloc(sizeof(PolyNode)); //���ƽ��
                s->exp=pa->exp;
                s->coef=c;
                tc->next=s;
                tc=s;
            }
            pa=pa->next;
            pb=pb->next;
        }
    }
    if (pb!=NULL) pa=pb;    //�������µĽ��
    while (pa!=NULL)
    {
        s=(PolyNode *)malloc(sizeof(PolyNode)); //���ƽ��
        s->exp=pa->exp;
        s->coef=pa->coef;
        tc->next=s;
        tc=s;
        pa=pa->next;
    }
    tc->next=NULL;
}

int main()
{
    PolyNode *ha,*hb,*hc;
    PolyArray a[]= {{1.2,0},{2.5,1},{3.2,3},{-2.5,5}};
    PolyArray b[]= {{-1.2,0},{2.5,1},{3.2,3},{2.5,5},{5.4,10}};
    CreateListR(ha,a,4);
    CreateListR(hb,b,5);
    printf("ԭ����ʽA:   ");
    DispPoly(ha);
    printf("ԭ����ʽB:   ");
    DispPoly(hb);
    Sort(ha);
    Sort(hb);
    printf("�������ʽA: ");
    DispPoly(ha);
    printf("�������ʽB: ");
    DispPoly(hb);
    Add(ha,hb,hc);
    printf("����ʽ���:  ");
    DispPoly(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}

