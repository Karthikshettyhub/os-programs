#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct node {
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

/* Create a node */
NODE getnode() {
    NODE node = (NODE)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Create BST */
NODE create(int item, NODE root) {
    NODE newNode = getnode();
    NODE current = root;
    NODE parent = NULL;

    newNode->value = item;

    if (root == NULL)
        return newNode;

    while (current != NULL) {
        parent = current;
        if (item < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (item < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}


/* Inorder traversal */
void in(NODE root) {
    if (root != NULL) {
        in(root->left);
        printf("%d\t", root->value);
        in(root->right);
    }
}

/* Preorder traversal */
void pre(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->value);
        pre(root->left);
        pre(root->right);
    }
}

/* Postorder traversal */
void post(NODE root) {
    if (root != NULL) {
        post(root->left);
        post(root->right);
        printf("%d\t", root->value);
    }
}

/* Search in BST */
void search(NODE root) {
   
    int item;

    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }


    NODE current;

    printf("Enter the element to be searched\n");
    scanf("%d", &item);

    current = root;
    while (current != NULL) {
        if (item == current->value) {
            printf("Found key %d in tree\n", item);
            return;
        } else if (item < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    printf("Key not found\n");
}

/* Main */
void main() {
    int choice, item, n, i;
    NODE root = NULL;

    while (1) {
        printf("\n1. Create BST of N Integers");
        printf("\n2. BST Traversal");
        printf("\n3. Binary Search");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter the item to be inserted\n");
                    scanf("%d", &item);
                    root = create(item, root);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("\nPREORDER traversal\n");
                    pre(root);
                    printf("\n\nINORDER traversal\n");
                    in(root);
                    printf("\n\nPOSTORDER traversal\n");
                    post(root);
                }
                break;

            case 3:
                search(root);
                break;

            case 4:
                return;

            default:
                printf("Invalid Choice\n");
        }
    }
}
