#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include "binarytree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;
    BinaryTree* BST;

    void PrintTreeToText();
    void AddNodeToWidget(Node* node, QTreeWidgetItem* parentItem);
    void ShowTree();

   private slots:
    void AddNodeSlot();
    void RemoveNodeSlot();
    void FindSlot();
    void BalanceSlot();
    void ChangeMinAndMaxSlot();
};
#endif	// MAINWINDOW_H
