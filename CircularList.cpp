#include <iostream>
using namespace std;

class CDNode
{
private:
    int data;
    CDNode* next, * prev;

    friend class CircularDoublyLinkedList;
};

class CircularDoublyLinkedList
{
private:
    CDNode* head;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    bool insertAtHead(int value)
    {
        CDNode* newNode = new CDNode;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            CDNode* lastNode = head->prev;
            newNode->next = head;
            newNode->prev = lastNode;
            head->prev = newNode;
            lastNode->next = newNode;
            head = newNode;
        }

        return true;
    }

    void Print()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            CDNode* curr = head;

            do
            {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);

            cout << endl;
        }
    }

    bool Search(int value)
    {
        if (head == nullptr)
        {
            return false;
        }

        CDNode* curr = head;
        do
        {
            if (curr->data == value)
            {
                return true;
            }
            curr = curr->next;
        } while (curr != head);

        return false;
    }

    bool Erase(int value)
    {
        if (head != nullptr)
        {
            CDNode* curr = head;
            do
            {
                if (curr->data == value)
                {
                    if (curr == head)
                    {
                        head = head->next;
                    }
                    CDNode* prevNode = curr->prev;
                    CDNode* nextNode = curr->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    delete curr;

                    return true;
                }
                curr = curr->next;

            } while (curr != head);
        }

        return false;
    }

    void printBack()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            CDNode* curr = head->prev;

            do
            {
                cout << curr->data << " ";
                curr = curr->prev;
            } while (curr != head->prev);

            cout << endl;
        }
    }

    bool insertAfter(int key, int value)
    {
        if (head != nullptr)
        {
            CDNode* curr = head;

            do
            {
                if (curr->data == key)
                {
                    CDNode* newNode = new CDNode;
                    newNode->data = value;
                    newNode->next = curr->next;
                    newNode->prev = curr;
                    curr->next->prev = newNode;
                    curr->next = newNode;

                    return true;
                }
                curr = curr->next;

            } while (curr != head);
        }

        return false;
    }

    ~CircularDoublyLinkedList()
    {
        while (head != nullptr)
        {
            CDNode* curr = head;
            head = head->next;
            delete curr;
        }
    }
};

void main()
{
Start:  CircularDoublyLinkedList List;

Menu: while (1)
{
    int choice;
    int choice2;

    system("CLS");
    cout << "Press 1: To Insert Value at Head." << endl;
    cout << "Press 2: To Insert after Specific Value." << endl;
    cout << "Press 3: To Erase Specific Value." << endl;
    cout << "Press 4: To Search Specific Value." << endl;
    cout << "Press 5: To Print List Forward." << endl;
    cout << "Press 6: To Print List Backward." << endl;
    cout << "Press 7: To Restart Program." << endl;
    cout << "Press 8: To Exit Program." << endl;
    cout << endl;
    cin >> choice;
    cout << endl;

choice1:   if (choice == 1)
{
    system("CLS");

    int Value;
    cout << "Enter Integer Value: " << endl;
    cin >> Value;
    List.insertAtHead(Value);

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cout << "-->Press 1: To Add more Values." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
        else if (choice2 == 1)
        {
            goto choice1;
        }
    } while (choice2 != 0);
}

choice2:   if (choice == 2)
{
    system("CLS");

    int Key, Value;
    cout << "Enter Integer Value to Insert: " << endl;
    cin >> Value;
    cout << "Enter Integer Value after which you wanna Insert: " << endl;
    cin >> Key;
    List.insertAfter(Key, Value);

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cout << "-->Press 1: To Add more Values." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
        else if (choice2 == 1)
        {
            goto choice2;
        }
    } while (choice2 != 0);
}

choice3:    if (choice == 3)
{
    system("CLS");

    int Value;
    cout << "Enter Integer Value to Remove: " << endl;
    cin >> Value;

    if (List.Erase(Value) == true)
    {
        cout << "Value Deleted Successfully!" << endl;
    }

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cout << "-->Press 1: To Remove more Values." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
        else if (choice2 == 1)
        {
            goto choice3;
        }
    } while (choice2 != 0);
}

choice4:    if (choice == 4)
{
    system("CLS");

    int Value;
    cout << "Enter Integer Value to Find: " << endl;
    cin >> Value;

    if (List.Search(Value) == true)
    {
        cout << "Value Found Successfully!" << endl;
    }
    else
        cout << "Value not Found!" << endl;

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cout << "-->Press 1: To Remove more Values." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
        else if (choice2 == 1)
        {
            goto choice4;
        }
    } while (choice2 != 0);
}

choice5:    if (choice == 5)
{
    system("CLS");

    List.Print();

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
    } while (choice2 != 0);
}

choice6:    if (choice == 6)
{
    system("CLS");

    List.printBack();

    do {
        cout << endl;
        cout << "-->Press 0: To Go Back to the Menu." << endl;
        cin >> choice2;
        if (choice2 == 0)
        {
            goto Menu;
        }
    } while (choice2 != 0);
}

if (choice == 7)
{
    goto Start;
}

if (choice == 8)
{
    exit(1);
}
}
}