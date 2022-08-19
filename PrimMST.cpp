#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int to;
    int wei;
    edge(){
        this->to=-1;
        this->wei=-1;
    }
    edge(int a, int b){
        this->to= a;
        this->wei=b;
    }
};
class Node
{
public:
	edge data;
	Node *next;
	Node(edge data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class LinkedList
{
private:
	Node *LinkedListHead;
	int LengthOfLinkedList;
	void partition(Node *head, Node **front, Node **back)
	{
		Node *fast, *slow;
		if (head == NULL || head->next == NULL)
		{
			*front = head; // &a
			*back = NULL;  //&b
		}
		else
		{
			slow = head;
			fast = head->next;

			while (fast != NULL)
			{
				fast = fast->next;
				if (fast != NULL)
				{
					slow = slow->next;
					fast = fast->next;
				}
			}
			*front = head;		// &a
			*back = slow->next; //&b
			slow->next = NULL;
		}
	}
	Node *mergeLists(Node *a, Node *b)
	{
		Node *mergedList = NULL;
		if (a == NULL)
		{
			return b;
		}
		else if (b == NULL)
		{
			return a;
		}

		if (a->data.wei <= b->data.wei)
		{
			mergedList = a;
			mergedList->next = mergeLists(a->next, b);
		}
		else
		{
			mergedList = b;
			mergedList->next = mergeLists(a, b->next);
		}
		return mergedList;
	}
	void mergeSort(Node **source)
	{
		Node *head = *source;
		Node *a = NULL, *b = NULL;
		if (head == NULL || head->next == NULL)
			return;

		partition(head, &a, &b);
		mergeSort(&a);
		mergeSort(&b);

		*source = mergeLists(a, b);
	}
public:
	LinkedList()
	{
		LinkedListHead = NULL;
		LengthOfLinkedList = 0;
	}
	int length()
	{
		return this->LengthOfLinkedList;
	}
	void push_back(edge data)
	{
        int position = length();
		Node *newNode = new Node(data);
		Node *temp = LinkedListHead;
        if(LinkedListHead==NULL){
            LinkedListHead=newNode;
            newNode->next= NULL;

        }
        else{
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
	void printlist()
	{
		Node *temp = LinkedListHead;
		if (LinkedListHead == NULL)
		{
			cout << "List is empty!" << endl;
			return;
		}
		while (temp != NULL)
		{
			cout << temp->data.wei;
			temp = temp->next;
		}
		cout << "\n";
	}
	void linkedlist_sort()
	{
		mergeSort(&this->LinkedListHead);
	}
    edge delete_front(){
        if(LinkedListHead==NULL) {
         return edge(-1,-1);   
        }
        Node* temp = LinkedListHead;
        LinkedListHead= temp->next;
        LengthOfLinkedList--;
        return temp->data;
    }
    bool is_empty(){
        if(LengthOfLinkedList==0 && LinkedListHead==NULL) return true;
        else return false;
    }
};

// class heap{

// };

class Graph{
    //adjlist 
    vector<edge> *adjl;
    int nver;

    public:
    Graph(int n){
        this->nver=n;
        adjl = new vector<edge>[n];
    }
    void addedge(int x, int y, int w){
        adjl[x].push_back(edge(y,w));
        adjl[y].push_back(edge(x,w));
    }
    int prim_mst_stl_linkedlist(){
        //Container To Keep The Active Edges
        LinkedList container= LinkedList();
        //Visited Array that denotes whether a node has been in MST or not
        bool *visited = new bool [nver]{0};
        int ans=0;
        container.push_back(edge(0,0));
        while(!container.is_empty()){
            container.linkedlist_sort();
            edge temp=container.delete_front();
            int to= temp.to;
            int wei = temp.wei;
            if(visited[to]){
                continue;
            }
            //otherwise take the current edge 
            ans+=wei;
            visited[to]=1;
            for(auto x: adjl[to]){
                if(visited[x.to]==0){
                    container.push_back(x);
                }
            }

        }
        return ans;
    }
    void quickSort(edge arr[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int partition(edge arr[], int start, int end)
{
    int pIndex = start;
    edge pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(arr[i].wei >= pivot.wei)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void swap(edge *x, edge *y)
{
    edge t = *x;
    *x = *y;
    *y = t;
}
    
    
    int prim_mst_stl_array(){
        //Container To Keep The Active Edges
        edge container[nver];
        int containerlen=0;
        //Visited Array that denotes whether a node has been in MST or not
        bool *visited = new bool [nver]{0};
        int ans=0;
        container[containerlen]=edge(0,0);
        containerlen++;
         while(containerlen>0){
       quickSort(container,0,containerlen-1);
            edge temp=container[containerlen-1];
            containerlen--;

            int to= temp.to;
            int wei = temp.wei;
            if(visited[to]){
                continue;
            }
            //otherwise take the current edge 
            ans+=wei;
            visited[to]=1;
            for(auto x: adjl[to]){
                if(visited[x.to]==0){
                    container[containerlen]=x;
                    containerlen++;
                }
            }

         }
        return ans;
    }

};

int main(){
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e,a, b,c;
    cin>>v>>e;
   Graph g1= Graph(v);
   for(int i=0; i<e; i++){
    cin>>a>>b>>c;
    g1.addedge(a,b,c);
   }
   cout<<g1.prim_mst_stl_linkedlist()<<endl;
   cout<<g1.prim_mst_stl_array()<<endl;

}