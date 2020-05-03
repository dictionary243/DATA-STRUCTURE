#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
char name[10];
char car[10];
};
struct node
{
char car[10];
struct node *next;
};
struct node *head;
struct data queue[10];
struct data stack[10];
int order=0;
int tos=-1;
int front=-1;
void insertcar()
{
char a[10];
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
printf("\n enter car name:");
scanf("%s",n->car);
n->next=head;
head=n;
}
void ordercar()
{
char a[10];
if(order==10)
{
printf("\n list is full plz visit next time");
}
else
{
printf("\n enter your  name sir:");
scanf("%s",queue[order].name);

printf("\n enter car name:");
scanf("%s",queue[order].car);
order++;
front=0;
}
}
void deletecar(char a[10])
{
struct node *temp,*t;
temp=head;
if(strcmp(head->car,a)==0)
{
temp=head->next;
free(head);
head=temp;
}
else
{
while(temp->next!=NULL&&strcmp(temp->next->car,a)!=0)
{
temp=temp->next;
}
if(temp->next==NULL)
{
printf("\n car is not in the list");
}
else
{
t=temp->next->next;
free(temp->next);
temp->next=t;
}
}
}
int search(char *a)
{
struct node *temp,*t;
int y=0;
temp=head;
if(strcmp(head->car,a)==0)
{
y=1;
}
else
{
while(temp->next!=NULL&&strcmp(temp->next->car,a)!=0)
{
temp=temp->next;
}
if(temp->next==NULL)
{
y=0;
}
else
{
y=1;
}
}
return y;
}
void sellcar()
{
if(front==-1)
{
printf("\nwell there is no order of car right now");
}
else
{
if(search(queue[front].car)==0)
{
printf("\n sorry mr-%s your car %s is not availabel visit next time",queue[front].name,queue[front].car); 
}
else
{tos=tos+1;
strcpy(stack[tos].name,queue[front].name);
strcpy(stack[tos].car,queue[front].car);
deletecar(queue[front].car);
}
front++;
if(front==order)
{
front=-1;
order=0;
}
}
}
void display()
{struct node *t;
if(head==NULL)
{
printf("\n no car in  the stock");
}
else
{t=head;
printf("\n->");
while(t->next!=NULL)
{
printf("%s->",t->car);
t=t->next;
}
printf("%s",t->car);
}
}
void display1()
{
int i;
if(order==0)
{
printf("\n well order list is empty");
}
for(i=0;i<order;i++)
{
printf("\n%d customer name is %s",i+1,queue[i].name);

printf("\n%d car name is %s",i+1,queue[i].car);
}
}
void lastcar()
{
if(tos==-1)
{
printf("\n not sold any car");
}
else
{
printf("\n last sold car is :%s which is belongs to mr-%s",stack[tos].car,stack[tos].name);
tos--;
}
}
int main()
{
int i;
while(243)
{
printf("\n welcome to car shop");
printf("\n1 for add a car\n2 for order a car\n3 for sell a car\n4 for last sold car\n5 for display car\n6 for display orders\n7 for exit");
scanf("%d",&i);
if(i==1)
{
insertcar();
}
else if(i==2)
{
ordercar();
}
else if(i==3)
{
sellcar();
}
else if(i==4)
{
lastcar();
}
else if(i==5)
{
display();
}
else if(i==6)
{
display1();
}
else if(i==7)
{
printf("\n thanks for using this");
break;
}
else
{
printf("\nenter cvalid choice");
}
}
}













