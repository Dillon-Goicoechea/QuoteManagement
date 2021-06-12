#include "insertquotewindow.h"
#include "viewsavedquotespage.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTabBar"
#include <QString>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>

InsertQuoteWindow::InsertQuoteWindow(QWidget *parent) :  QMainWindow(parent)
  , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //connect(ui->BackToMain1, SIGNAL(released()), this, SLOT(MoveToHomePage()));
}

void InsertQuoteWindow::MoveToHomePage() {

}

InsertQuoteWindow::~InsertQuoteWindow() {
    delete ui;
}
