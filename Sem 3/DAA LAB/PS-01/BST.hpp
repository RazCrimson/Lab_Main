#include <iostream>

using namespace std;

template <class T>
class BST;

template <class T>
class Node
{
    T data;
    Node<T> *left, *right;
    friend class BST<T>;

public:
    Node() : data(0), left(NULL), right(NULL) {}
    Node(T val) : data(val), left(NULL), right(NULL) {}
    Node(const Node &copy) : data(copy.data), left(copy.left), right(copy.right) {}

    T value() { return data; }
    void printLeft() { (data && left) ? cout << left->data : cout << "NULL"; }
    void printRight() { (data && right) ? cout << right->data : cout << "NULL"; }
};

template <class T>
class BST
{
protected:
    Node<T> *root;

    int height(Node<T> *&);
    int numberOfNodes(Node<T> *&);
    int numberOfLeafNodes(Node<T> *&);
    void inOrder(Node<T> *&);
    void preOrder(Node<T> *&);
    void postOrder(Node<T> *&);
    bool deleteElement(Node<T> *&, T);
    Node<T> *insert(Node<T> *&, T);
    Node<T> *findNode(Node<T> *&ptr, T val, int *count = NULL);

public:
    BST() : root(NULL) {}
    BST(T data);

    Node<T> *minimumValueNode(Node<T> *ptr = NULL);
    Node<T> *maximumValueNode(Node<T> *ptr = NULL);
    Node<T> *findNodeWithValue(T val, int *count = NULL);
    void printL2R(Node<T> *ptr, int space = 0);
    void printGivenLevel(Node<T> *&root, int level);

    // Wrappers functions
    void printAllLevels();
    void printTreeL2R();
    void insertIntoTree(T);
    void traverseInOrder();
    void traversePreOrder();
    void traversePostOrder();
    bool deleteFromTree(T);
    int heightOfTree();
    int numberOfNodesInTree();
    int numberOfLeafNodesInTree();
    
};

template <class T>
BST<T>::BST(T data)
{
    root = new Node<T>(data);
}

template <class T>
Node<T> *BST<T>::insert(Node<T> *&ptr, T value)
{
    if (!ptr)
    {
        ptr = new Node<T>(value);
        return ptr;
    }
    if (value > ptr->data)
        ptr->right = insert(ptr->right, value);
    else if(value < ptr->data)
        ptr->left = insert(ptr->left, value);
    else
        ptr = NULL;    
    return ptr;
}

template <class T>
int BST<T>::height(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

template <class T>
int BST<T>::numberOfNodes(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    else
        return numberOfNodes(node->left) + numberOfNodes(node->right) + 1;
}

template <class T>
int BST<T>::numberOfLeafNodes(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return numberOfLeafNodes(node->left) + numberOfLeafNodes(node->right);
}

template <class T>
void BST<T>::inOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    inOrder(ptr->left);
    cout << ptr->data << " ";
    inOrder(ptr->right);
}

template <class T>
void BST<T>::preOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    cout << ptr->data << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}

template <class T>
void BST<T>::postOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->data << " ";
}

template <class T>
Node<T> *BST<T>::findNode(Node<T> *&ptr, T val, int *count)
{
    if (count != NULL)
        *count += 1;
    if (ptr == NULL)
        return NULL;
    else if (ptr->data < val)
        return findNode(ptr->right, val, count);
    else if (ptr->data < val)
        return findNode(ptr->left, val, count);
    else
        return ptr;
}

template <class T>
Node<T> *BST<T>::minimumValueNode(Node<T> *ptr)
{
    if (ptr == NULL)
        ptr = root;

    while (ptr && ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

template <class T>
Node<T> *BST<T>::maximumValueNode(Node<T> *ptr)
{
    if (ptr == NULL)
        ptr = root;

    while (ptr && ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

template <class T>
bool BST<T>::deleteElement(Node<T> *&ptr, T val)
{
    if (ptr == NULL)
        return false;

    if (val < ptr->data)
        return deleteElement(ptr->left, val);
    else if (val > ptr->data)
        return deleteElement(ptr->right, val);

    else
    {
        Node<T> *temp = NULL;
        if (ptr->left == NULL)
        {
            temp = ptr->right;
            delete ptr;
            ptr = temp;
            return true;
        }
        else if (ptr->right == NULL)
        {
            temp = ptr->left;
            delete ptr;
            ptr = temp;
            return true;
        }

        temp = maximumValueNode(ptr->left);

        ptr->data = temp->data;

        return deleteElement(ptr->left, temp->data);
    }
}

template <class T>
void BST<T>::printL2R(Node<T> *root, int space)
{
    if (root == NULL)
        return;
    space += 1;
    printL2R(root->right, space);
    for (int i = 1; i < space; i++)
        cout << "\t";
    cout << root->data << "\n";
    printL2R(root->left, space);
}

template <class T>
void BST<T>::printAllLevels()
{
    int h = height(root);
    for (int i = 1; i <= h; i++){
        cout << "Level " << i << " - ";
        printGivenLevel(root, i);
        cout << endl;
    }
}

template <class T>
void BST<T>::printGivenLevel(Node<T> *&node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        cout << node->data << " ";
    else if (level > 1)
    {
        printGivenLevel(node->left, level - 1);
        printGivenLevel(node->right, level - 1);
    }
}

template <class T>
void BST<T>::insertIntoTree(T value) { insert(root, value); }

template <class T>
int BST<T>::numberOfNodesInTree() { return numberOfNodes(root); }

template <class T>
int BST<T>::numberOfLeafNodesInTree() { return numberOfLeafNodes(root); }

template <class T>
int BST<T>::heightOfTree() { return height(root); }

template <class T>
void BST<T>::traverseInOrder() { inOrder(root); }

template <class T>
void BST<T>::traversePreOrder() { preOrder(root); }

template <class T>
void BST<T>::traversePostOrder() { postOrder(root); }

template <class T>
void BST<T>::printTreeL2R() { printL2R(root, 0); }

template <class T>
bool BST<T>::deleteFromTree(T val) { return deleteElement(root, val); }

template <class T>
Node<T> *BST<T>::findNodeWithValue(T val, int *count) { return findNode(root, val, count); }