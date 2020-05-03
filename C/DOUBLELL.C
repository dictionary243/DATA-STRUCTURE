#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int num=0;
struct dll
{
int val;
struct dll *r;
struct dll *l;
};
struct dll *first,*last;

void insert1()
{
int a;
struct dll *n;
n=(struct dll *)malloc(sizeof(struct dll));
if(n==NULL)
{
return;
}
printf("\nenter the value which u want to enter:");
scanf("%d",&a);
n->val=a;
if(num==0)
{
n->r=NULL;
n->l=NULL;
num++;
first=n;
last=n;
}
else
{
n->l=NULL;
n->r=first;
first->l=n;
first=n;
num++;
}
}
void insert2()
{
int a;
struct dll *n;
n=(struct dll *)malloc(sizeof(struct dll));
if(n==NULL)
{
return;
}
printf("\nenter the value which u want to enter:");
scanf("%d",&a);
n->val=a;
if(num==0)
{
n->r=NULL;
n->l=NULL;
num++;
first=n;
last=n;
}
else
{
n->r=NULL;
n->l=last;
last->r=n;
last=n;
num++;
}
}
void insert3()
{
int i,j;
struct dll *n,*t;
n=(struct dll *)malloc(sizeof(struct dll));
if(n==NULL)
{
return;
}
printf("\n enter position at which u want to enter");
scanf("%d",&i);
if(i>0&&i<=num+1)
{
if(i==1)
{
insert1();
return;
}
if(i==num+1)
{
insert2();
return;
}
t=first;
for(j=1;j<i-1;j++)
{
t=t->r;
}
n->r=t->r;
n->l=t;
t->r=n;
printf("\n enter the value of node:");
scanf("%d",&j);
n->val=j;
num++;
}
else
{
printf("\nwe do not have that much of node");
}

}
void insert()
{
int i;
printf("\n1 for at front \n2 for end \n3 for at position");
printf("\nenter choice:");
scanf("%d",&i);
if(i==1)
{
insert1();
}
else if(i==2)
{
insert2();
}
else if(i==3)
{
insert3();
}
else
{
printf("\nwell enter valid choice");
insert();
}
}
void display()
{struct dll *t;
int i;
printf("\nhead->");
t=first;
for(i=0;i<num;i++)
{
printf("%d->",t->val);
t=t->r;
}
printf("null");
}
void delete1()
{
struct dll *temp;
if(num==1)
{
free(first);
first=last=NULL;
}
else
{
temp=first->r;
free(first);
temp->l=NULL;
first=temp;
}
num--;
}
void delete2()
{
struct dll *temp;
if(num==1)
{
free(first);
first=last=NULL;
}
else
{
temp=last->l;
free(last);
temp->r=NULL;
last=temp;
}
num--;
}
void delete3()
{
int i,j;
struct dll *temp;
printf("\nenter the num of node u want to delete:");
scanf("%d",&i);
if(i>num)
{
printf("\n thats not possible");
}
else
{
if(i==1)
{
delete1();
}
else if(i==num)
{
delete2();
}
else
{
temp=first;
for(j=1;j<i;j++)
{
temp=temp->r;
}
temp->l->r=temp->r;
temp->r->l=temp->l;
free(temp);
num--;
}
}
}
void delete()
{

int i;
if(num==0)
{
}
printf("\n1 for at front\n2 for at end\n3 at position");
printf("\nenter choice");
scanf("%d",&i);
if(i==1)
{
delete1();
}
else if(i==2)
{
delete2();
}
else if(i==3)
{
delete3();
}
else
{
printf("\nenter valid choice");
delete();
}
}
void main()
{
int i;
clrscr();
first=NULL;
last=NULL;

while(243)
{
printf("\n---------------------------------");
display();
printf("\n---------------------------------");
printf("\n1 for insert \n2 for delete \n3 for display\n4 for exit");
printf("\nenter choice:");
scanf("%d",&i);
if(i==1)
{
insert();
}
else if(i==2)
{
delete();
}
else if(i==3)
{
display();
}
else if(i==4)
{
printf("\n thanks for using this");
break;
}
}
getch();
}