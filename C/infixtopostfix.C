#include<stdio.h>
#include<conio.h>
int isoperand(char e)
{
if((e>='a'&&e<='z')||(e>='A'&&e<='Z'))
return 1;
else
return 0;
}
int isoprator(char a)
{
if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
return 1;
else
return 0;
}
void push(char c[],int *t,char d)
{
c[++(*t)]=d;
}
char pop(char h[],int *u)
{
return h[(*u)--];
}
int prec(char b)
{
if(b=='+'||b=='-')
return 1;
else if(b=='*'||b=='/')
return 2;
else
return 3;
}
void main()
{
int i=0,j=0,tos=-1;
char pof[100],s[100],z;
char inf[100];
clrscr();
printf("enter operation :");
scanf("%s",inf);
while(inf[i]!='\0')
{
if(isoperand(inf[i]))
{
pof[j]=inf[i];
j++;
i++;
}
if(isoprator(inf[i]))
{
if(tos==-1||prec(inf[i])>prec(s[tos])||s[tos]=='('||prec(inf[i])==3)
{
z=inf[i];
push(s,&tos,z);
i++;
}
else
{
pof[j++]=pop(s,&tos);
}
}
if(inf[i]=='(')
{
push(s,&tos,inf[i++]);
}
if(inf[i]==')')
{
while(s[tos]!='(')
{
pof[j++]=pop(s,&tos);
}
z=pop(s,&tos);
i++;
}

}
while(tos>-1)
{
pof[j++]=pop(s,&tos);
}
printf(" your input was:");
printf("%s",inf);
printf("\n so output is :");
printf("%s",pof);
getch();

}