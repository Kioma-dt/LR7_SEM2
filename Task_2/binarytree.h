#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QString>

struct Node {
    int key;
    QString value;
    Node* left;
    Node* right;

    Node(int k, QString val = "")
        : key(k), value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
   private:
    Node* root;

    Node* insert(Node* node, int key, QString value);
    Node* remove(Node* node, int key);
    Node* search(Node* node, int key);

    Node* findMin(Node* node);
    Node* findMax(Node* node);

    void destroy(Node* node);

    QString preOrder(Node* node);
    QString postOrder(Node* node);
    QString inOrder(Node* node);

    int bstToVine(Node* grand);
    void compress(Node* grand, int m);
    Node* balanceBst(Node* root);

   public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();
    Node* getRoot() const;
    void insert(int key, QString value);
    void remove(int key);
    bool find(int key);
    QString value(int key);
    QString printPreOrder();
    QString printPostOrder();
    QString printInOrder();
    void balance();
    void changeMinAndMax();
};

#endif	// BINARYTREE_H
