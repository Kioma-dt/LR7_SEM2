#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    BinaryTree bst;
    bst.insert(10, "10");
    bst.insert(20, "20");
    bst.insert(30, "30");
    bst.insert(100, "100");
    bst.insert(150, "150");
    bst.insert(200, "200");
    bst.insert(300, "300");

    bst.balance();

    AddTree(bst);
    ui->textEdit->append(bst.printInOrder());
    ui->textEdit->append(bst.printPreOrder());
    ui->textEdit->append(bst.printPostOrder());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AddNodeToWidget(Node* node, QTreeWidgetItem* parentItem) {


    if (node == nullptr) {
        return;
    }

    QTreeWidgetItem* item =
        new QTreeWidgetItem(QStringList() << QString::number(node->key));

    parentItem->addChild(item);

    AddNodeToWidget(node->left, item);
    AddNodeToWidget(node->right, item);
}

void MainWindow::AddTree(const BinaryTree& bst) {
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("BST");

    Node* root = bst.getRoot();


    if (root == nullptr) {
        return;
    }

    QTreeWidgetItem* rootItem =
        new QTreeWidgetItem(QStringList() << QString::number(root->key));
    ui->treeWidget->addTopLevelItem(rootItem);

    AddNodeToWidget(root->left, rootItem);
    AddNodeToWidget(root->right, rootItem);

    ui->treeWidget->expandAll();
}
