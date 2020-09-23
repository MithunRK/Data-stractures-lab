#include<stdio.h>

int push(int top, int n, int s[n])
{
	int item;
	if (top>=n-1)
	{
		printf("\nStack Overflow");
		return 0;
	}
	printf("\nEnter the item:	");
	scanf("%d", &item);
	s[++top] = item;
	return 1;
}

int pop(int top, int n, int s[n])
{
	if(top>=0)
	{
		printf("\n%d", s[top]);
		return 1;
	}
	printf("\nStack Underflow");
	return 0;
}


void display(int top, int n, int s[n])
{
	if (top<0)
	{
		printf("Empty stack");
		return;
	}
	for(int i=0; i<=top; i++)
		printf("%d\t", s[i]);
	printf("\nthe contents of the stack:-");
}



int main()
{
	int n;
	printf("Enter the size of stack:");
	scanf("%d", &n);
	int s[n];
	int top =-1;
	int ch = 10;
	while(ch!=4)
	{
		printf("\nStacks Implementation");
		printf("\n1:Push\n2:Pop\n3:Display\n4:EXIT\nChoice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:if(push(top, n, s))
			top++;
			break;
		case 2:if(pop(top, n, s))
			top--;
			break;
		case 3:display(top, n, s);
			break;
		case 4:break;
		default: printf("\n\tInvalid choice");
		}
	}
	return 0;
}
