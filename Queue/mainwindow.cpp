#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    first = new Queue<int>();
    second = new Queue<int>();

    connect(ui->buttonGenerateFirst, &QPushButton::clicked, this,
            &MainWindow::GenerateFirstSlot);
    connect(ui->buttonGenerateSecond, &QPushButton::clicked, this,
            &MainWindow::GenerateSecondSlot);
    connect(ui->buttonAddFirst, &QPushButton::clicked, this,
            &MainWindow::AddToFirstSlot);
    connect(ui->buttonAddSecond, &QPushButton::clicked, this,
            &MainWindow::AddToSecondSlot);
    connect(ui->buttonRemoveFirst, &QPushButton::clicked, this,
            &MainWindow::RemoveFirstSlot);
    connect(ui->buttonRemoveSecond, &QPushButton::clicked, this,
            &MainWindow::RemoveSecondSlot);
    connect(ui->buttonSwap, &QPushButton::clicked, this, &MainWindow::SwapSlot);
    connect(ui->buttonMinFirst, &QPushButton::clicked, this,
            &MainWindow::PushMinFirstSlot);
    connect(ui->buttonMinSecond, &QPushButton::clicked, this,
            &MainWindow::PushMinSecondSlot);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Generate(Queue<int>* queue, size_t size) {


    for (size_t i = 0; i < size; i++) {
        queue->push(QRandomGenerator::system()->generate() % 100);
    }
}

void MainWindow::Add(Queue<int>* queue, int value) {
    queue->push(value);
}

void MainWindow::Remove(Queue<int>* queue) {
    queue->pop();
}

void MainWindow::ShowQueue() {
    ui->listFirst->clear();
    ui->listSecond->clear();
    QFont font;
    font.setPointSize(20);

    for (size_t i = 0; i < first->size(); i++) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setTextAlignment(Qt::AlignCenter);
        item->setFont(font);
        item->setText(QString::number(first->front()));
        ui->listFirst->addItem(item);
        first->push(first->front());
        first->pop();
    }

    for (size_t i = 0; i < second->size(); i++) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setTextAlignment(Qt::AlignCenter);
        item->setFont(font);
        item->setText(QString::number(second->front()));
        ui->listSecond->addItem(item);
        second->push(second->front());
        second->pop();
    }
}

void MainWindow::PushMin(Queue<int>* queue) {
    size_t size = queue->size();
    int min = queue->front();


    for (size_t i = 0; i < size; i++) {
        if (queue->front() < min) {
            min = queue->front();
        }
        queue->push(queue->front());
        queue->pop();
    }

    size_t count_min = 0;


    for (size_t i = 0; i < size; i++) {
        if (queue->front() == min) {
            count_min++;
        } else {
            queue->push(queue->front());
        }

        queue->pop();
    }


    for (size_t i = 0; i < count_min; i++) {
        queue->push(min);
    }


    for (size_t i = 0; i < size - count_min; i++) {
        queue->push(queue->front());
        queue->pop();
    }
}

void MainWindow::GenerateFirstSlot() {
    bool ok = false;
    size_t size = ui->textNumberFirst->text().toUInt(&ok);


    if (!ok) {
        QMessageBox::warning(this, "First Problem", "Wrong Number Format");
        return;
    }
    first->clear();
    this->Generate(first, size);
    this->ShowQueue();
}

void MainWindow::GenerateSecondSlot() {
    bool ok = false;
    size_t size = ui->textNumberSecond->text().toUInt(&ok);


    if (!ok) {
        QMessageBox::warning(this, "Second Problem", "Wrong Number Format");
        return;
    }
    second->clear();
    this->Generate(second, size);
    this->ShowQueue();
}

void MainWindow::AddToFirstSlot() {
    bool ok = false;
    int value = ui->textValue->text().toUInt(&ok);


    if (!ok) {
        QMessageBox::warning(this, "Second Problem", "Wrong Number Format");
        return;
    }
    this->Add(first, value);
    this->ShowQueue();
}

void MainWindow::RemoveFirstSlot() {
    this->Remove(first);
    this->ShowQueue();
}

void MainWindow::AddToSecondSlot() {
    bool ok = false;
    int value = ui->textValue->text().toUInt(&ok);


    if (!ok) {
        QMessageBox::warning(this, "Second Problem", "Wrong Number Format");
        return;
    }
    this->Add(second, value);
    this->ShowQueue();
}

void MainWindow::RemoveSecondSlot() {
    this->Remove(second);
    this->ShowQueue();
}

void MainWindow::SwapSlot() {
    first->swap(*second);
    this->ShowQueue();
}

void MainWindow::PushMinFirstSlot() {
    this->PushMin(first);
    this->ShowQueue();
}

void MainWindow::PushMinSecondSlot() {
    this->PushMin(second);
    this->ShowQueue();
}
