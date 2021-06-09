#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTabBar"
#include "insertquotewindow.h"
#include <QMessageBox>
#include <QDebug>

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
    connect(ui->SaveButton, SIGNAL(released()), this, SLOT(SaveQuote()));



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

void MainWindow::SaveQuote(){

    QString quote = ui->QuoteEntryBox->toPlainText();
    QString author = ui->QuoteAuthorEntryBox->toPlainText();
    if (quote.isEmpty()){
        QMessageBox msgWarning;
        msgWarning.setText("WARNING!\nQuote box cannot be empty.");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Caution");
        msgWarning.exec();
        return;
    }

    if (author.isEmpty()){
        author = "Unknown";
    }
    qDebug() << "test quote " << Qt::endl << quote << Qt::endl << author << Qt::endl;
    bool t = Quote(quote, author).WriteQuoteToFile();
    qDebug() << t;

}


MainWindow::~MainWindow()
{
    delete ui;
}

