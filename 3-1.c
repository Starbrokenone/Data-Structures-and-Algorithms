#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int n; 
struct VNode{              
	int position; 
	struct VNode* next;
};
struct ArcNode{                
	int mark; 
	struct VNode* first;
};
void DFS(struct ArcNode* v,struct ArcNode* w){             
	struct VNode* L; w->mark=1; L=w->first; 
	while(L!=NULL){ 
	if((v+(L->position))->mark==0){ 
		DFS(v,(v+L->position));               
	} 
	L=L->next; } 
} 
int main()
{ 
int i,j,k; 
int num=0; 
struct ArcNode* p; 
struct VNode* temp; 
struct VNode* flag; 
printf("\n�����붥����� n��"); 
scanf("%d",&n); 
while(n<1){ 
	printf("�������ֵ���������������룺\n"); 
	scanf("%d",&n); 
} 
p=(struct ArcNode*)malloc(n*sizeof(struct ArcNode));   
for(i=0;i<n;i++){           
	printf("\n��������V%dΪ��β�����л�������9��������\n",i+1); 
	scanf("%d",&k);  
	if(k==9){
				p[i].mark=0; p[i].first=NULL; 
			}
 	else{ 
			temp=(struct VNode*)malloc(sizeof(struct VNode));
			temp->position=k;
			temp->next=NULL;
			p[i].first=temp; 
			p[i].mark=0; 
			flag=temp; 
			scanf("%d",&k); 
			while(k!=9){ 
				temp=(struct VNode*)malloc(sizeof(struct VNode)); 
				temp->position=k; 
				temp->next=NULL; 
				flag->next=temp; 
				flag=temp; 
				scanf("%d",&k); 
			}
	 }
} 
i=0; 
while(p[i].mark==0){               
	DFS(p,(p+i)); num++; i=0; 
	while(p[i].mark!=0&&i<n){
	 i++; 
	 } 
} 
printf("��ͼ����ͨ��������Ϊ��%d\n",num); system("pause"); 
return 0;  
}
