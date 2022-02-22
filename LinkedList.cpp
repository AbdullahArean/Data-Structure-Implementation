#include <iostream>
using namespace std;
class Node
{
public:
	int data;
    Node *next;
    //Node *previous; 
	Node()
	{
		data = 0;
		next = NULL;
        //previous = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
        //this->previous = NULL;
	}
};
class LinkedList
{
private:
	Node *LinkedListHead;
	int LengthOfLinkedList;
	Node 	*ReverseRecursion(Node *current)
	{

		if (current == NULL || current->next == NULL)
			return current;
		Node *newhead = ReverseRecursion(current->next);
		current->next->next = current;
		current->next = NULL;
		return newhead;
	}
	Node 	*ReverseIterative(Node *current)
	{
		Node *prev = NULL, *next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		return prev;
	}
	
public:
				LinkedList()
	{
		LinkedListHead = NULL;
		LengthOfLinkedList = 0;
	}
				LinkedList(Node *head)
	{
		this->LinkedListHead = head;
	}
	int 		Length()
	{
		return this->LengthOfLinkedList;
	}
	void 		InsertNode(int data, int position)
	{
		Node *newNode = new Node(data);
		if (position < 0)
			printf("Invalid Position!\n");
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
	void 		PrintList()
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
	void 		deleteNode(int position) 
{ 
   // If linked list is empty 
   if (this->LinkedListHead == NULL) 
      return; 
  
   // Store head node 
    Node* temp = this->LinkedListHead; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        this->LinkedListHead = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
}   
	Node 		*ReturnLinkedListHead() 
	{ return LinkedListHead; }
	void 		Reverse()
	{
		this->LinkedListHead = ReverseIterative(this->LinkedListHead);
		//this->LinkedListHead = ReverseRecursion(this->LinkedListHead);

	}
};
int main()
{
	return 0;
}
