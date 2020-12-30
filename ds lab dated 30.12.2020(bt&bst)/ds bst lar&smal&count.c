#include<stdio.h>
#include<conio.h>
#include<process.h>
struct node
 {
  int info;
  struct node *rlink;
  struct node *llink;
 };
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("mem full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert(NODE root,int item)
{
NODE temp,cur,prev;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
if(root==NULL)
 return temp;
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
cur=(item<cur->info)?cur->llink:cur->rlink;
}
if(item<prev->info)
 prev->llink=temp;
else
 prev->rlink=temp;
return root;
}
void display(NODE root,int i)
{
int j;
if(root!=NULL)
 {
  display(root->rlink,i+1);
  for(j=0;j<i;j++)
	  printf("  ");
   printf("%d\n",root->info);
	 display(root->llink,i+1);
 }
}


void preorder(NODE root)
{
if(root!=NULL)
 {
  printf("%d\n",root->info);
  preorder(root->llink);
  preorder(root->rlink);
  }
 }
void postorder(NODE root)
{
if(root!=NULL)
 {

  postorder(root->llink);
  postorder(root->rlink);
  printf("%d\n",root->info);
  }
 }
void inorder(NODE root)
{
if(root!=NULL)
 {
  inorder(root->llink);
  printf("%d\n",root->info);
  inorder(root->rlink);
  }
 }
void largest(NODE root)
{
	while(root!=NULL && root->rlink!=NULL)
	{
		root=root->rlink;
	}
	printf("\nLargest value is %d",root->info);
}
void smallest(NODE root)
{
	while(root!=NULL && root->llink!=NULL)
	{
		root=root->llink;
	}
	printf("\nSmallest value is %d",root->info);
}
int count(NODE root){
 int c=1;
 if(root==NULL)
    return 0;
 else{
    c+=count(root->llink);
    c+=count(root->rlink);
    return c;
    }
}
void main()
{

int item,choice,c;
NODE root=NULL;
for(;;)
{
printf("\n1.insert\n2.display\n3.pre-order\n4.post-order\n5.in-order\n6.no.of elements in tree\n7.largest element in tree\n8.smallest element of tree\n9.exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item\n");
		 scanf("%d",&item);
		 root=insert(root,item);
		 break;
  case 2:display(root,0);
		 break;
  case 3:preorder(root);
         break;
  case 4:postorder(root);
         break;
  case 5:inorder(root);
         break;
  case 6:c=count(root);
         printf("No. of nodes are: %d\n",c);
         break;
  case 7:largest(root);
         break;
  case 8:smallest(root);
         break;
  default:exit(0);
		  break;
	  }
	}
 }
