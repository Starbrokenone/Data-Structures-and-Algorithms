#include <stdio.h>
#include <stdlib.h>
 
#define ENDKEY 0
 
typedef int KeyType;
 
typedef struct  node
{
    KeyType  key ; /*关键字的值*/
    struct node  *lchild,*rchild;/*左右指针*/
}BSTNode, *BSTree;
 
void InsertBST(BSTree *bst, KeyType key)
/*若在二叉排序树中不存在关键字等于key的元素，插入该元素*/
{ 
    BSTree s;
    if (*bst == NULL)/*递归结束条件*/
    {
        s=(BSTree)malloc(sizeof(BSTNode));/*申请新的结点s*/
        s-> key=key;
        s->lchild=NULL; 
        s->rchild=NULL;
        *bst=s;
    }
    else 
        if (key < (*bst)->key)
            InsertBST(&((*bst)->lchild), key);/*将s插入左子树*/
        else 
            if (key > (*bst)->key)
                InsertBST(&((*bst)->rchild), key); /*将s插入右子树*/
}
 
void  CreateBST(BSTree  *bst)
/*从键盘输入元素的值，创建相应的二叉排序树*/
{ 
    KeyType key;
    *bst=NULL;
    scanf("%d", &key);
    while (key!=ENDKEY)   /*ENDKEY为自定义常量*/
    {
        InsertBST(bst, key);
        scanf("%d", &key);
    }
}
 
void  PreOrder(BSTree root) 
/*先序遍历二叉树, root为指向二叉树根结点的指针*/
{
    if (root!=NULL)
    {
        printf("%d  ",root->key);  /*输出结点*/
        PreOrder(root->lchild);  /*先序遍历左子树*/
        PreOrder(root->rchild);  /*先序遍历右子树*/
    }
}
/*
BSTree  SearchBST(BSTree bst, KeyType key)
/ *在根指针bst所指二叉排序树中，递归查找某关键字等于key的元素，若查找成功，返回指向该元素结点指针，否则返回空指针* /
{ 
    if (!bst) 
        return NULL;
    else 
        if (bst->key == key)
            return bst;/ *查找成功* /
        else
            if (bst->key > key)
                return SearchBST(bst->lchild, key);/ *在左子树继续查找* /
            else 
                return SearchBST(bst->rchild, key);/ *在右子树继续查找* /
}*/
 
BSTree  SearchBST(BSTree bst, KeyType key)
/*在根指针bst所指二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{ 
    BSTree q;
    q=bst;
    while(q)
    {
        if (q->key == key) 
            return q;  /*查找成功*/
        if (q->key > key)  
            q=q->lchild;  /*在左子树中查找*/
        else  
            q=q->rchild;  /*在右子树中查找*/
    }
    return NULL; /*查找失败*/
}/*SearchBST*/
 
 
 
void main()
{
    BSTree T;
    int k;
    BSTree result;
    printf("建立二叉排序树，请输入序列以0结束:\n");
    CreateBST(&T);
    printf("先序遍历输出序列为:");
    PreOrder(T);
    printf("\n请输入要查找的元素:");
    fflush(stdin);
    scanf("%d",&k);
    result = SearchBST(T,k);
    if (result != NULL)
        printf("已查到");
    else
        printf("未找到!\n");
    
}

