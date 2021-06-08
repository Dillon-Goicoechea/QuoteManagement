#include "quote.h"

//Not really sure what this does
Quote::Quote(QObject *parent) : QObject(parent)
{

}

//constructor for quote
Quote::Quote(std::string content, std::string author) : _quote(content), _quoteAuthor(author) {

}

//prints out data members of quote in formatted string
//I dont think this is JSON but hopefully it's close enough or it's easy to convert to JSON
std::string Quote::ToString() {
    return "{quoteID: " + std::to_string(_quoteID) + ", quote: " + _quote + ", quoteAuthor: " + _quoteAuthor + "}";
}

//used to set new ID for quote once it's location that it's being inserted into the array is known
void Quote::SetQuoteID(int id) {
    _quoteID = id;
}

std::string Quote::ReadQuoteFromFile() {
    return "";
}

void Quote::WriteQuoteToFile(){

}
