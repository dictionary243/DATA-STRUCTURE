#include<stdio.h>
#include<stdlib.h>
int num=0;
struct node
{
int value;
struct node *right;
struct node *left;
};

struct node *insert(struct node *root,int val)
{
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
n->value=val;
if(root==NULL)
{
root=n;
root->right=NULL;
root->left=NULL;
num++;
}
else if(val<root->value)
{
root->left=insert(root->left,val);
}
else
{
root->right=insert(root->right,val);
}
return root;
}
void inorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
inorder(h->left);
printf("\t%d",h->value);
inorder(h->right);
return;
}
}
void preorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
printf("\t%d",h->value);
preorder(h->left);
preorder(h->right);
return;
}
}
void postorder(struct node *h)
{
if(h==NULL)
{
return ;
}
else
{
postorder(h->left);
postorder(h->right);
printf("\t%d",h->value);

return;
}
}
void printlevel(struct node *root,int i)
{
  if(i==0)
  {
    if(root==NULL)
    {
      return;
    }
    else
    {
      printf("\t%d",root->value);
    }
  }
  else
  {
    printlevel(root->left,i-1);
    printlevel(root->right,i-1);
  }
}
void levelorder(struct node *root)
{
  int i,j;
  j=height(root);
  printf("\n");
  for(i=0;i<=j;i++)
  {
    printlevel(root,i);
    printf("\n");
  }

}
void display(struct node *root)
{
  int i;
  printf("\n--------------------------");
  printf("\n1 for display inorder\n2 for preorder\n3 for post order\n4 for level order\nenter choice:");
  scanf("%d",&i);
  if(i==1)
  {
    printf("\n--------------------------\n");
  inorder(root);
  }
  else if(i==2)
  {
    printf("\n--------------------------\n");
  preorder(root);
  }
  else if(i==3)
  {
    printf("\n--------------------------\n");
  postorder(root);
  }
  else if(i==4)
  {
    printf("\n--------------------------\n");
    levelorder(root);
  }
  else

  {
    printf("\n--------------------------");
    printf("\nenter valid choice:");
  }
return;
}
int search(struct node *root,int val) //search a node in treee if present return 1 else o
{  int a=0;
     if(root==NULL)
     {
       return a;
     }
    else if(val==root->value)
    {
      return 1;
    }
    else if(val<(root->value))
    {
      return search(root->left,val);
    }
    else
    {
      return search(root->right,val);
    }
  }

struct node *minright(struct node *root)  //minimum value in right subtree which can replace root
{
  struct node *temp;
  temp=root->right;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp;
}

struct node *maxleft(struct node *root)
{
  struct node *temp;
  temp=root->left;
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
  return temp;

}
struct node *delete(struct node *root,int val)   //delete function
{
  struct node *temp;
  int x,choice;
  if(root==NULL)
  {
    printf("\n--------------------------");
    printf("\nwe can not delete ");
  }

  else
  {
     if(root->value==val)    //when root is the node to be deleted
     {
       if(root->right==NULL&&root->left==NULL) //when root is the only node
       {
         free(root);
         root=NULL;
       }
       else if(root->right==NULL)         //when root is having left subtree only
       {
         temp=root->left;
         free(root);
         root=temp;
       }
       else if(root->left==NULL)       //when root is having only right subtree;
       {
         temp=root->right;
         free(root);
         root=temp;
       }
       else                           //when we have to set root value to min value of left subtree
       {
         printf("\nwhich value u want to see as root's value\n%d or %d",minright(root)->value,maxleft(root)->value);
         scanf("%d",&choice);
         if(choice==minright(root)->value)
         {
        x=minright(root)->value;
        delete(root,x);
        root->value=x;
      }
      else
      {
        x=maxleft(root)->value;
        delete(root,x);
        root->value=x;
      }
       }
     }
     else if(root->value>val)
     {
       root->left=delete(root->left,val);
     }
     else
     {
       root->right=delete(root->right,val);
     }
  }

  return root;
}

int max(int a,int b)
{
  if(a>b)
  return a;
  else
  return b;
}
int height(struct node *root)
{
  if(root==NULL||(root->right==NULL&&root->left==NULL))
  return 0;
  else
  return 1+max(height(root->left),height(root->right));
}

struct node *clonetree(struct node *root)
{
  struct node *n;
  n=(struct node *)malloc(sizeof(struct node));
  if(root==NULL)
  {
    return NULL;
  }
  else
  {
    n->value=root->value;
    n->left=clonetree(root->left);
    n->right=clonetree(root->right);
  }
}
int checktree(struct node *tree1,struct node *tree2)
{
  int t=0;
  if(tree1==NULL&&tree2==NULL)
  {
    t=0;
  }
  else if(tree1==NULL&&tree2!=NULL)
  {
    t=1;
  }
  else if (tree2==NULL&&tree1!=NULL)
  {
       t=1;
  }
  else
  {
    if(tree1->value==tree2->value)
    {
      t=checktree(tree1->left,tree2->left)+checktree(tree1->right,tree2->right);
    }
    else
    {
      t=1;
    }
  }
  return t;
}
void main()
{
  int i,j,k;
struct node *root,*tree2;
root=NULL;
while(243)
{
printf("\n--------------------------");
printf("\n1 for insert\n2 for delete\n3 for display\n4 for search a node\n5 to know height of tree\n and total nodes\n6 to clone a tree\n7 for exit\n--------------------------\nenter choice:");
scanf("%d",&i);
if(i==1)
{
  printf("\n--------------------------");
  printf("\n enter num:");
  scanf("%d",&j);
  root=insert(root,j);
}
else if(i==2)
{
  printf("\n--------------------------");
  printf("\n enter num:");
  scanf("%d",&j);
  root=delete(root,j);
}
else if(i==3)
{
  display(root);
}
else if(i==4)
{
  printf("\n--------------------------");
  printf("\n enter num");
  scanf("%d",&j);
  k=search(root,j);
  if(k==1)
  {
    printf("\n--------------------------");
    printf("\nsearch succesful");
  }
  else
  {
    printf("\n--------------------------");
    printf("\nthat node is not present:");
  }
}
else if(i==5)
{
  printf("\n--------------------------");
  printf("\nheight of tree is %d",height(root));
  printf("\ntotal nodes are %d",num);
}
else if(i==6)
{
  tree2=clonetree(root);
  //display(tree2);
  printf("\n--------------------------");
  printf("\n enter num:");
  scanf("%d",&j);

  tree2=insert(tree2,j);
  if(checktree(tree2,root)==0)
  {
  printf("\nchecking tree is same ");
  }
  else
  {
    printf("\nnot same");
  }
}
else if(i==7)
{
  printf("\n--------------------------");
  printf("\n thanks for using this");
  printf("\n--------------------------");
  break;
}
else
{
  printf("\n--------------------------");
  printf("\n invalid choice");
}
}
}
