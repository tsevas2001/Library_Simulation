#ifndef BOOK_H
#define BOOK_H

#pragma once
#include <iostream>

using namespace std;

class Book
{
    private:
        string BookName;
        string Name;
        int ISBN;
    public:
        Book(string, string, int);
        string getBookName();
        string getName();
        int getISBN();
        ~Book();
};

#endif