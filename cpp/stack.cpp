// fix the Stack() constructor

#include <iostream>
#include <vector>

class Node
{
public:
    int val;
    Node* bot;
    Node() : val(0), bot(nullptr) {}
    Node(int x) : val(x), bot(nullptr) {}
    Node(int x, Node* y) : val(x), bot(y) {}
};

class Stack
{
public:
    Node* top;
    Stack()
    {
        this->top = nullptr;
    }

    Stack(int* x, int size)
    {
        this->top = nullptr;
        if (!x)
            return;
        for (int i = 0; i < size; i++)
        {
            this->Push(x[i]);
        }
    }

    void Push(int x)
    {
        Node* node = new Node(x, this->top);
        this->top = node;
    }

    int Pop()
    {
        if (!this->top)
            return -1;
        Node* tmp = this->top;
        this->top = tmp->bot;
        int out = tmp->val;
        delete tmp;
        return out;
    }

    void Print()
    {
        if (!this->top)
            return;
        std::cout << this->top->val << " <- top\n";
        Node* node = this->top->bot;
        while (node)
        {
            std::cout << node->val << '\n';
            node = node->bot;
        }
    }

    ~Stack()
    {
        while (this->top)
        {
            Node* tmp = this->top;
            this->top = tmp->bot;
            delete tmp;
        }
    }
};

int main()
{
    int buffer[] = { 400, 500, 600 };
    Stack stack(buffer, sizeof(buffer) / sizeof(buffer[0]));
    stack.Push(750);
    stack.Print();
    int out = stack.Pop();
    std::cout << '\n' << out << " <- popped\n\n";
    stack.Print();

}