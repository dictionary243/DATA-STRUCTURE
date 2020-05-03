package datastructure;

import java.util.Scanner;

class queuefun{
	int front=-1,rear=-1,size,a[];
	public queuefun(int i)
	{
		size=i;
		a=new int[size];
	}
	public void insert(int i)
	{
		if(((rear+1)%size)==front){
			System.out.println("queue is full");
		}
		else {
			if(front==-1)
				{front++;}
			rear=(rear+1)%size;
			a[rear]=i;
		}
	}
	public void delete()
	{
		if(front==-1)
		{
			System.out.println("queue is empty");
		}
		else 
		{
			System.out.println(a[front]+" is deleted");
			if(front==rear)
				front=rear=-1;
			else
				front=(front+1)%size;
		}
	}
	public void display()
	{   int j=front;
		if(front==-1)
		{
			System.out.println("queue is empty");
		}
		else 
		{
			while(true){
				System.out.println(a[j]);
				if(j==rear)
					break;
				else
					j=(j+1)%size;
			}
		}
	}
	public void search(int i)
	{	int ans=0,j=front;	
		while(true)
		{
			if(a[j]==i) {
				ans++;
				break;
			}
			if(j==rear)
				break;
			else
				j=(j+1)%size;
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

public class Queue {

	public static void main(String[] args) {
		int i;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the size of stack:");
		i=sc.nextInt();
		queuefun s=new queuefun(i);
		while(true)
		{
		System.out.println("---------------------");
		System.out.println("enter 1 for insert");
		System.out.println("enter 2 for delete");
		System.out.println("enter 3 for display");
		System.out.println("enter 4 for search");
		System.out.println("enter 5 for exit");
		System.out.println("enter choice:");
		i=sc.nextInt();
		switch (i) {
		case 1:
			System.out.println("enter num :");
			s.insert(sc.nextInt());
			break;
		case 2:
			s.delete();
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


