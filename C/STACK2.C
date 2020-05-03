#include<stdio.h>

void push(int a[],int*t,int x)
{
if(*t<100)
{
a[++(*t)]=x;

}
else
{
printf("stack overflow\n");
}
}
void pop(int a[],int*t)
{
if((*t)==-1)
{
printf("stack is empty\n");
}
else
{
printf("%d",a[(*t)--]);
}
}
void search(int a[],int*t)
{
int x,k,j;
printf("enter a number that u want to search:");
scanf("%d",&x);
if(*t>-1)
{
for(k=0;k<=(*t);k++)
{
if(a[k]==x)
{
printf("\n so your element %d is present at index:%d",x,k+1);
}
else
{
continue;
}
}
}
}
void info(int a[],int*t)
{
int k=*t;
printf("\n stack is having %d elements:",(*t)+1);
if(*t>-1)
{
printf("\n------------ your stack -------------");
while(k>-1)
{
printf("\n");
printf("%d",a[k]);
k--;
}
}
}
void main()
{
int n[100],i,c,tos=-1,v;
while(243)
{
printf("\n-------------------------------------------\n");
printf("1-for push \n2- for pop\n3-for searching element\n4-for stack info\n5-for exit\n enter choice:");
scanf("%d",&c);
if(c==1)
{
printf(" enter any number:");
scanf("%d",&i);
push(n,&tos,i);
}
if(c==2)
{
pop(n,&tos);

}
if(c==3)
{
search(n,&tos);
}
if(c==4)
{
info(n,&tos);
}
if(c==5)
{
printf("thanks\n");
break;
}
if(c<1||c>5)
{
printf("enter correct number in 1 to 5\n");
}
}
}
