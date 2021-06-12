#ifndef INSERTQUOTEWINDOW_H
#define INSERTQUOTEWINDOW_H

#include "quote.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class InsertQuoteWindow : public QMainWindow
{
    Q_OBJECT
public:
    InsertQuoteWindow (QWidget* parent = nullptr);
    virtual ~InsertQuoteWindow();
private:
    Ui::MainWindow *ui;

    private slots:
    void MoveToHomePage();
};


#endif // INSERTQUOTEWINDOW_H
