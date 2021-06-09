#include "mainwindow.h"
#include "insertquotewindow.h"
#include "viewsavedquotespage.h"

#include <QApplication>
#include <QString>

void InsertQuote(Quote* q[], QString content, QString author);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Quote* q = new Quote[100];
    InsertQuote(&q, "quote1", "author1"); //example
    delete[] q;
    return a.exec();

}


void InsertQuote(Quote* q[], QString content, QString author) {
    Quote newQ(content, author);
    bool lookingForEmptySlot = true;
    int i = 0;
    while(lookingForEmptySlot) {
        if (q[i] == nullptr) {
            newQ.SetQuoteID(i);
            q[i] = &newQ;
            lookingForEmptySlot = false;
        } else {
            i++;
        }
    }
}
