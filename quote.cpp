#include "quote.h"
#include <QDebug>

//Not really sure what this does
Quote::Quote(QObject *parent) : QObject(parent)
{

}

//constructor for quote
Quote::Quote(QString content, QString author) : _quote(content), _quoteAuthor(author) {

}


//prints out data members of quote in formatted string
//I dont think this is JSON but hopefully it's close enough or it's easy to convert to JSON
QString Quote::ToString() {
    return "{quoteID: " + QString(_quoteID) + ", quote: " + _quote + ", quoteAuthor: " + _quoteAuthor + "}";
}

//used to set new ID for quote once it's location that it's being inserted into the array is known
void Quote::SetQuoteID(int id) {
    _quoteID = id;
}

QString Quote::ReadQuoteFromFile() {
    return "";
}

bool Quote::WriteQuoteToFile(){
    QFile file("C:\\development\\applicationDevelopmnet2021\\QuoteManagement\\QuoteStorage.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        stream << this->_quote << Qt::endl << this->_quoteAuthor << Qt::endl;

        file.close();
        return true;
    }
    return false;
}
