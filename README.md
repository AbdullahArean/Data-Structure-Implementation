

# Data Structure Implementation
A data structure is a way of organizing the data so that it can be used efficiently. Here, we have used the word efficiently, which in terms of both the space and time. The Best way of learning about data structure is trying to implement it. In Competitive Programming majority of the problems require any of the well-known data structure or modified version of particular data structure.  So, In this repository, I tried to implement important data structures from scratch, so that any one can easily learn and apply these data structure, if necessary can apply to modified version as well. There first stage I included data structures written in C/C++, but I have planning to implement in other language as well. *Linked List, Stack, Queue, Tree, Binary Tree, Min Heap, Max Heap and Graph* data structure along with important functions are implemented in this repository.

## Features

- Simple Codes
- Easy to understand 
- Self Explanatory naming of variables and functions 
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
### Stack Class
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
### 4. Queue Class
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
### 5. Binary Tree Class
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
### 6. Min Heap Class
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
### 7. Max Heap Class
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
### 8. Graph Class
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
