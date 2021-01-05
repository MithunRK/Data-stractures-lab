#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
struct node{
int info;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("MEMORY IS FULL\n");
exit(0);
}
else
return x;
}
NODE insertfront(NODE first,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
{
return temp;
}
temp->link=first;
first=temp;
return first;
}
NODE insertrear(NODE first,int item)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
{
return temp;
}
cur=first;
while(cur->link != NULL)
{
cur=cur->link;
}
cur->link=temp;
return first;
}
NODE deletefront(NODE first)
{
NODE cur;
if(first==NULL)
{
printf("THE LIST IS EMPTY\n");
return first;
}
cur=first;
cur=cur->link;
printf("THE DELETED ITEM FROM FRONT IS=%d\n",first->info);
free(first);
return cur;
}
NODE deleterear(NODE first)
{
NODE prev,cur;
if(first==NULL)
{
printf("THE LIST IS EMPTY\n");
return first;
}
if(first->link==NULL)
{
printf("ITEM DELETED IS=%d\n",first->info);
free(first);
return NULL;
}
prev=NULL;
cur=first;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
printf("THE DELETED ITEM FROM REAR IS=%d\n",cur->info);
free(cur);
prev->link=NULL;
return first;
}
void display(NODE first)
{
NODE temp;
if(first==NULL){
printf("THE LIST IS EMPTY\n");
}
printf("THE ELEMENTS ARE=");
for(temp=first;temp!=NULL;temp=temp->link)
{
printf("%d\t",temp->info);
}
printf("\n");
}
int main()
{
int c,item,pos;
int n,i;
int choice;
NODE first=NULL,sec,fir;
for(;;)
{
printf(" 1-STACK \n 2-QUEUE \n 3-EXIT\n");
printf("ENTER THE CHOICE\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("STACK\n");
 for(;;)
 {
 printf("\n 1:Insert_rear\n 2:Delete_rear\n 3:Display_list\n 4:Exit\n");
 printf("Enter the choice\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter the item at rear-end\n");
 scanf("%d",&item);
 first=insertrear(first,item);
 break;
 case 2:first=deleterear(first);
 break;
 case 3:display(first);
 break;
 default:exit(0);
 }
 }
 break;
 case 2:
 printf("QUEUE\n");
 for(;;)
 {
 printf("\n 1:Insert_rear\n 2:Delete_front\n 3:Display_list\n 4:Exit\n");
 printf("Enter the choice\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter the item at rear-end\n");
 scanf("%d",&item);
 first=insertrear(first,item);
 break;
 case 2:first=deletefront(first);
 break;
 case 3:display(first);
 break;
 default:exit(0);
 break;
 }
 }
 break;
 case 3:
 exit(0);
 default:
 printf("INVALID CHOICE\n");
}
}
}
