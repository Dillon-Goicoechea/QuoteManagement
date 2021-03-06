#ifndef VIEWSAVEDQUOTESPAGE_H
#define VIEWSAVEDQUOTESPAGE_H

#include "quote.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class ViewSavedQuotesPage : public QMainWindow
{
 Q_OBJECT;
public:
    ViewSavedQuotesPage(QWidget *parent = nullptr);
    virtual ~ViewSavedQuotesPage();
    private:
        Ui::MainWindow *ui;

    private slots:
        void DeleteQuote(int);
        void EditQuote(int);
        void DisplayQuotes();
        void MoveToHomePage();

};

#endif // VIEWSAVEDQUOTESPAGE_H
