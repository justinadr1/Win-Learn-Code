#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node_
{
    struct Node_* bot;
    int val;
} Node;

typedef struct Stack_
{
    Node* top;
    int len;
} Stack;

void Push(Stack* s, int a) 
{
    Node* node = malloc(sizeof(Node));
    node->val = a;
    node->bot = s->top;
    s->top = node;
    s->len++;
}

int Pop(Stack* s)
{
    if (!s->top)
        return -1;
    Node* tmp = s->top;
    s->top = tmp->bot;
    int out = tmp->val;
    s->len--;
    free(tmp);
    return out;
}

void Print(Stack* s)
{
    if (!s->top)
        return;
    int len = s->len - 1;
    printf("%i: %i <- top\n", len--, s->top->val);
    Node* t = s->top->bot;
    for (int i = len; i >= 0; i--)
    {
        printf("%i: %i\n", i, t->val);
        t = t->bot;
    }
}

void Delete(Stack* s)
{
    while (s->top)
    {
        Node* t = s->top;
        s->top = t->bot;
        free(t);
    }
}

void Reverse(Stack* s)
{
    Node* prev = NULL;
    Node* curr = s->top;
    Node* next = NULL;
    while (curr)
    {
        next = curr->bot;
        curr->bot = prev;
        prev = curr;
        curr = next;
    }
    s->top = prev;
}


int main(int argc, char** argv)
{
    Stack stack;
    stack.top = NULL;
    stack.len = 0;
    Push(&stack, 500);
    Push(&stack, 200);
    Push(&stack, 300);
    Push(&stack, 100);
    Push(&stack, 400);
    
    Print(&stack);

    Reverse(&stack);
    printf("\n");
    Print(&stack);
    
    
    Delete(&stack); 
}
