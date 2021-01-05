#include<stdio.h>
#include<stdlib.h>
int stack[5];
void push(void);
void pop(void);
void display(void);
int n,top,no,i,ch;
int main()
{
    top=-1;
    printf("\n Enter the size of stack:");
    scanf("%d",&n);
    printf("\n select ur choice:");
    printf("\n 1.Push\n 2.Pop\n 3.display\n 4.exit");
    while(ch!='0')
    {
        printf("\n Enter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
            {
                printf ("\nINVALID CHOICE!");
            }

        }
    }

    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\nSTACK OVERFLOW");

    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&no);
        top++;
        stack[top]=no;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n UNDERFLOW");
    }
    else
    {
        printf("\n The popped element is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in stack are as follows: \n");
        for(i=top;i>=0;i--)
            printf("\t%d,",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The stack is empty");
    }

}
