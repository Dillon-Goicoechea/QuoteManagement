#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quote.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();



private:
    Ui::MainWindow *ui;

private slots:
    void DisplayQuotes();
    void EditQuote(int);
    void DeleteQuote(int);
    void MoveToNewQuotePage();
    void MoveToViewSavedQuotesPage();
    void MoveToHomePage();
    void SaveQuote();


};
#endif // MAINWINDOW_H
