#define NULL 0
typedef struct node{
	char a;
	struct node *link;
}node,*nodelink;
void readlink(nodelink head){
	nodelink p,q;
	char c;
	p=head;
	printf("Input a Incremental order linktable(a string):");
	scanf("%c",&c);
	if (c=='\n') printf("This string is empty??");
	while(c!='\n'){
		q=(nodelink)malloc(sizeof(node));
		q->a=c;
		p->link=q;
		p=q;
		scanf("%c",&c);
	  }
	p->link=NULL;
}
void writelink(nodelink head){
	nodelink q;
	if (head->link==NULL) printf(" This link is empty??\n");
	for(q=head->link;q;q=q->link)
		printf("%c",q->a);
	printf("\n");
	}

int  insert(nodelink head,char x){
	nodelink p,q,m;
	int i=0;
	p=head;
    q=(nodelink)malloc(sizeof(node));
    q->a=x;
	m=p;
	while(p->link!=0){
	if(p->a  >=  x){
	q->link=m->link;
	m->link=q;
	i=1;
	break;
	}
	m=p;
	p=p->link;
	}
	if(i==0){
	p->link=q;
	q->link=0;
	}
}

main()
{
	nodelink head;
	nodelink p;
	char x,z;
	head=(nodelink)malloc(sizeof(node));
	head->link=NULL;
	readlink(head);
	writelink(head); 
	if (head->link!=NULL){
		printf("Build link is :");
		for(p=head->link;p!=0;p=p->link)
		printf("%c",p->a);
		printf("\nPlease input a char you want to insert:");
		x=getchar();
		insert(head,x);
		printf("insert %c,link is:",x);
		for(p=head->link;p!=0;p=p->link)
		printf("%c",p->a);
		printf("\n\n");
		scanf("%c",&z);
	}
	}


