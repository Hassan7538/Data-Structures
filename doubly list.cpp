#include<iostream>
#include<cstdlib>
using namespace std;

class DoublyLinkedList;

class DNode
{
	int data;
	DNode* next, *prev;
	friend class DoublyLinkedList;
};

class DoublyLinkedList
{
	DNode* head;
public:
	DoublyLinkedList() {
		head = nullptr;
	}

	~DoublyLinkedList() 
	{
		while (head != nullptr)
		{
			DNode* curr = head;
			head = head->next;
			delete curr;
			curr = head;
		}
	}

	bool insertAtStart(int val) {
		DNode* temp = new DNode;
		temp->data = val;
		temp->next = head;
		temp->prev = nullptr;
		if (head != nullptr)  // if head != 0
			temp->next->prev = temp;  // Place temp info in the previous block of the node which be
		head = temp;
		
		return true;
	}

	bool insertAtEnd(int val) {
		DNode* temp = new DNode;
		temp->data = val;
		temp->next = nullptr;
		if (head == nullptr) 
		{
			head = temp;
			return true;
		}
		else
		{
			DNode* curr = head;
			while (curr->next != 0)
				curr = curr->next;

			temp->prev = curr;
			curr->next = temp;
			return true;
		}
	}

	bool sortedInsert(int val)//if list has 1, 2, 4 and 3 is the new value to insert then you have to insert the node having value 3 before node having value 4
	{
		  // if list is empty insert a start
		if (head == nullptr)
		{
			insertAtStart(val);
			return true;
		}
		 // if val is less than head-> data ; then also insert at start
		else if (val < head->data)
		{
			insertAtStart(val);
			return true;
		}
		else
		{
			DNode* curr = head;
			DNode* temp = new DNode;
			temp->data = val;
			while (curr!=nullptr)
			{
				if (curr->next == nullptr || curr->next->data > val)
				{
					temp->next = curr->next;
					temp->prev = curr;
					if (curr->next != nullptr) {
						curr->next->prev = temp;
					}
					curr->next = temp;
					return true;
				}
				curr = curr->next;
			}
		}
	}

	bool deleteFromStart() {
		DNode* temp = new DNode;
		temp = head;
		temp->next->prev = nullptr;
		head = temp->next;
		delete temp;
		return true;
	}

	bool deleteFromEnd()
	{
		if (head == nullptr) {
			cout << "List is empty\n";
			return false;
		}
		DNode* curr = head, * last = nullptr, * secondlast = nullptr;
		while (curr != nullptr) {
			secondlast = last;
			last = curr;
			curr = curr->next;
		}
		if (secondlast == nullptr) {
			head = nullptr;
		}
		else {
			secondlast->next = nullptr;
			last->prev = nullptr;
			delete last;
			last = nullptr;
		}
		return true;
	}


	DNode* Search(int val)//if value found then this function returns the address of that node otherwise it will return 0
	{
		if (head == nullptr)
		{
			cout << "Your list is empty" << endl;
			return nullptr;
		}
		else
		{
			DNode* curr = head;
			while (curr!=nullptr)
			{
				if (curr->data == val)
					return curr;
				curr = curr->next;
			}
			cout << "You have not inserted this value" << endl;
			return nullptr;
		}

	}
	
	bool delectSpecificValue(int valToDelete) {
		if (head == nullptr) {
			cout << "Your list is empty" << endl;
			return false;
		}
		else {
			DNode* curr = head;

			while (curr != nullptr)
			{
				if (curr->data == valToDelete)
				{
					if (curr == head)
					{
						// If the value to deleted is first value of the list
						head = curr->next;
						if (head != nullptr) 
						{
							head->prev = nullptr;
						}
					}
					else 
					{
						curr->prev->next = curr->next;

						if (curr->next != nullptr)   // if we are deleting last value
							curr->next->prev = curr->prev;

					}
					delete curr;
					return true;
				}
				curr = curr->next;
			}
			cout << "Number is not present in your list" << endl;
			return false;
		}
	}


	void display() {
		if (head == nullptr)
			cout << "List is Emty";
		else {
			DNode* curr = head;
			while (curr!=0)
			{
				cout << curr->data << "  ";
				curr = curr->next;
			}
		}
	}
};

void main() {

	int num, n;

	DoublyLinkedList a;

	cout << "How many elements you want to enter at start to make list (elements will be inserted at start) : ", cin >> n, cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " element : ", cin >> num;
		a.insertAtStart(num);
	}
	cout << endl << "\n\tYour enetered list is : ";
	a.display();

	cout << endl << endl;

	//cout << "Press:\n\t'1' for \"insert at start\"\n"
	//	 <<"\t'2' for \"insert at end\"\n"
	//	 <<"\t'3' for \"sorted insert\"\n"
	//	 <<"\t'4' for \"search value address\"\n"
	//	 <<"\t'5' for \"delete from start start\"\n";

	cout << "\n\n\nHow many elements you want to enter at start : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\tenter the element : ", cin >> num;
		a.insertAtStart(num);
	}
	cout << endl << "\tlist is : ";
	a.display();

	cout << "\n\n\nHow many elements you want to enter at end : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\tenter the element : ", cin >> num;
		a.insertAtEnd(num);
	}
	cout << endl << "\tlist is : ";
	a.display();

	cout << "\n\n\nHow many elements you want to insert sorted : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\tenter the element : ", cin >> num;
		a.sortedInsert(num);
	}
	cout << endl << "\tSorted inserted list is : ";
	a.display();

	cout << "\n\n\nHow many elements you want to delete from start : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		a.deleteFromStart();
	}
	cout << endl << "\tAfter element deletion from start; list is : ";
	a.display();

	cout << "\n\n\nHow many elements you want to delete from end : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		a.deleteFromEnd();
	}
	cout << endl << "\tAfter element deletion from end; list is : ";
	a.display();

	cout << "\n\n\nHow many specific elements you want to delete : ", cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter " << i + 1 << " value : ", cin >> num;
		a.delectSpecificValue(num);
	}
	cout << endl << "\tlist sfter specific value deletion is : ";
	a.display();
	
	cout << "\n\n\nEnter element of which you want to find address :  ", cin >> num;
	DNode* address = a.Search(num);
	cout << "Address : " << address;
	if (address != nullptr)
	{
		delete address;
		address = nullptr;
	}

	cout << endl << endl << endl;
}