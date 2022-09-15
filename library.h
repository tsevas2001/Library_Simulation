#ifndef LIBRARY_H
#define LIBRARY_H

#pragma once
#include <iostream>
#include "book.h"

using namespace std;


class Shelf
{
    private:
        int max_Space;
        int bookCount;
        Book** books;
    public:
        Shelf(int);
        bool place_book(Book*);
        bool take_book();
        void print();
        ~Shelf();
};

class Cabinet
{
    private:
        Shelf* topShelf;
        Shelf* botShelf;
    public:
        Cabinet(int);
        bool place_book(Book*, int);
        bool take_book(int);
        void print(int);
        ~Cabinet();
};

class Base
{
    public:
        Base();
        ~Base();
};

class Library
{
    private:
        int totalBooks;
        Base* base;
        Cabinet* cabinet;
        Shelf* topShelf;
        Shelf* midShelf;
        Shelf* botShelf;
    public:
        Library(int);
        bool place_book(Book*, int);
        void random_places(Book**, int);
        void random_takes();
        bool take_book(int);
        void print();
        ~Library();
};

#endif