
#include<stdio.h>
#define size 15
int heap[size];
int csize=0;
void insert()
{
  int i,child,parent;
  printf("\nenter a number:");
  scanf("%d",&i);
  if(csize==size-1)
  {
    printf("\nheap is full");
  }
  else if(csize==0)
  {
    heap[0]=i;
    csize++;
  }
  else
  {
    child=csize;
    parent=(child-1)/2;
    heap[child]=i;
    while((heap[parent]<i)&&child!=0)
    {
      heap[child]=heap[parent];
      child=parent;
      parent=(child-1)/2;
    }
    heap[child]=i;
    csize++;
  }
}
void display()
{
  int i;
  if(csize==0)
  {
    printf("\nheap is empty");
  }
  else
  {
    for(i=0;i<csize;i++)
    {
      printf("\t%d",heap[i]);
    }
  }
}
int max(int a,int b)
{
  if(heap[a]>=heap[b])
  {
    return a;
  }
  else
  {
    return b;
  }
}
void delete()
{
  int child,parent,item;
  if(csize==0)
  {
    printf("\nheap is empty");
  }
  else
  {
    heap[0]=heap[csize-1];
    csize--;
    item=heap[0];
    parent=0;
    if((2*parent+2)<csize)
    {
    child=max(2*parent+1,2*parent+2);

    while(heap[child]>item&&child<csize)
    {
      heap[parent]=heap[child];
      parent=child;
      if((2*parent+2)>csize)
      {
        break;
      }
      else
      {
        child=max(2*parent+1,2*parent+2);
      }
    }
    heap[parent]=item;
    }
  }
}
void main()
{
  int i;
  while(243)
  {
    printf("\n1 for insert\n2 for delete\n3 for display\n4 for exit");
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
    else if(i=3)
    {
      printf("\nthanks for using this:");
      break;
    }
    else
    {
      printf("\nenter valid choice");
    }
  }
}
