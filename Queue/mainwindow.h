#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <MyLibVector/include/vector.h>
#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>
#include "queue.h"

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
    Queue<int>* first;
    Queue<int>* second;

    void Generate(Queue<int>* queue, size_t size);
    void Add(Queue<int>* queue, int value);
    void Remove(Queue<int>* queue);
    void ShowQueue();
    void PushMin(Queue<int>* queue);

   private slots:
    void GenerateFirstSlot();
    void GenerateSecondSlot();
    void AddToFirstSlot();
    void RemoveFirstSlot();
    void AddToSecondSlot();
    void RemoveSecondSlot();
    void SwapSlot();
    void PushMinFirstSlot();
    void PushMinSecondSlot();
};
#endif	// MAINWINDOW_H
