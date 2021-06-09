#ifndef QUOTE_H
#define QUOTE_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class Quote : public QObject
{
    Q_OBJECT
public:
    explicit Quote(QObject *parent = nullptr);
    Quote(QString content, QString author);
    void SetQuoteID(int id);
    QString ToString();
    QString ReadQuoteFromFile();
    bool WriteQuoteToFile();
protected:
    QString _quote;
    QString _quoteAuthor;
    int _quoteID = 0;

signals:

};

#endif // QUOTE_H
