#include<iostream>
using namespace std;

class Node
{
	int data;
	Node* next;

	friend class LinkedList;
};

class LinkedList
{
	Node* head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	bool insertAtStart(int val)
	{
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
		return true;
	}

	bool deleteFromStart()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			Node* Start = head;
			head = head->next;
			delete Start;
			return true;
		}
	}

	bool insertAtEnd(int val)
	{
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return true;
		}
		else
		{
			Node* Curr = head;
			while (Curr->next != nullptr)
			{
				Curr = Curr->next;
			}

			Curr->next = newNode;
			return true;
		}
	}

	bool deleteFromEnd()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			Node* Curr = head, * Prev = nullptr;
			while (Curr->next != nullptr)
			{
				Prev = Curr;
				Curr = Curr->next;
			}

			if (Prev == nullptr)
			{
				head = nullptr;
			}
			else
			{
				Prev->next = nullptr;
			}

			delete Curr;
			Curr = nullptr;
			return true;
		}
	}

	bool insertAfterSpecificValue(int Sval, int Nval)
	{
		Node* newNode = new Node;
		newNode->data = Nval;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return true;
		}

		else
		{
			Node* Curr = head;
			while (Curr != nullptr)
			{
				if (Curr->data == Sval)
				{
					newNode->next = Curr->next;
					Curr->next = newNode;
					return true;
				}
			}
			return false;
		}
	}

	bool ReverseList()
	{
		if (head == nullptr)
		{
			return false;
		}
		else if (head->next == nullptr)
		{
			return false;
		}
		else
		{
			Node* Curr = head, * Next = nullptr, * Prev = nullptr;
			while (Curr != nullptr)
			{
				Next = Curr->next;
				Curr->next = Prev;
				Prev = Curr;
				Curr = Next;
			}
			head = Prev;
			return true;
		}
	}

	Node* reverseList(Node* current, Node* prev = nullptr) {
		if (current == nullptr) {
			head = prev;
			return head;
		}

		Node* nextNode = current->next;
		current->next = prev;

		return reverseList(nextNode, current);
	}
	obj.reverseList(head);

	bool SortList()
	{
		if (head == nullptr)
		{
			return false;
		}
		else if (head->next == nullptr)
		{
			return false;
		}
		else
		{
			Node* Curr = head;
			Node* Next = nullptr;
			while (Curr->next->next != nullptr)
			{
				Next = Curr->next;
				while (Next->next != nullptr)
				{
					if (Next->data < Curr->data)
					{
						swap(Next->data, Curr->data);
					}
				}
				Curr = Curr->next;
			}
		}
	}

	void Display()
	{
		if (head == nullptr)
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			Node* Curr = head;
			while (Curr != nullptr)
			{
				cout << Curr->data << " ";
				Curr = Curr->next;
			}
			cout << endl;
		}
	}

	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* Curr = head;
			head = head->next;
			delete Curr;
		}
	}
};