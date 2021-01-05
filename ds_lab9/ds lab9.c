#include<stdio.h>
#include<stdlib.h>
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
NODE insert_rear(NODE head,int item)
{
NODE temp,cur;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
cur=head->llink;
temp->llink=cur;
cur->rlink=temp;
head->llink=temp;
temp->rlink=head;
head->info=head->info+1;
return head;
}
NODE insert_leftpos(int item,NODE head)
{
NODE temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->llink;
 printf("enter towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}
NODE insert_righttpos(int item,NODE head)
{
NODE temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->rlink;
 printf("enter towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->llink=temp;
 temp->llink=cur;
 cur->rlink=temp;
 temp->rlink=prev;
 return head;
}
NODE delete_all_key(int item,NODE head)
{
NODE prev,cur,next;
int count;
   if(head->rlink==head)
    {
     printf("LE");
     return head;
     }
count=0;
cur=head->rlink;
while(cur!=head)
{
  if(item!=cur->info)
  cur=cur->rlink;
  else
 {
  count++;
  prev=cur->llink;
  next=cur->rlink;
  prev->rlink=next;
  next->llink=prev;
  freenode(cur);
  cur=next;
 }
}
if(count==0)
  printf("key not found");
else
  printf("key found at %d positions and are deleted\n", count);

return head;
}
void Search_info(int item,NODE head){
NODE cur;
if(head->rlink==head)
{
printf("list empty\n");
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)
{
    printf("Search Successfull\n");
    break;
}
cur=cur->rlink;
}
if(cur==head)
{
 printf("Info not found\n");
 }
}
void display(NODE head)
{
NODE temp;
if(head->rlink==head)
{
printf("list empty\n");
return;
}
for(temp=head->rlink;temp!=head;temp=temp->rlink)
printf("%d\n",temp->info);
}
void main()
{
int item,choice,key;
NODE head;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;)
{
printf("\n1.insert_rear\n2.insert_key_left\n3.insert_key_right\n4.delete_duplicates\n5.Searh_info\n6.display\n7.exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item\n");
		 scanf("%d",&item);
		 head=insert_rear(head,item);
		 break;
  case 2:printf("enter the key item\n");
		 scanf("%d",&item);
		 head=insert_leftpos(item,head);
		 break;
  case 3:printf("enter the key item\n");
		 scanf("%d",&item);
		 head=insert_righttpos(item,head);
		 break;
  case 4:printf("enter the key item\n");
		 scanf("%d",&item);
		 head=delete_all_key(item,head);
		 break;
  case 5:printf("enter the key item\n");
		 scanf("%d",&item);
		 Search_info(item,head);
		 break;
  case 6:display(head);
		 break;
  default:exit(0);
		  break;
  }
 }
}
