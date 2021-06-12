#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTabBar"
#include "viewsavedquotespage.h"
#include <QMessageBox>
#include <QDebug>
#include "insertquotewindow.h"
#include <QString>
#include <QWidget>

ViewSavedQuotesPage::ViewSavedQuotesPage(QWidget *parent) :  QMainWindow(parent)
  , ui(new Ui::MainWindow)

{
    ui->setupUi(this);


}

ViewSavedQuotesPage::~ViewSavedQuotesPage() {
    delete ui;
}

void ViewSavedQuotesPage::DisplayQuotes(){
    if(this->ui->tabWidget->isTabVisible(2)==true){
        QFile file("C:\\development\\applicationDevelopmnet2021\\QuoteManagement\\QuoteStorage.txt");
     QString quote, author;
     quote = file.readLine();
     author = file.readLine();
     file.close();
           this->ui->Quotedisplay->setText(quote + " " + author);
    }
}

void ViewSavedQuotesPage::EditQuote(int){
    //Deletes quote from q array after saving data, and it displays the data on the insert quote page for it to be edited before being saved again
    QTabWidget* q = this->ui->tabWidget;
    if (q->isTabVisible(1) == false) {
        q->setTabVisible(1, true);
        q->setTabVisible(0, false);
    }
    QFile file("C:\\development\\applicationDevelopmnet2021\\QuoteManagement\\QuoteStorage.txt");
 QString quote, author;
 quote = file.readLine();
 author = file.readLine();
 file.close();
    this->ui->QuoteAuthorEntryBox->setText(author);
    this->ui->QuoteEntryBox->setText(quote);
}

void ViewSavedQuotesPage::DeleteQuote(int){

    this->ui->Quotedisplay->setText("");

}

void ViewSavedQuotesPage::MoveToHomePage() {

}

