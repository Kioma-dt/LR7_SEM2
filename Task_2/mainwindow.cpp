#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    BST = new BinaryTree();

    connect(ui->buttonAdd, &QPushButton::clicked, this,
            &MainWindow::AddNodeSlot);
    connect(ui->buttonRemove, &QPushButton::clicked, this,
            &MainWindow::RemoveNodeSlot);
    connect(ui->buttonFind, &QPushButton::clicked, this, &MainWindow::FindSlot);
    connect(ui->buttonBalance, &QPushButton::clicked, this,
            &MainWindow::BalanceSlot);
    connect(ui->buttonChange, &QPushButton::clicked, this,
            &MainWindow::ChangeMinAndMaxSlot);

    QFont font;
    font.setPointSize(16);
    ui->labelFounded->setFont(font);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::PrintTreeToText() {
    ui->textTree->clear();
    ui->textTree->setFontPointSize(16);

    ui->textTree->append("Pre Order: " + BST->printPreOrder() + "\n");
    ui->textTree->append("Post Order: " + BST->printPostOrder() + "\n");
    ui->textTree->append("In Order: " + BST->printInOrder());
}

void MainWindow::AddNodeToWidget(Node* node, QTreeWidgetItem* parentItem) {


    if (node == nullptr) {
        QTreeWidgetItem* item =
            new QTreeWidgetItem(QStringList() << "No Child");
        parentItem->addChild(item);
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem(
        QStringList() << ("Key: " + QString::number(node->key) +
                          " Value: " + node->value));

    parentItem->addChild(item);

    AddNodeToWidget(node->left, item);
    AddNodeToWidget(node->right, item);
}

void MainWindow::ShowTree() {
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("BST");

    Node* root = BST->getRoot();


    if (root == nullptr) {
        return;
    }

    QTreeWidgetItem* rootItem = new QTreeWidgetItem(
        QStringList() << ("Key: " + QString::number(root->key) +
                          " Value: " + root->value));
    ui->treeWidget->addTopLevelItem(rootItem);

    AddNodeToWidget(root->left, rootItem);
    AddNodeToWidget(root->right, rootItem);

    ui->treeWidget->expandAll();
}

void MainWindow::AddNodeSlot() {
    try {
        bool ok = false;

        int key = ui->lineKey->text().toInt(&ok);
        QString value = ui->lineValue->text();


        if (!ok) {
            throw std::runtime_error("Wrong Key Format");
        }


        if (value == "") {
            throw std::runtime_error("Value Can't Be Empty");
        }

        if (BST->find(key)) {
            throw std::runtime_error("Such Key Exist");
        }

        BST->insert(key, value);
        this->PrintTreeToText();
        this->ShowTree();
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Add Problem", ex.what());
    }
}

void MainWindow::RemoveNodeSlot() {
    try {
        bool ok = false;

        int key = ui->lineKey->text().toInt(&ok);


        if (!ok) {
            throw std::runtime_error("Wrong Key Format");
        }

        BST->remove(key);
        this->PrintTreeToText();
        this->ShowTree();
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Remove Problem", ex.what());
    }
}

void MainWindow::FindSlot() {
    try {
        bool ok = false;

        int key = ui->lineKey->text().toInt(&ok);


        if (!ok) {
            throw std::runtime_error("Wrong Key Format");
        }

        QString value = BST->value(key);


        if (value == "") {
            ui->labelFounded->setText("No Value With Such Key");
        } else {
            ui->labelFounded->setText("Key: " + QString::number(key) +
                                      " Value: " + value);
        }
    }


    catch (const std::runtime_error& ex) {
        QMessageBox::warning(this, "Find Problem", ex.what());
    }
}

void MainWindow::BalanceSlot() {
    BST->balance();
    this->PrintTreeToText();
    this->ShowTree();
}

void MainWindow::ChangeMinAndMaxSlot() {
    BST->changeMinAndMax();
    this->PrintTreeToText();
    this->ShowTree();
}
