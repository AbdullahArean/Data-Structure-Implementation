
# Linked List Implementation In C/C++

C/C++ implementation for (Singly) Linked List is here. Learn the concepts
with implemented codes and clear your doubts on this topic. Reusing this templates 
for many application of Linked List including Competitive programming. 
Where STL use is restricted, simply use the pre-implemented class or structure from here. Simple, Compact, and brilliantly named variables and function 
name will make your life easier. Happy Coding!

## Features

- Simple Codes
- Easy to understand 
- Wise naming of variables and functions 
- Effective reuse of codes is possible in any case


## Classes & Functions
### 1. Node Class
"Node" Class is used in the entire code to store "data" and link of the "next" pointer to the node and "previous" pointer is used to point at the previous node .
"previous" pointer is not used in singly classes and remains comment out.
    
    class Node 
    { 
        public:
	        int data;
            Node *next;
            Node *previous;             //Comment out in singly
	        Node()
	        {
		        data = 0;
		        next = NULL;
                previous = NULL;        //Comment out in singly
	        }
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
                this->previous = NULL;  //Comment out in singly
	        }
    };
### 2. LinkedList Class
LinkedList Class uses Object Oriented Programming Concept of Encapsulation as two key variables are kept Private. 
"LinkedListHead" is the main node pointing to the first node of the LinkedList. To know the LinkedList Length in O(1) a variable named   
"LengthOfLinkedList" is used. A Constructor is used to easily construct and use Linked List. "Public" Functions have the same works as it names suggest. No ambiguity, No tension.
It is to remembered that position of this LinkedList is counted from 0


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
    };

## Optimizations
Working to make the code more optimized, if you want to contribute, welcome!
