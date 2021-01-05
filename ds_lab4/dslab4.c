#include<stdio.h>
#include<conio.h>
#include<process.h>
#define QUE_SIZE 3
int item,front=0,rear=-1,q[QUE_SIZE],count=0;
 void insertrear(){
   if(count==QUE_SIZE){
    printf("***QUEUE OVERFLOW***\n");
    return;
   }
   rear=(rear+1)%QUE_SIZE;
   q[rear]=item;
   count++;
 }
 int deletefront(){
    if(count==0) return -1;
    item=q[front];
    front=(front+1)%QUE_SIZE;
    count--;
    return item;
 }
void display(){
    if(count==0){
        printf("QUEUE IS EMPTY");
        return;
    }
    printf("CONTENTS OF QUEUE ARE :\n");
    for(int i=1;i<=count;i++){
        printf("%d\n",q[front]);
        front=(front+1)%QUE_SIZE;
    }
}
void main(){
   int choice;
   printf("-----THIS IS CIRCULAR QUEUE-----\n");
   for(;;){
    printf("\n1:INSERT_REAR\n2:DELETE_FRONT\n3:DISPLAY\n4:****EXIT****\n");
    printf("ENTER UR CHOICE\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:printf("ENTER ITEM TO BE INSERTED\n");
             scanf("%d",&item);
             insertrear();
      break;
      case 2:item=deletefront();
             if(item==-1){
                printf("***QUEUE IS EMPTY***");
             }
             else{
                printf("ITEM DELETED =%d\n",item);}

      break;
      case 3:display();
      break;
      default : exit (0);
    }
   }
}
