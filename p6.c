#include <stdio.h>
#define MAX 6
int front = 0, rear = 0;
char q[MAX];
void insert()
{
    char item;
    if (front == (rear + 1) % MAX)
    {
        printf("\n Circular Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    printf("\n Enter the character to be inserted: ");
    scanf(" %c", &item);
    q[rear] = item;
}
void delete()
{
    if (front == rear)
    {
        printf("\n Circular Queue Underflow\n");
        return;
    }
    front = (front + 1) % MAX;
    printf("\n Deleted character is: %c ", q[front]);
}
void display()
{
    int i;
    if (front == rear)
    {
        printf("\nCircular Queue is Empty\n");
        return;
    }
    printf("\n Contents of Queue:\n");
    for (i = (front + 1) % MAX; i != rear; i = (i + 1) % MAX)
        printf("%c\t", q[i]);
    printf("%c\t", q[i]);
}
void main()
{
    int choice;
    while (1)
    {
        printf("\n CIRCULAR QUEUE OPERATIONS");
        printf("\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("\n Invalid Choice \n");
        }
    }
}