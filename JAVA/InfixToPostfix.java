package datastructure;
import java.util.Scanner;

class Func{
	int tos=0;
	char []a=new char[20];
	public void push(char i)
	{
		a[++tos]=i;		
	}
	public char pop()
	{
		return a[tos--];
	}
}
public class InfixToPostfix {
public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	String infix,postfix;
	infix=sc.nextLine();
	postfix=convert(infix);
	System.out.println("so infix form was :"+infix);
	System.out.println("so postfix form is :"+postfix);
}
public static String convert(String infix)
{
	int i=0,j=0;
	String postfix;
	Func s=new Func();
	char ch;
	char array[]=new char[20]; 
	while(i<infix.length()) {
		ch=infix.charAt(i);
		if(isoperand(ch)) {
			array[j++]=ch;
			i++;
		}
		else if(isoprator(ch)) {
			if(s.tos==0||prec(ch)>prec(s.a[s.tos])||s.a[s.tos]=='('||prec(ch)==3)
			{
				s.push(ch);i++;
			}
			else
			{
				array[j++]=s.pop();
			}
		}
		else if(ch=='(')
		{
			s.push(ch);i++;
		}
		else// (ch==')')
		{
			while(s.a[s.tos]!='(') {
				array[j++]=s.pop();
			}
			ch=s.pop();//have to pop '(' char
			i++;
		}
	}//end of while
		while(s.tos!=-1) {
			array[j++]=s.pop();
		}
		postfix=new String(array);
	return postfix;
}//end of convert function
static boolean isoperand(char e)
{
	if((e>='a'&&e<='z')||(e>='A'&&e<='Z'))
		return true;
	else
		return false;
}
static boolean isoprator(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
		return true;
	else
		return false;
}
static int prec(char b)
{
	if(b=='+'||b=='-')
		return 1;
	else if(b=='*'||b=='/')
		return 2;
	else
		return 3;
}


}//end of class