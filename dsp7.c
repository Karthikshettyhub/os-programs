#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    char usn[20], name[10], branch[5];
    int sem, phno;
    struct node *next;
};

typedef struct node* NODE;

/* Head pointer */
NODE head = NULL;

/* Create a node */
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    x->next = NULL;
    return x;
}

/* Read student details */
NODE read() {
    NODE newNode = getnode();

    printf("Enter USN:\n");
    scanf("%s", newNode->usn);

    printf("Enter NAME:\n");
    scanf("%s", newNode->name);

    printf("Enter Branch:\n");
    scanf("%s", newNode->branch);

    printf("Enter Semester:\n");
    scanf("%d", &newNode->sem);

    printf("Enter phno:\n");
    scanf("%d", &newNode->phno);

    return newNode;
}

/* Create SLL using front insertion */
void create_SLL() {
    int n, i;
    NODE newNode;

    printf("Enter the number of students\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\nEnter the details of student %d\n", i);
        newNode = read();

        if (head == NULL)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
}

/* Display list and count */
void display_count() {
    NODE current = head;
    int count = 1;

    if (head == NULL) {
        printf("Student detail is NULL and count is 0\n");
        return;
    }

    printf("USN\tNAME\tBRANCH\tSEM\tPHNO\n");

    while (current->next != NULL) {
        
        printf("%s\t%s\t%s\t%d\t%d\n",
               current->usn, current->name,
               current->branch, current->sem,
               current->phno);
        current = current->next;
        count++;
    }

    printf("%s\t%s\t%s\t%d\t%d\n",
           current->usn, current->name,
           current->branch, current->sem,
           current->phno);

    printf("Total node count is %d\n", count);
}

/* Insert at front */
void insert_front() {
    NODE newNode;

    printf("Enter the details of student\n");
    newNode = read();

    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
}

/* Insert at end */
void insert_end() {
    NODE newNode, last;

    printf("Enter the details of student\n");
    newNode = read();

    if (head == NULL) {
        head = newNode;
        return;
    }

    last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

/* Delete from front */
void delete_front() {
    NODE del;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    del = head;
    head = head->next;
    printf("Deleted element is %s\n", del->usn);
    free(del);
}

/* Delete from end */
void delete_end() {
    NODE current = head, prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted element is %s\n", head->usn);
        free(head);
        head = NULL;
        return;
    }

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    printf("Deleted element is %s\n", current->usn);
    free(current);
}

/* Main */
void main() {
    int choice;

    while (1) {
        printf("\n1.Create SLL\n2.Display SLL\n3.Insert front\n4.Insert end\n");
        printf("5.Delete front\n6.Delete end\n7.Exit\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_SLL(); break;
            case 2: display_count(); break;
            case 3: insert_front(); break;
            case 4: insert_end(); break;
            case 5: delete_front(); break;
            case 6: delete_end(); break;
            case 7: return;
            default: printf("Invalid choice\n");
        }
    }
}
