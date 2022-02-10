#include <iostream>
using namespace std;
class Node
{
public:
	int data;
    Node *next;
    Node *previous; 
	Node()
	{
		data = 0;
		next = NULL;
        previous = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
        this->previous = NULL;
	}
};
class LinkedList
{
private:
	Node *LinkedListHead;
	int LengthOfLinkedList;
public:
    LinkedList();
    int Length();
    void InsertNode(int data, int position);
    void PrintList()
    Node *ReturnLinkedListHead()
	LinkedList()
	{
		LinkedListHead = NULL;
		LengthOfLinkedList = 0;
	}  
	int Length()
	{
		return this->LengthOfLinkedList;
	}
	void InsertNode(int data, int position)
	{
		Node *newNode = new Node(data);
        if(position<0) printf("Invalid Position!\n");
		else if (LinkedListHead == NULL)
		{
			newNode->next = NULL;
			LinkedListHead = newNode;
		}
		else if (position == 0)
		{
			newNode->next = LinkedListHead;
			LinkedListHead = newNode;
		}
		else
		{
			Node *temp = LinkedListHead;
			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					printf("Invalid Position!\n");
					return;
				}
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		LengthOfLinkedList++;
	}
	void PrintList()
	{
		Node *temp = LinkedListHead;
		if (LinkedListHead == NULL)
		{
			cout << "List is empty!" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void DeleteNode(int position)
	{
		Node *temp1 = LinkedListHead, *temp2 = NULL;
		if (this->LengthOfLinkedList == 0)
		{
			cout << "List is empty!" << endl;
			return;
		}
		if (this->LengthOfLinkedList <= position)
		{
			cout << "Invalid Position!"<< endl;
			return;
		}
		if (position == 0)
		{
			LinkedListHead = LinkedListHead->next;
			delete temp1;
			return;
		}
		while (position-- > 0)
		{

			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;

		delete temp1;
		this->LengthOfLinkedList--;
		return;
	}
	Node *ReturnLinkedListHead() {return LinkedListHead;}
};
int main()
{
	return 0;
}
