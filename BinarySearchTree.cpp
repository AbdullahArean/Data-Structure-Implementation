#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
class Node
{
public:
    int data;
    int count; //To handle Duplicate data
    Node *left_child;
    Node *right_child;
    Node(int data)
    {
        this->data = data;
        this->count = 1;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};
class BinarySearchTree {
private:
    Node*   BinarySearchTreeRoot;
    Node*   insert(int x, Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL) 
            Current_Tree_Node = new Node(x);
        else if(Current_Tree_Node->data==x) 
            Current_Tree_Node->count++;
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = insert(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = insert(x, Current_Tree_Node->right_child);
        return Current_Tree_Node;
    }
    Node*   findMin(Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->left_child == NULL)
            return Current_Tree_Node;
        else
            return findMin(Current_Tree_Node->left_child);
    }
    Node*   findMax(Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->right_child == NULL)
            return Current_Tree_Node;
        else
            return findMax(Current_Tree_Node->right_child);
    }
    Node*   remove(int x, Node* Current_Tree_Node) {
        Node* temp;
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = remove(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = remove(x, Current_Tree_Node->right_child);
        else if(Current_Tree_Node->data==x && Current_Tree_Node->count>1) {
            Current_Tree_Node->count--;
            return Current_Tree_Node;
        }
        else if(Current_Tree_Node->count==1 && Current_Tree_Node->left_child && Current_Tree_Node->right_child)
        {
            temp = findMin(Current_Tree_Node->right_child);
            Current_Tree_Node->data = temp->data;
            Current_Tree_Node->right_child = remove(Current_Tree_Node->data, Current_Tree_Node->right_child);
        }
        else
        {
            temp = Current_Tree_Node;
            if(Current_Tree_Node->left_child == NULL)
                Current_Tree_Node = Current_Tree_Node->right_child;
            else if(Current_Tree_Node->right_child == NULL)
                Current_Tree_Node = Current_Tree_Node->left_child;
            delete temp;
        }

        return Current_Tree_Node;
    }
    void    inorder(Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return;
        inorder(Current_Tree_Node->left_child);
        cout << Current_Tree_Node->data << " ";
        inorder(Current_Tree_Node->right_child);
    }
    Node*   find(Node* Current_Tree_Node, int x) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            return find(Current_Tree_Node->left_child, x);
        else if(x > Current_Tree_Node->data)
            return find(Current_Tree_Node->right_child, x);
        else
            return Current_Tree_Node;
    }
    void    print_preorder      (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            printf("%d ", bbinary_tree->data);
            print_preorder(bbinary_tree->left_child);
            print_preorder(bbinary_tree->right_child);
        }
    }
    void    print_inorder       (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            print_inorder(bbinary_tree->left_child);
            printf("%d ", bbinary_tree->data);
            print_inorder(bbinary_tree->right_child);
        }
    }
    void    print_postorder     (Node *bbinary_tree)
    {
        if (bbinary_tree)
        {
            print_postorder(bbinary_tree->left_child);
            print_postorder(bbinary_tree->right_child);
            printf("%d ", bbinary_tree->data);
        }
    }
    int     height              (Node* bbinary_tree)
{ // Recursive function to calculate the height of a given binary tree
    // base case: empty tree has a height of 0
    if (bbinary_tree == nullptr) {
        return 0;
    }
 
    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(bbinary_tree->left_child), height(bbinary_tree->right_child));
}
    void    print_levelorder    (Node *bbinary_tree)
    {
        /* Function to line by line print level order traversal a tree*/
        int h = height(bbinary_tree);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(bbinary_tree, i);
            //printf("\n");
        }
    }
    void    printGivenLevel     (Node *bbinary_tree, int level)
    {
        /* Print Nodes at a given level */
        if (bbinary_tree == NULL)
            return;
        if (level == 1)
            printf("%d ", bbinary_tree->data);
        else if (level > 1)
        {
            printGivenLevel(bbinary_tree->left_child, level - 1);
            printGivenLevel(bbinary_tree->right_child, level - 1);
        }
    }
    int     numberofNodes       (Node *bbinary_tree){
        if (!bbinary_tree) return 0;
        return numberofNodes(bbinary_tree->left_child)+numberofNodes(bbinary_tree->right_child)+1;

    }
    int     numberofleafs       (Node *bbinary_tree){
        if(!bbinary_tree) return 0;
        if (!bbinary_tree->left_child && !bbinary_tree->right_child) return 1;
        return numberofleafs (bbinary_tree->left_child)+numberofleafs (bbinary_tree->right_child);

    }
    int     numberofnonleafs    (Node *bbinary_tree){
        if((!bbinary_tree) || (!bbinary_tree->left_child && !bbinary_tree->right_child) )return 0;
            return numberofnonleafs (bbinary_tree->left_child)+numberofnonleafs (bbinary_tree->right_child)+1;

    }
    int     numberoffullNode    (Node *bbinary_tree){
        if(!bbinary_tree) return 0;
        if(!bbinary_tree->left_child && !bbinary_tree->right_child ) return 0;
        return numberoffullNode(bbinary_tree->left_child)+numberoffullNode(bbinary_tree->right_child)+ (bbinary_tree->left_child && bbinary_tree->right_child)?1:0;
       
    }
    Node*   BuildTreePreIn      (int in[], int pre[], int inStrt, int inEnd)
    {
        static int preIndex = 0;
        if (inStrt > inEnd) return NULL;
        Node *tNode = new Node(pre[preIndex++]);
        if (inStrt == inEnd) return tNode;
        int inIndex = -1;
        for (int i = inStrt; i <= inEnd; i++) if (in[i] == tNode->data) inIndex = i;
        tNode->left_child = BuildTreePreIn(in, pre, inStrt, inIndex - 1);
        tNode->right_child = BuildTreePreIn(in, pre, inIndex + 1, inEnd);
        return tNode;
    }
    Node*   makeBSTEmpty        (Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        {
            makeBSTEmpty(Current_Tree_Node->left_child);
            makeBSTEmpty(Current_Tree_Node->right_child);
            delete Current_Tree_Node;
        }
        return NULL;
    }
    int CountGreaterElement(Node *Current_Tree_Node, int x)
    {
        if(Current_Tree_Node == NULL)
            return 0;
        else if( Current_Tree_Node->data>x) return 1+ CountGreaterElement(Current_Tree_Node->left_child,x) +CountGreaterElement(Current_Tree_Node->right_child,x);
        else if (Current_Tree_Node->data<=x) return CountGreaterElement(Current_Tree_Node->right_child,x); 
        return 0;
       
    } 
    int CountSmallerElement(Node *Current_Tree_Node, int x)
    {
        if(Current_Tree_Node == NULL)
            return 0;
        else if( Current_Tree_Node->data<x) return 1+ CountSmallerElement(Current_Tree_Node->left_child,x) +CountSmallerElement(Current_Tree_Node->right_child,x);
        else if (Current_Tree_Node->data>=x) return CountSmallerElement(Current_Tree_Node->left_child,x); 
        return 0;
       
    }
    Node * Min( Node * a, Node * b){
         return (a->data>b->data)?b:a;
    }
    Node * Max( Node * a, Node * b){
         return (a->data>b->data)?a:b;
    }
    Node*   UpperBound(Node* Current_Tree_Node, int x) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->data<=x) return UpperBound(Current_Tree_Node->right_child, x);
        else if(Current_Tree_Node->data> x) return Min(UpperBound(Current_Tree_Node->left_child, x), UpperBound(Current_Tree_Node->right_child, x));
         
        return NULL;
    }
