#include "PriorityQueue.h"
#include <iostream>
using namespace std;

template <class T>
void PriorityQueue<T>::push(T add,int prior) // add item to end
{
	if (size == 0) //if list is empty
	{
		head = new Node(add, prior); //create head
		tail = head;
	}
	else
	{
		Node* newNod = new Node(add, prior);
		Node* cur = head;
		while ((newNod->priority < cur->priority)&&(cur->next != NULL))
		{
			cur = cur->next;
		}
		if ((newNod->priority <= cur->priority) && (cur->next == NULL)) {
			newNod->before = cur;
			newNod->next = NULL;
			cur->next = newNod;
			tail = newNod;
		}else if ((newNod->priority >= cur->priority) && (cur->before == NULL))
		{
			newNod->before = NULL;
			newNod->next = cur;
			cur->before = newNod;
			head = newNod;
		}
		else {
			newNod->next = cur;
			newNod->before = cur->before;
			cur->before->next = newNod;
			cur->before = newNod;

		}
	}
	size++;
}

template <class T>
size_t PriorityQueue<T>::get_size() // get list size
{
	return size;
}

template <class T>
T PriorityQueue<T>::pop() // delete first item
{
	T cont;
	if (size == 1)
	{
		cont = head->content;
		size = 0;  //setup zero position
		head = NULL;
		tail = NULL;
	}
	else if (size > 1) //if list is not empty
	{
		cont = tail->content;
		tail = tail->before; //set new head
		delete tail->next;
		tail->next = NULL;
		size--;
	}
	else //else return error
		throw out_of_range("Segmentation fault");
	return cont;
}

template <class T>
int PriorityQueue<T>::head_priority() {
	return head->priority;
}

template <class T>
void PriorityQueue<T>::clear() // clear list
{
	if (head != NULL)
	{
		while (head->next != NULL)  //delete all item
		{
			head = head->next;
			delete head->before;
		}
		size = 0;  //setup zero position
		head = NULL;
		tail = NULL;
	}
}

template <class T>
bool PriorityQueue<T>::isEmpty() // test for emptiness
{
	if (head == NULL)
		return true;
	return false;
}