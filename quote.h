#ifndef QUOTE_H
#define QUOTE_H

#include <QObject>

class Quote : public QObject
{
    Q_OBJECT
public:
    explicit Quote(QObject *parent = nullptr);
    Quote(std::string content, std::string author);
    void SetQuoteID(int id);
    std::string ToString();
    std::string ReadQuoteFromFile();
    void WriteQuoteToFile();
protected:
    std::string _quote;
    std::string _quoteAuthor;
    int _quoteID = 0;

signals:

};

#endif // QUOTE_H
