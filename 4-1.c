#include <stdio.h>
#include <stdlib.h>
 
#define ENDKEY 0
 
typedef int KeyType;
 
typedef struct  node
{
    KeyType  key ; /*�ؼ��ֵ�ֵ*/
    struct node  *lchild,*rchild;/*����ָ��*/
}BSTNode, *BSTree;
 
void InsertBST(BSTree *bst, KeyType key)
/*���ڶ����������в����ڹؼ��ֵ���key��Ԫ�أ������Ԫ��*/
{ 
    BSTree s;
    if (*bst == NULL)/*�ݹ��������*/
    {
        s=(BSTree)malloc(sizeof(BSTNode));/*�����µĽ��s*/
        s-> key=key;
        s->lchild=NULL; 
        s->rchild=NULL;
        *bst=s;
    }
    else 
        if (key < (*bst)->key)
            InsertBST(&((*bst)->lchild), key);/*��s����������*/
        else 
            if (key > (*bst)->key)
                InsertBST(&((*bst)->rchild), key); /*��s����������*/
}
 
void  CreateBST(BSTree  *bst)
/*�Ӽ�������Ԫ�ص�ֵ��������Ӧ�Ķ���������*/
{ 
    KeyType key;
    *bst=NULL;
    scanf("%d", &key);
    while (key!=ENDKEY)   /*ENDKEYΪ�Զ��峣��*/
    {
        InsertBST(bst, key);
        scanf("%d", &key);
    }
}
 
void  PreOrder(BSTree root) 
/*�������������, rootΪָ�������������ָ��*/
{
    if (root!=NULL)
    {
        printf("%d  ",root->key);  /*������*/
        PreOrder(root->lchild);  /*�������������*/
        PreOrder(root->rchild);  /*�������������*/
    }
}
/*
BSTree  SearchBST(BSTree bst, KeyType key)
/ *�ڸ�ָ��bst��ָ�����������У��ݹ����ĳ�ؼ��ֵ���key��Ԫ�أ������ҳɹ�������ָ���Ԫ�ؽ��ָ�룬���򷵻ؿ�ָ��* /
{ 
    if (!bst) 
        return NULL;
    else 
        if (bst->key == key)
            return bst;/ *���ҳɹ�* /
        else
            if (bst->key > key)
                return SearchBST(bst->lchild, key);/ *����������������* /
            else 
                return SearchBST(bst->rchild, key);/ *����������������* /
}*/
 
BSTree  SearchBST(BSTree bst, KeyType key)
/*�ڸ�ָ��bst��ָ����������bst�ϣ����ҹؼ��ֵ���key�Ľ�㣬�����ҳɹ�������ָ���Ԫ�ؽ��ָ�룬���򷵻ؿ�ָ��*/
{ 
    BSTree q;
    q=bst;
    while(q)
    {
        if (q->key == key) 
            return q;  /*���ҳɹ�*/
        if (q->key > key)  
            q=q->lchild;  /*���������в���*/
        else  
            q=q->rchild;  /*���������в���*/
    }
    return NULL; /*����ʧ��*/
}/*SearchBST*/
 
 
 
void main()
{
    BSTree T;
    int k;
    BSTree result;
    printf("����������������������������0����:\n");
    CreateBST(&T);
    printf("��������������Ϊ:");
    PreOrder(T);
    printf("\n������Ҫ���ҵ�Ԫ��:");
    fflush(stdin);
    scanf("%d",&k);
    result = SearchBST(T,k);
    if (result != NULL)
        printf("�Ѳ鵽");
    else
        printf("δ�ҵ�!\n");
    
}

