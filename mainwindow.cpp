#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "QTabBar"
#include "insertquotewindow.h"
#include "viewsavedquotespage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

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
    connect(ui->BackToMain1, SIGNAL(released()), this, SLOT(MoveToHomePage()));
    connect(ui->BackToMain2, SIGNAL(released()), this, SLOT(MoveToHomePage()));
    connect(ui->EditQuoteButton, SIGNAL(released()), this, SLOT(EditQuote()));
    connect(ui->DeleteQuoteButton, SIGNAL(released()), this, SLOT(DeleteQuote()));



}

void MainWindow::DisplayQuotes() {
    if(this->ui->tabWidget->isTabVisible(2) == true) {
        QFile file("../QuoteManagement/QuoteStorage.txt");
        if (!file.exists()) {
            qCritical() << "cannot be found";
            return;
        }
        if (file.open(QIODevice::OpenModeFlag::ReadWrite)) {
            QString quote, author;
            file.seek(0);
            QTextStream stream(&file);
            quote = stream.readLine();
            author = stream.readLine();
            this->ui->Quotedisplay->setText(quote + " " + author);
            file.close();
        } else {
            qCritical() << "could not open";
            qCritical() << file.errorString();
            return;
        }
    }
}

void MainWindow::EditQuote(int){
    //Deletes quote from q array after saving data, and it displays the data on the insert quote page for it to be edited before being saved again
    QTabWidget* q = this->ui->tabWidget;
    if (q->isTabVisible(1) == false) {
        q->setTabVisible(1, true);
        q->setTabVisible(0, false);
    }
    QFile file("QuoteStorage.txt");
    QString quote, author;
    quote = file.readLine();
    author = file.readLine();
    file.close();
    this->ui->QuoteAuthorEntryBox->setText(author);
    this->ui->QuoteEntryBox->setText(quote);
}

void MainWindow::DeleteQuote(int){

    this->ui->Quotedisplay->setText("");

}

void MainWindow::MoveToHomePage() {
    ui->tabWidget->setTabVisible(0, true);
    ui->tabWidget->setTabVisible(1, false);
    ui->tabWidget->setTabVisible(2, false);
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
    DisplayQuotes();
}

void MainWindow::SaveQuote() {

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

