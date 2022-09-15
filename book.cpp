#include "book.h"

using namespace std;

Book::Book(string bookName, string name, int isbn) : BookName{bookName}, Name{name}, ISBN{isbn}
{
    cout << "A Book is Creating!" << endl;
    cout << "A Book With Name: " << bookName << " Author Name: " << Name << " And ISBN: " << ISBN << " Created!" << endl;
}

string Book::getBookName()
{
    return BookName;
}

string Book::getName()
{
    return Name;
}

int Book::getISBN()
{
    return ISBN;
}

Book::~Book()
{
    cout << "A Book is Destructing!" << endl;
    cout << "A Book With Author Name: " << Name << " And ISBN: " << ISBN << " Destructed!" << endl;
}