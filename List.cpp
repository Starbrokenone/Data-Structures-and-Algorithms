//线性表的顺序存储结构
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define LIST_INIT_SIIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间分配增量
typedef int ElemType;

typedef struct{
    ElemType *elem;//存储空间基址 =
    int length;
    int listsize;
} Sqlist;
int InitList_Sq(Sqlist&L) {
    //构造一个空的线性表l
    L.elem = (ElemType*)malloc(LIST_INIT_SIIZE*sizeof(ElemType));
    if(!L.elem)exit;//存储分配失败
    L.length = 0;//空表长度为0
    L.listsize=LIST_INIT_SIIZE;//初始存储容量
    return 1;
}
int main()
{Sqlist L;
    ElemType e;
    InitList_Sq(L);
    printf("......");
    return 0;
}

