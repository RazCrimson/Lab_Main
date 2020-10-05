#include <iostream>

#define T cout << "Test " << endl;
#define COUNT 10

using namespace std;

class Node
{
public:
    int val;
    Node* right;
    Node* left;
    Node();
    Node(int);
    friend class Tree;
};

Node :: Node()
{

}

Node :: Node(int val)
{
    right = NULL;
    left = NULL;
    this -> val = val;
}

class Tree
{
public:
    Node *root;
    Tree();
    void insert(Node*&, int);
    void deleteVal(Node*&, int);
    int deleteMinNode(Node*&);
    void print2DUtil(Node*, int);
    Node*& merge(Node*&, Node*&, int, int);
};

Tree :: Tree ()
{
    root = NULL;
}

Node* newNode(int val)  
{  
    Node* node = new Node(); 
    node->val = val;  
    node->left = NULL;  
    node->right = NULL;  
  
    return(node);  
} 

void Tree :: print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->val <<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

void inorder(Node* node, int array[], int *index_ptr)  
{  
    if (node != NULL)  
    {
        inorder(node->left, array, index_ptr);  
    
        array[*index_ptr] = node->val;  
        (*index_ptr)++; 
    
        inorder(node->right, array, index_ptr);  
    }    
}  


void Tree :: insert(Node *&node, int value)
{

    if(node == NULL)
    {
        node = new Node (value);
        return;
    }
    else if(node->val > value)
    {
        insert(node->left, value);
    }
    else
    {
        insert(node->right, value);
    }

}

int Tree :: deleteMinNode(Node *&node)
{
    if(node->left != NULL)
    {
        return deleteMinNode(node->left);
    }
    else
    {
        int temp = node->val;
        Node* temp_node = node;
        node = node->right;
        delete temp_node;
        return temp; 
    } 
}

void Tree :: deleteVal(Node *&node, int value)
{
    if(node == NULL)
        return;
    else
    {
        if(node->val < value)
            deleteVal(node->right, value);
        else if(node->val > value)
            deleteVal(node->left, value);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                Node* temp = node;
                node = NULL;
                delete temp;
            }
                
            else if(node->left == NULL && node->right != NULL)
            {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->left != NULL && node->right == NULL)
            {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                int minimum = deleteMinNode(node->right);
                node->val = minimum;
            }
        }
    }
    
}

int* mergeArray(int first[], int second[], int m, int n)
{
    int *merged = new int[m+n];
    int i = 0, j = 0, k = 0; 

    while (i < m && j < n)
    {  
        if (first[i] < second[j])  
        {  
            merged[k] = first[i];  
            i++;  
        }  
        else
        {  
            merged[k] = second[j];  
            j++;  
        }  
        k++;  
    }

    while (i < m)  
    {  
        merged[k] = first[i];  
        i++; k++;  
    }  

    while (j < n)  
    {  
        merged[k] = second[j];  
        j++; k++;  
    }  
  
    return merged;    
}
Node* arrayToBst(int arr[], int start, int end)
{
    if (start > end)  
    return NULL;  
  
    int mid = (start + end)/2;  
    Node *node = newNode(arr[mid]);  
  
    node->left = arrayToBst(arr, start, mid-1);  
  
    node->right = arrayToBst(arr, mid+1, end);  
  
    return node;  
}

Node* merge(Node*& tree_1, Node*& tree_2, int m, int n)
{
    int *first = new int [m];
    int *second = new int [n];
    int i = 0;
    int j = 0; 
    inorder(tree_1, first, &i);
    inorder(tree_2, second, &j);

    int *merged = mergeArray(first, second, m, n);

    return arrayToBst(merged, 0, m+n-1);
}

int main()
{
    Tree tree_1;
    Tree tree_2;   
    int val;
    int m = 0, n = 0;
    cout << "Please enter the values of the first tree ending with -1: " << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree_1.insert(tree_1.root, val);
        m++;
        //cout << "------------------------------------------------" << endl;
    }    

    cout << "Please enter the values of the second tree ending with -1: " << endl;
    while(true)
    {
        cin >> val;
        if(val == -1)
            break;
        tree_2.insert(tree_2.root, val);
        n++;
        //cout << "------------------------------------------------" << endl;
    } 

    Tree merged;
    merged.root = merge(tree_1.root, tree_2.root, m, n);
    merged.print2DUtil(merged.root, 0);
    return 0;
}
