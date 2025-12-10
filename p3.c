/* 3. Design, Develop and Implement a menu driven Program in C for the
following operations
on STACK of Integers (Array Implementation of Stack with maximum size
MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit.
Support the program with appropriate functions for each of the above
operations */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int item;
    if (top == (MAX - 1))
        printf("\n Stack Overflow");
    else
    {
        printf("\n Enter the element to be pushed :");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

void pop()
{
    if (top == -1)
        printf("\n Stack Underflow");
    else
        printf("\nPoped element is %d ", stack[top--]);
}

void display()
{
    int i;
    if (top == -1)
        printf("\n Sorry Empty Stack");
    else
    {
        printf("\nThe elements of the stack are\n");
        for (i = top; i >= 0; i--)
            printf("stack[%d] = %d\n", i, stack[i]);
    }
}

void palindrome()
{
   for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            printf("\nStack contents are not palindrome");
            return;
        }
    }
    printf("\nStack contents are Palindrome");
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n STACK OPERATIONS\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
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
            palindrome();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}
