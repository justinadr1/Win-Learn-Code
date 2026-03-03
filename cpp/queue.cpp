
#include <iostream>
#include <thread>
#include <bitset>

struct Node
{
    int val;
    Node* next;
    Node(int a) : val(a), next(nullptr) {}
};

struct Queue
{
    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    bool empty()
    {
        return !front;
    }

    void Enqueue(int a)
    {
        Node* node = new Node(a);
        if (empty())
        {
            front = rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }

    int Dequeue()
    {
        if (empty())
        {
            std::cout << "Queue is empty\n";
        }
        else
        {
            Node* tmp = front;
            front = tmp->next;
            int out = tmp->val;
            if (!front)
                rear = nullptr;
            delete tmp;
            return out;
        }
    }

    int PeekFront()
    {
        return front->val;
    }

    int PeekRear()
    {
        return rear->val;
    }

    void Print()
    {
        if (empty())
        {
            std::cout << "Queue is empty\n";
        }
        else
        {
            std::cout << front->val << " <- front\n";
            Node* tmp = front->next;
            while (tmp)
            {
                std::cout << tmp->val;
                std::cout << (tmp->next != nullptr ? "\n" : " <- rear\n");
                tmp = tmp->next;
            }
        }
    }

    ~Queue()
    {
        while(!empty())
        {
            Dequeue();
        }
    }
};


int main()
{
    Queue line;

    line.Enqueue(400);
    line.Enqueue(500);
    line.Enqueue(600);
    line.Enqueue(700);
    line.Print();
    
    std::cout << "\n";
    int out = line.Dequeue();
    std::cout << out << " <- dequeue'd\n\n";

    line.Print();
}

