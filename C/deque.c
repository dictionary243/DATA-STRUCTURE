#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct dequeue
{
	struct node *front;
	struct node *rear;
};
void Insertatfront(struct dequeue *p,int item)
{

	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	if(p->front==NULL)
	{
		p->front=p->rear=temp;
	}
	else
	{
		temp->link=p->front;
		p->front=temp;
	}
}
void Insertatend(struct dequeue *p,int item)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	if(p->front==NULL)
	{
		p->front=temp;
	}
	else
	{
		p->rear->link=temp;
	}
	p->rear=temp;
}
int Removeatfront(struct dequeue*p)
{
	struct node*temp = p->front;
	int item;
	if(temp==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		temp=p->front;
		item=temp->data;
		p->front=temp->link;
		free(temp);
		if(temp==NULL)
		{
			p->rear=NULL;
		}
		return item;
	}
}
int Removeatend(struct dequeue*p)
{
	struct node*temp,*rleft,*q;
	int item;
	temp=p->front;
	if(p->rear==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		while(temp!=p->rear)
		{
			rleft=temp;
			temp=temp->link;
		}
		q=p->rear;
		item=q->data;
		free(q);
		p->rear=rleft;
		p->rear->link=NULL;
		if(p->rear==NULL)
		{
			p->front=NULL;
		}
		return item;
	}
}
void makenull(struct node *front,struct node *rear)
{
	struct node *temp=NULL;
	front=rear=temp;
}

int main() {

	int ch,item;
	struct dequeue p;
	p.front=NULL;
	p.rear=NULL;
//makenull(p->front,p->rear);
	do{
		printf("\n 1.Insert at front \t\n 2.Insert at rear \t\n 3.Delete at front \t\n 4.Delete at rear \t\n 5.EXIT \t\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number to be inserted at front = ");
				scanf("%d",&item);
				Insertatfront(&p,item);
				break;
			case 2:
				printf("Enter the number to be inserted at rear = ");
				scanf("%d",&item);
				Insertatend(&p,item);
				break;
			case 3:
				printf("The number deleted from front = %d",Removeatfront(&p));
				break;
			case 4:
				printf("The number deleted from rear = %d",Removeatend(&p));
				break;
			case 5:
				printf("EXIT");
		}
	}while(ch!=5);
	return 0;
}
