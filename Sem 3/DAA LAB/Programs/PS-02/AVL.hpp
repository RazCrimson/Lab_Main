#include <iostream>

using namespace std;

template <class T>
class AVL;

template <class T>
class Node
{
    T key;
    int height;
    Node<T> *left, *right;
    friend class AVL<T>;

public:
    Node() : key(0), height(0), left(NULL), right(NULL) {}
    Node(T val) : key(val), left(NULL), right(NULL) {}
    Node(const Node &copy) : key(copy.key), left(copy.left), right(copy.right) {}

    T value() { return key; }
    void printLeft() { (key && left) ? cout << left->key : cout << "NULL"; }
    void printRight() { (key && right) ? cout << right->key : cout << "NULL"; }
};

template <class T>
class AVL
{
protected:
    Node<T> *root;

    int findHeight(Node<T> *&);
    int numberOfNodes(Node<T> *&);
    int numberOfLeafNodes(Node<T> *&);
    void inOrder(Node<T> *&);
    void preOrder(Node<T> *&);
    void postOrder(Node<T> *&);
    bool deleteElement(Node<T> *&, T);
    Node<T> *insert(Node<T> *&, T);
    Node<T> *findNode(Node<T> *&ptr, T val, int *count = NULL);

public:
    AVL() : root(NULL) {}
    AVL(T key);

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

    // Rotations & Wrappers
    Node<T> *LL(Node<T> *&);
    Node<T> *RR(Node<T> *&);
    Node<T> *RL(Node<T> *&);
    Node<T> *LR(Node<T> *&);
};

template <class T>
Node<T> *AVL<T>::LL(Node<T> *&node)
{
    Node<T> *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = findHeight(node);
    temp->height = findHeight(temp);
    return temp;
}

template <class T>
Node<T> *AVL<T>::RR(Node<T> *&node)
{
    Node<T> *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = findHeight(node);
    temp->height = findHeight(temp);
    return temp;
}

template <class T>
Node<T> *AVL<T>::LR(Node<T> *&node)
{
    node->left = RR(node->left);
    return LL(node);
}
template <class T>
Node<T> *AVL<T>::RR(Node<T> *&node)
{
    node->right = LL(node->right);
    return RR(node);
}

template <class T>
AVL<T>::AVL(T key)
{
    root = new Node<T>(key);
}

template <class T>
Node<T> *AVL<T>::insert(Node<T> *&node, T value)
{
    if (!node) 
        return new Node(value);
    else if (value > node->key) 
        node->right = insertNode(node->right, value);
    else if (value < node->key)
        node->left = insertNode(node->left, value);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balancefactor = getBalanceFactor(node);

    if (balancefactor > 1 && value < node->left->key)
        return LL(node);
    if (balancefactor > 1 && value > node->left->key)
        return LR(node);
    if (balancefactor < -1 && value > node->right->key)
        return RR(node);
    if (balancefactor < -1 && value < node->right->key)
        return RL(node);
    
    return node;
}
template <class T>
int AVL<T>::findHeight(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

template <class T>
int AVL<T>::numberOfNodes(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    else
        return numberOfNodes(node->left) + numberOfNodes(node->right) + 1;
}

template <class T>
int AVL<T>::numberOfLeafNodes(Node<T> *&node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return numberOfLeafNodes(node->left) + numberOfLeafNodes(node->right);
}

template <class T>
void AVL<T>::inOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    inOrder(ptr->left);
    cout << ptr->key << " ";
    inOrder(ptr->right);
}

template <class T>
void AVL<T>::preOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    cout << ptr->key << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}

template <class T>
void AVL<T>::postOrder(Node<T> *&ptr)
{
    if (ptr == NULL)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->key << " ";
}

template <class T>
Node<T> *AVL<T>::findNode(Node<T> *&ptr, T val, int *count)
{
    if (count != NULL)
        *count += 1;
    if (ptr == NULL)
        return NULL;
    else if (ptr->key < val)
        return findNode(ptr->right, val, count);
    else if (ptr->key < val)
        return findNode(ptr->left, val, count);
    else
        return ptr;
}

template <class T>
Node<T> *AVL<T>::minimumValueNode(Node<T> *ptr)
{
    if (ptr == NULL)
        ptr = root;

    while (ptr && ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

template <class T>
Node<T> *AVL<T>::maximumValueNode(Node<T> *ptr)
{
    if (ptr == NULL)
        ptr = root;

    while (ptr && ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

template <class T>
bool AVL<T>::deleteElement(Node<T> *&node, T value)
{
    if (!node)
        return node;
    if (value < node->key)
        node->left = deleteNode(node->left, value);
    else if (value > node->key)
        node->right = deleteNode(node->right, value);
    else {
        if (node->right == NULL && node->left == NULL) {
            Node *temp = new Node();
            *temp = *node;
            node = NULL;
            free(temp);

        }
        else if (node->right == NULL || node->left == NULL) {
            Node* temp = new Node();
            temp = node->left ? node->left : node->right;
            *node = *temp;
            free(temp);
        }
        else {
            Node* temp = node->left;
            while(temp->right != NULL)
                temp = temp->right;
            node->key = temp->key;
            node->left = deleteNode(node->left, temp->key);
        }
    }

    if (!node)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balancefactor = getBalanceFactor(node);

    if (balancefactor > 1 && getBalanceFactor(node->left) >= 0)
        return LL(node);
    if (balancefactor > 1 && getBalanceFactor(node->left) < 0)
        return LR(node);
    if (balancefactor < -1 && getBalanceFactor(node->right) <= 0)
        return RR(node);
    if (balancefactor < -1 && getBalanceFactor(node->right) > 0)
        return RL(node);
    
    return node;
}

template <class T>
void AVL<T>::printL2R(Node<T> *root, int space)
{
    if (root == NULL)
        return;
    space += 1;
    printL2R(root->right, space);
    for (int i = 1; i < space; i++)
        cout << "\t";
    cout << root->key << "\n";
    printL2R(root->left, space);
}

template <class T>
void AVL<T>::printAllLevels()
{
    int h = findHeight(root);
    for (int i = 1; i <= h; i++)
    {
        cout << "Level " << i << " - ";
        printGivenLevel(root, i);
        cout << endl;
    }
}

template <class T>
void AVL<T>::printGivenLevel(Node<T> *&node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        cout << node->key << " ";
    else if (level > 1)
    {
        printGivenLevel(node->left, level - 1);
        printGivenLevel(node->right, level - 1);
    }
}

template <class T>
void AVL<T>::insertIntoTree(T value) { insert(root, value); }

template <class T>
int AVL<T>::numberOfNodesInTree() { return numberOfNodes(root); }

template <class T>
int AVL<T>::numberOfLeafNodesInTree() { return numberOfLeafNodes(root); }

template <class T>
int AVL<T>::heightOfTree() { return findHeight(root); }

template <class T>
void AVL<T>::traverseInOrder() { inOrder(root); }

template <class T>
void AVL<T>::traversePreOrder() { preOrder(root); }

template <class T>
void AVL<T>::traversePostOrder() { postOrder(root); }

template <class T>
void AVL<T>::printTreeL2R() { printL2R(root, 0); }

template <class T>
bool AVL<T>::deleteFromTree(T val) { return deleteElement(root, val); }

template <class T>
Node<T> *AVL<T>::findNodeWithValue(T val, int *count) { return findNode(root, val, count); }