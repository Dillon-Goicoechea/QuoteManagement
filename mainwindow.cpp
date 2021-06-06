#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTabBar"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //starts out with only main window visible
    ui->tabWidget->setTabVisible(0, true);
    ui->tabWidget->setTabVisible(1, false);
    ui->tabWidget->setTabVisible(2, false);

    //connects new button
    connect(ui->AddNewQuoteButton, SIGNAL(released()), this, SLOT(MoveToNewQuotePage()));
    connect(ui->ViewSavedQuotesButton, SIGNAL(released()), this, SLOT(MoveToViewSavedQuotesPage()));


}

void MainWindow::MoveToNewQuotePage() {
    QTabWidget* q = this->ui->tabWidget;
    if (q->isTabVisible(1) == false) {
        q->setTabVisible(1, true);
        q->setTabVisible(0, false);
    }
}

void MainWindow::MoveToViewSavedQuotesPage() {
    QTabWidget* q = this->ui->tabWidget;
    if (q->isTabVisible(2) == false) {
        q->setTabVisible(2, true);
        q->setTabVisible(0, false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

