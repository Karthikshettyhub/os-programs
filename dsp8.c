#include <stdio.h>
#include <stdlib.h>

/* Structure to store employee details */
struct node {
    char ssn[10], name[10], dept[15], desig[10];
    int phno, sal;
    struct node *prev;
    struct node *next;
};

typedef struct node* NODE;

/* Best-practice names */
NODE head = NULL;
NODE END  = NULL;

/* Create node */
NODE getnode() {
    NODE node = (NODE)malloc(sizeof(struct node));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* Read employee details */
NODE read() {
    NODE node = getnode();

    printf("Enter SSN: ");
    scanf("%s", node->ssn);

    printf("Enter Name: ");
    scanf("%s", node->name);

    printf("Enter Dept: ");
    scanf("%s", node->dept);

    printf("Enter Designation: ");
    scanf("%s", node->desig);

    printf("Enter Phno: ");
    scanf("%d", &node->phno);

    printf("Enter Salary: ");
    scanf("%d", &node->sal);

    return node;
}

/* Create DLL using end insertion */
void Create_DLL() {
    int n, i = 1;
    NODE node;

    printf("Enter the number of Employees\n");
    scanf("%d", &n);

    while (i <= n) {
        printf("Enter the details of the %d employee\n", i++);
        node = read();

        if (head == NULL) {
            head = node;
            END = node;
        } else {
            END->next = node;
            node->prev = END;
            END = node;
        }
    }
}

/* Display DLL and count */
void display_count() {
    NODE current = head;
    int count = 0;

    printf("Employee details:\n");

    if (head == NULL) {
        printf("The employee detail is NULL and count is 0\n");
        return;
    }

    while (current != NULL) {
        count++;
        printf("%s\t%s\t%s\t%s\t%d\t%d\n",
               current->ssn, current->name,
               current->dept, current->desig,
               current->phno, current->sal);
        current = current->next;
    }

    printf("Employee count is %d\n", count);
}

/* Insertion at front */
void Insertionfront() {
    NODE node = read();

    if (head == NULL) {
        head = node;
        END = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

/* Insertion at end */
void Insertionend() {
    NODE node = read();

    if (head == NULL) {
        head = node;
        END = node;
    } else {
        END->next = node;
        node->prev = END;
        END = node;
    }
}

/* Deletion at front */
void Deletionfront() {
    NODE del;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    del = head;
    printf("Deleted element is %s\n", del->ssn);

    if (head == END) {
        head = NULL;
        END = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(del);
}

/* Deletion at end */
void Deletionend() {
    NODE del;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    del = END;
    printf("Deleted element is %s\n", del->ssn);

    if (head == END) {
        head = NULL;
        END = NULL;
    } else {
        END = END->prev;
        END->next = NULL;
    }

    free(del);
}

/* Main */
void main() {
    int choice;

    while (1) {
        printf("\n1 - Create DLL of N Employees");
        printf("\n2 - Display DLL");
        printf("\n3 - Insertion at front");
        printf("\n4 - Insertion at end");
        printf("\n5 - Deletion at front");
        printf("\n6 - Deletion at end");
        printf("\n7 - Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Create_DLL(); break;
            case 2: display_count(); break;
            case 3: Insertionfront(); break;
            case 4: Insertionend(); break;
            case 5: Deletionfront(); break;
            case 6: Deletionend(); break;
            case 7: return;
            default: printf("Invalid Choice\n");
        }
    }
}
