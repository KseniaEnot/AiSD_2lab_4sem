#pragma once
#include <iostream>
template <class T>
class PriorityQueue
{
private:
    class Node
    {
    public:
        Node(T content, int prior = 0, Node* before = NULL, Node* next = NULL)
        {
            this->content = content;
            this->priority = prior;
            this->before = before;
            this->next = next;
        };
        ~Node()
        {  }
        T content;
        int priority;
        Node* next;
        Node* before;
    private:

    };

    Node* head; //head list
    Node* tail;  //tail list
    size_t size;  //list size

public:
    PriorityQueue(Node* head = NULL, Node* tail = NULL) {
        this->head = head;
        this->tail = tail;
        size = 0;
    };
    void push(T, int); // add item to end
    size_t get_size(); // get list size
    T pop(); // delete first item
    int head_priority();
    void clear(); // clear list
    bool isEmpty(); // test for emptiness
    ~PriorityQueue()
    {
        while ((head != NULL)&&(head->next != NULL)) //while we can go next
        {
            head = head->next;
            delete head->before;
        }
        size = 0;
        delete head;
    };
};

