// QueueAdt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};
class Queue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL;  
	}

	bool isEmpty()
	{
		return (front == NULL);
    }
	void Enqueue(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;
		if (isEmpty())
		{
			front = newnode;
			rear = newnode;
			rear->next = NULL;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
			newnode->next = NULL;
		}
	}
	void Display()
	{
		Node* temp = front;
		while (!isEmpty() && temp != NULL)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << endl;
	}
	int Dequeue()
	{
		int value;
		if (isEmpty())
		{
			cout << "Sorry , the queue is empty! \n";
		}
		else if (front->next == NULL)
		{
			value = front->data;
			front = NULL;
			return value;
		}
		else 
		{
			Node* delptr = front;
			value = front->data;
			front = front->next;
			delete delptr;
			return value;
		}
		
	}
	int getFront()
	{
		return front->data;
	}
	int getRear()
	{
		return rear->data;
	}
	int Count()
	{
		int count = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	bool isFound(int key)
	{
		bool found = false;
		Node* temp = front;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				found = true;
			}
			temp = temp->next;
		}
		return found;
	}
	void Clear()
	{
		Node* temp = front;
		while (!isEmpty())
		{
			Dequeue();
	    }
	}
};
int main()
{
	Queue q;
	int x;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a number to add to the Queue \n";
		cin >> x;
		q.Enqueue(x);
    }
	q.Display();
    q.Clear();
	cout << " the Queue has been cleared\n";
	q.Display();
}

