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
    Node(T key) : data(key), left(NULL), right(NULL) {}
    Node(const Node &copy) : data(copy.data), left(copy.left), right(copy.right) {}
};

template <class T>
class BST
{
    Node<T> *root;

public:
    BST() : root(NULL) {}
    BST(T data);
    Node<T> *insert(Node<T> *, T);
    Node<T> *insert(T);
    void inOrder();
    void preOrder();
    void postOrder();
    void inOrder(Node<T> *ptr);
    void preOrder(Node<T> *ptr);
    void postOrder(Node<T> *ptr);
};

template <class T>
BST<T>::BST(T data)
{
    root = new Node<T>(data);
}

template <class T>
Node<T> *BST<T>::insert(T value)
{
    return insert(root, value);
}

template <class T>
Node<T> *BST<T>::insert(Node<T> *ptr, T value)
{
    if (!ptr)
    {
        ptr = new Node<T>(value);
        return;
    }
    if (value > ptr->data)
        ptr->right = insert(ptr->right, value);
    else
        ptr->left = insert(ptr->left, value);
    return ptr;
}

template <class T>
void BST<T>::inOrder(Node<T> *ptr)
{
    if (ptr == nullptr)
        ptr = root;
    if (ptr == NULL)
        return;
    inOrder(ptr->left);
    cout << ptr->data << endl;
    inOrder(ptr->right);
}

template <class T>
void BST<T>::preOrder(Node<T> *ptr)
{
    if (ptr == nullptr)
        ptr = root;
    if (ptr == NULL)
        return;
    cout << ptr->data << endl;
    preOrder(ptr->left);
    preOrder(ptr->right);
}

template <class T>
void BST<T>::postOrder(Node<T> *ptr)
{
    if (ptr == nullptr)
        ptr = root;
    if (ptr == NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->data << endl;
}

template <class T>
void BST<T>::inOrder(Node<T> *ptr) { inOrder(root); }

template <class T>
void BST<T>::preOrder(Node<T> *ptr) { preOrder(root); }

template <class T>
void BST<T>::postOrder(Node<T> *ptr) { postOrder(root); }

int main()
{
    BST<int> b;
    b.insert(50);
    b.insert(30);
    b.insert(20);
    b.insert(40);
    b.insert(70);
    b.insert(60);
    b.insert(80);
    b.inOrder();
    return 0;
}