#pragma once

#include <iostream>

using std::cout;
using std::endl;


//настроить добавление и удаление первого элемента
class Collection
{
private:
	struct Node
	{
		int data;
		Node* next;
	};

 
	Node* current;
	Node* head;
public:
	Collection(){
		
		head = NULL;
		current = NULL;
	}
	void add(int k)
	{
		if (head == NULL)
		{
			head = new Node;
			head->data = k;
			head->next = NULL;
			current = head;
		}
		else
		{
			current->next = new Node;
			current = current->next;
			current->data = k;
			current->next = NULL;
		}
	}

	void add_push(int k, int number)
	{
		current = head;
		Node* ins = new Node;
		if (number == 1)
		{
			ins->data = k;
			ins->next = head;
			head = ins;
		}
		else
		{
			for (int i(0); i < (number - 2); i++)
				current = current->next;

			Node* ins = new Node;
			ins->data = k;
			ins->next = current->next;
			current->next = ins;
		}
	}

	void remove_push(int number)
	{
		Node* additional = head;
		current = head;

		if (number == 1)
		{
			head = head->next;
			delete additional;
		}
		else {
			for (int i(0); i < (number - 2); i++)
			{
				current = current->next;
				additional = additional->next;
			}
			additional = additional->next;
			current->next = additional->next;
			delete additional;
		}
	}

	int search_index(int k)
	{
		int index = 0;
		current = head;
		while (current != NULL)
		{
			if (current->data == k)
				break;
			current = current->next;
			index++;
		}
		if ((index + 1) > count()) return -1;
		else return (index+1);
	}


	void print()
	{
		current = head;
		while (current != NULL)
		{
			cout << current->data << " -> ";
			current = current->next;
		}
	}


	int count()
	{
		current = head;
		int count = 0;
		while (current!=NULL)
		{
			current = current->next;
			count++;
		}
		return count;
	}


};
