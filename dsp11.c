#include <stdio.h>
#include <stdlib.h>

int adjMatrix[50][50];
int n;
int isVisited[50];

int queue[20], front = -1, rear = -1;
int stack[20], top = -1;

void bfs(int startVertex)
{
    int i, currentVertex;

    isVisited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear)
    {
        currentVertex = queue[++front];

        for (i = 1; i <= n; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && isVisited[i] == 0)
            {
                queue[++rear] = i;
                isVisited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int startVertex)
{
    int i;

    isVisited[startVertex] = 1;
    stack[++top] = startVertex;

    for (i = 1; i <= n; i++)
    {
        if (adjMatrix[startVertex][i] == 1 && isVisited[i] == 0)
        {
            printf("%d ", i);
            dfs(i);
        }
    }
}

int main()
{
    int choice, startVertex, i, j;

    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        isVisited[i] = 0;

    printf("\nEnter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
    printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
    printf("\n==>3:Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nNodes reachable from starting vertex %d are: ", startVertex);
        bfs(startVertex);

        for (i = 1; i <= n; i++)
        {
            if (isVisited[i] == 0)
                printf("\nThe vertex that is not reachable is %d", i);
        }
        break;

    case 2:
        printf("\nNodes reachable from starting vertex %d are:\n", startVertex);
        dfs(startVertex);
        break;

    case 3:
        exit(0);

    default:
        printf("\nPlease enter valid choice:");
    }
}
