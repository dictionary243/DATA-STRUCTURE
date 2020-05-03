package datastructure;
import java.util.Scanner;
class stackfun{
	protected int a[],tos=-1,size;
	public stackfun(int i)
	{
		size=i;
		a=new int[size];
	}
	public void push(int i)
	{
		if(tos==size-1){
			System.out.println("stack is full");
		}
		else {
		a[++tos]=i;
		}
	}
	public void pop()
	{
		if(tos==-1)
		{
			System.out.println("stack is empty");
		}
		else 
		{
			System.out.println(a[tos--]);
		}
	}
	public void display()
	{   int j=tos;
		if(tos==-1)
		{
			System.out.println("stack is empty");
		}
		else 
		{
			do {
				System.out.println(a[j--]);
			}while(j!=-1);
		}
	}
	public void search(int i)
	{	int ans=0,j=tos;	
		while(j!=-1)
		{
			if(a[j]==i) {
				ans++;
				break;
			}j--;
		}
		if(ans==1)
		{
			System.out.println("search of "+i+"is succesful");
		}
		else
		{
			System.out.println(i+"is not present");
		}
	}
	
}
public class Stack {

	public static void main(String[] args) {
		int i;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the size of stack:");
		i=sc.nextInt();
		stackfun s=new stackfun(i);
		while(true)
		{
		System.out.println("---------------------");
		System.out.println("enter 1 for push");
		System.out.println("enter 2 for pop");
		System.out.println("enter 3 for display");
		System.out.println("enter 4 for search");
		System.out.println("enter 5 for exit");
		System.out.println("enter choice:");
		i=sc.nextInt();
		switch (i) {
		case 1:
			System.out.println("enter num :");
			s.push(sc.nextInt());
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.display();
			break;
		case 4:
			System.out.println("enter num which u want to search:");
			s.search(sc.nextInt());
			break;
		case 5:
			System.out.println("thanks for using this");
			break;
		default :
			System.out.println("enter valid choice");
		}
		if(i==5)break;
		}
		}
}