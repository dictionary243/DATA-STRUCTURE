#include<stdio.h>
#include<conio.h>
#define n 20
int s[n];
int f=-1,r=-1;
void insert()
{
 if(r+1==n)
 {
 printf("\n queue is full");
 }
 else
 {
 r++;
 printf("\n enter number to insert:");
 scanf("%d",&s[r]);
 if(f==-1)
 {f++;}
 }
}
void delete()
{int i;
 if(f==-1)
 {
 printf("\n there is no element in queue:");
 }
 else
 {
 printf("\n so deleted number is :%d",s[f]);
 if(r==f)
 {
 f=-1;
 r=-1;
 }
 else
 {
 for(i=0;i<r;i++)
 {s[i]=s[i+1];}
 r--;
 }
}
}

void disp()
{int j;
if(f==0)
{
printf("\n there r %d numbers in queue",r+1);
for(j=0;j<=r;j++)
{printf("\n element at index %d is %d",j+1,s[j]);}
}
if(f==-1)
{
printf("\n there is no element in queue");
}
}
void main()
{
int c;
while(243)
{
printf("\n 1 for insert \n 2 for delete \n 3 for info(display) \n 4 for exit\n enter a number:");
scanf("%d",&c);
 switch(c)
 {
   case 1:
   insert();
   break;
   case 2:
   delete();
   break;
   case 3:
   disp();
   break;
   case 4:
   printf("\n thanks for using this");
   break;
   default:
   printf("\n enter valid choice:");
  }
  if(c==4)
  {
  break;
  }
 }
 getch();
 }