public:
    BinarySearchTree() 
    {
        BinarySearchTreeRoot = NULL;
    }
    ~BinarySearchTree()
     {
        BinarySearchTreeRoot = makeBSTEmpty(BinarySearchTreeRoot);
    }
    void    insert(int x) 
    {
        BinarySearchTreeRoot = insert(x, BinarySearchTreeRoot);
    }
    void    remove(int x) 
    {
        BinarySearchTreeRoot = remove(x, BinarySearchTreeRoot);
    }
    bool    search(int x) 
    {
        if(find(BinarySearchTreeRoot, x)) return 1;
        return 0;
    }
    void    Display             ()
     {
        print_inorder(BinarySearchTreeRoot);
        //cout << endl;
    }
    void    BuildTree           (int in[], int pre[], int inStrt, int inEnd)
    {
        this->BinarySearchTreeRoot = BuildTreePreIn(in,pre, inStrt, inEnd);

    }
    Node*   Returntreehead      ()
    {
        return BinarySearchTreeRoot;
    }
    Node*   FindMaximumElement  () 
    {
        return findMax(this->BinarySearchTreeRoot);

    }
    Node*   FindMinimumElement  ()
    {
        return findMin(this->BinarySearchTreeRoot);

    }
    int     CountGreaterElement(int x)
    {
        return CountGreaterElement(this->BinarySearchTreeRoot, x);
    }
    int     CountSmallerElement(int x)
    {
        return CountSmallerElement(this->BinarySearchTreeRoot, x);
    }
    int UpperBound(int x){
        int min = findMin(this->BinarySearchTreeRoot)->data;
        int max  = findMax(this->BinarySearchTreeRoot)->data;
        if(x<min) return min;
        else if(x>=max) return max;  
        else {
            return UpperBound(this->BinarySearchTreeRoot, x)->data;
        }

    }
    int LowerBound (int x){

    }
};
void Solution()
{
    int n, q,x;
    BinarySearchTree t1;
    char c;
    cin>>n>>q;
    while(n--) {cin>>x; t1.insert(x);}
    t1.Display();
    printf("\n");
    cout<<t1.CountGreaterElement(10)<<endl;
    cout<<t1.CountSmallerElement(10)<<endl;
    t1.remove(1);
    t1.Display();

    printf("\n");
    cout<<t1.CountGreaterElement(10)<<endl;
    cout<<t1.CountSmallerElement(10)<<endl;
    printf("\n");
    cout<< t1.UpperBound(1) <<endl;
    cout<< t1.UpperBound(2) <<endl;
    // cout<< t1.UpperBound(3) <<endl;
    // cout<< t1.UpperBound(4) <<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}