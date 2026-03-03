#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
    int val;
    struct Node_* next;
} Node;

typedef struct Queue_
{
    Node* front;
    Node* rear;
} Queue;

Queue QueueInit()
{
    Queue tmp;
    tmp.front = NULL;
    tmp.rear = NULL;
    return tmp;
}

int QueueEmpty(Queue* q)
{
    return !q->front;
}

void Enqueue(Queue* q, int a)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = a;
    node->next = NULL;
    if (QueueEmpty(q))
    {
        q->front = q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}

int Dequeue(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Cannot dequeue, its empty\n");
        return 0;
    }

    Node* tmp = q->front;
    q->front = tmp->next;
    if (!q->front)
    {
        q->rear = NULL;
    }
    int out = tmp->val;
    free(tmp);
    return out;
}

int PeekFront(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Cannot get front, its empty\n");
        return 0;
    }
    return q->front->val;
}

int PeekRear(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Cannot get rear, its empty\n");
        return 0;
    }
    return q->rear->val;
}

void PrintQueue(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Cannot print queue, its empty\n");
        return;
    }

    printf("%i <- front\n", q->front->val);
    Node* tmp = q->front->next;
    while (tmp)
    {
        if (!tmp->next)
        {
            printf("%i <- rear\n", tmp->val);
            break;
        }
        printf("%i\n", tmp->val);
        tmp = tmp->next;
    }
}

void QueueFree(Queue* q)
{
    while (q->front)
    {
        Node* tmp = q->front;
        q->front = tmp->next;
        free(tmp);
    }
}


int main()
{
    Queue line = QueueInit();
    
    Enqueue(&line, 400);
    Enqueue(&line, 500);
    Enqueue(&line, 600);
    Enqueue(&line, 700);

    PrintQueue(&line);

    int out = Dequeue(&line);
    printf("\n%i <- dequeue'd\n\n", out);

    PrintQueue(&line);
    
    QueueFree(&line);
}

