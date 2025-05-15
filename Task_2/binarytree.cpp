#include "binarytree.h"

Node* BinaryTree::insert(Node* node, int key, QString value) {


    if (node == nullptr) {
        return new Node(key, value);
    }


    else if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else {
        node->right = insert(node->right, key, value);
    }

    return node;
}

Node* BinaryTree::remove(Node* node, int key) {


    if (node == nullptr) {
        return nullptr;
    }


    if (key < node->key) {
        node->left = remove(node->left, key);
    }


    else if (key > node->key) {
        node->right = remove(node->right, key);
    }

    else {


        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node->left;
            return temp;
        }


        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node->right;
            return temp;
        }

        Node* min = findMin(node->right);
        node->key = min->key;
        node->value = min->value;
        node->right = remove(node->right, min->key);
    }

    return node;
}

Node* BinaryTree::search(Node* node, int key) {


    if (node == nullptr || node->key == key) {
        return node;
    }


    else if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

Node* BinaryTree::findMin(Node* node) {


    while (node->left != nullptr) {
        return findMin(node->left);
    }

    return node;
}

Node* BinaryTree::findMax(Node* node) {


    while (node->right != nullptr) {
        return findMax(node->right);
    }

    return node;
}

void BinaryTree::destroy(Node* node) {


    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

QString BinaryTree::preOrder(Node* node) {
    QString temp = "";


    if (node != nullptr) {
        temp += node->value + " ";
        temp += preOrder(node->left);
        temp += preOrder(node->right);
    }

    return temp;
}

QString BinaryTree::postOrder(Node* node) {
    QString temp = "";


    if (node != nullptr) {
        temp += postOrder(node->left);
        temp += postOrder(node->right);
        temp += node->value + " ";
    }

    return temp;
}

QString BinaryTree::inOrder(Node* node) {
    QString temp = "";


    if (node != nullptr) {
        temp += inOrder(node->left);
        temp += node->value + " ";
        temp += inOrder(node->right);
    }

    return temp;
}

int BinaryTree::bstToVine(Node* grand) {
    int count = 0;

    Node* tmp = grand->right;


    while (tmp != nullptr) {
        if (tmp->left != nullptr) {
            Node* oldTmp = tmp;
            tmp = tmp->left;
            oldTmp->left = tmp->right;
            tmp->right = oldTmp;
            grand->right = tmp;
        }

        else {
            count++;
            grand = tmp;
            tmp = tmp->right;
        }
    }

    return count;
}

void BinaryTree::compress(Node* grand, int m) {
    Node* tmp = grand->right;


    for (int i = 0; i < m; i++) {
        Node* oldTmp = tmp;
        tmp = tmp->right;
        grand->right = tmp;
        oldTmp->right = tmp->left;
        tmp->left = oldTmp;
        grand = tmp;
        tmp = tmp->right;
    }
}

Node* BinaryTree::balanceBst(Node* root) {
    Node* grand = new Node(0);

    grand->right = root;

    int count = bstToVine(grand);
    int height = log2(count + 1);
    int m = pow(2, height) - 1;

    compress(grand, count - m);


    for (m = m / 2; m > 0; m /= 2) {
        compress(grand, m);
    }

    return grand->right;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

Node* BinaryTree::getRoot() const {
    return root;
}

void BinaryTree::insert(int key, QString value) {
    root = insert(root, key, value);
}

void BinaryTree::remove(int key) {
    root = remove(root, key);
}

bool BinaryTree::find(int key) {
    return search(root, key) != nullptr;
}

QString BinaryTree::value(int key) {
    Node* founded = search(root, key);


    if (founded != nullptr) {
        return founded->value;
    }

    return "";
}

QString BinaryTree::printPreOrder() {
    return preOrder(root);
}

QString BinaryTree::printPostOrder() {
    return postOrder(root);
}

QString BinaryTree::printInOrder() {
    return inOrder(root);
}

void BinaryTree::balance() {
    root = balanceBst(root);
}

void BinaryTree::changeMinAndMax() {


    if (root != nullptr) {
        Node* min = findMin(root);
        Node* max = findMax(root);
        QString temp = min->value;
        min->value = max->value;
        max->value = temp;
    }
}
