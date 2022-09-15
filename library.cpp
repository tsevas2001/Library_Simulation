#include <time.h>
#include "library.h"

using namespace std;

// Creating Shelf.
Shelf::Shelf(int max) : max_Space{max}
{
    cout << "A Shelf is creating!" << endl;
    // Creting storage for the books.
    books = new Book*[max];
    for (int i = 0; i < max; i++)
    {
        books[i] = nullptr;
    }
    bookCount = 0;
    cout << "A Shelf created!" << endl;
}

// Placing the book in the shelf.
bool Shelf::place_book(Book* book)
{
    if (bookCount < max_Space)
    {
        // Adding book in the shelf.
        books[bookCount] = book;
        bookCount++;
        return true;
    }
    else
        return false;
}

// Taking the book from the shelf.
bool Shelf::take_book()
{
    if (bookCount == 0) 
    {
        return false;
    }
    else
    {
        for (int i = 0; i < max_Space; i++)
        {
            if (books[i] != nullptr) 
            {
                books[i] == nullptr; 
                bookCount--;
                return true;
            }
        }
        return false;
    }
}

// Printing the SHelf.
void Shelf::print()
{
    cout << "===============================================" << endl;
    cout << "    _|_|_|  _|                  _|      _|_|  #" << endl;
    cout << "  _|        _|_|_|      _|_|    _|    _|      #" << endl;
    cout << "    _|_|    _|    _|  _|_|_|_|  _|  _|_|_|_|  #" << endl;
    cout << "        _|  _|    _|  _|        _|    _|      #" << endl;
    cout << "        _|  _|    _|  _|        _|    _|      #" << endl;
    cout << "  _|_|_|    _|    _|    _|_|_|  _|    _|      #" << endl;
    cout << "===============================================" << endl;

    if (bookCount != 0)
    {
        cout << "Book Name | Name author | ISBN" << endl; 
        for (int i = 0; i < max_Space; i++)
        {
            if (books[i] != nullptr)
                cout << i+1 << ") " << books[i]->getBookName() << " | " << books[i]->getName() << " | " << books[i]->getISBN() << endl;
        }
    }
    else
    {
        cout << "Their is no book in the shelf!" << endl;
    }
}

// Destroyng the Shelf.
Shelf::~Shelf()
{
    cout << "A Shelf is Destructing" << endl;
    delete[] books;
    cout << "A Shelf Destructed" << endl;
}

// Creating Cabinet.
Cabinet::Cabinet(int space)
{
    cout << "A Cabinet is Creating!" << endl;
    // Creating cabinet shelfs.
    topShelf = new Shelf(space); 
    botShelf = new Shelf(space);
    cout << "A Cabinet Created!" << endl;
}

// Placing book in the cabinet shelf.
bool Cabinet::place_book(Book* book, int position)
{
    if (position == 1)
        return topShelf->place_book(book);
    else
        return botShelf->place_book(book);
}

// Taking a book from the cabinet shelf.
bool Cabinet::take_book(int position)
{
    if (position == 1)
        return topShelf->take_book();
    else
        return botShelf->take_book();
}

// Printing the cabinet Shelf.
void Cabinet::print(int position)
{
    cout << "=================================================================" << endl;
    cout << "  _|_|_|            _|        _|                        _|      #" << endl;
    cout << "_|          _|_|_|  _|_|_|        _|_|_|      _|_|    _|_|_|_|  #" << endl;
    cout << "_|        _|    _|  _|    _|  _|  _|    _|  _|_|_|_|    _|      #" << endl;
    cout << "_|        _|    _|  _|    _|  _|  _|    _|  _|          _|      #" << endl;
    cout << "  _|_|_|    _|_|_|  _|_|_|    _|  _|    _|    _|_|_|      _|_|  #" << endl;
    cout << "=================================================================" << endl;
    if (position == 1)
        return topShelf->print();
    else
        return botShelf->print();
}

// Destroying cabinet.
Cabinet::~Cabinet()
{
    cout << "A Cabinet is Destructing!" << endl;
    // Deleteing cabinet shelfs.
    delete topShelf;
    delete botShelf;
    cout << "A Cabinet Destructed!" << endl;
}

// Creating Base.
Base::Base()
{
    cout << "A Base is Creating!" << endl;
    cout << "A Base Created!" << endl;
}
//Destroying Base.
Base::~Base()
{
    cout << "A Base is Destructing!" << endl;
    cout << "A Base Destructed" << endl;
}

// Creating Library.
Library::Library(int space)
{
    cout << "A Library is Creating!" << endl;
    totalBooks = 0;
    // Creating objectes.
    base = new Base();
    cabinet = new Cabinet(space);
    topShelf = new Shelf(space);
    midShelf = new Shelf(space);
    botShelf = new Shelf(space);
    cout << "A Library Created!" << endl;
    
}

// Placing book in the Library
bool Library::place_book(Book* book, int position)
{
    switch(position)
    {
        case 1:
            return topShelf->place_book(book);
            break;
        case 2:
            return midShelf->place_book(book);
            break;
        case 3:
            return botShelf->place_book(book);
            break;
        case 4:
            return cabinet->place_book(book, 1);
            break;
        case 5:
            return cabinet->place_book(book, 2);
            break;
        default:
            cout << "Wrong Position!" << endl;
            return false;
            break;
    }
}

// Taking book from the Library.
bool Library::take_book(int position)
{
    switch (position)
    {
        case 1:
            return topShelf->take_book();
            break;
        case 2:
            return midShelf->take_book();
            break;
        case 3:
            return botShelf->take_book();
            break;
        case 4:
            return cabinet->take_book(1);
            break;
        case 5:
            return cabinet->take_book(2);
            break;
        default:
            cout << "Wrong Position!" << endl;
            return false;
            break;
    }
}

// Placeing book random in the library.
void Library::random_places(Book** books, int NumOfBooks)
{
    int selection;
    srand(time(NULL));

    selection = rand() % 5;
    while (selection < 1 || selection > 5)
    {
        selection = rand() % 5;
    }

    cout << "Placing book in top bookcase self..." << endl;
    // place_book() return true/false.
    if (place_book(books[rand() % NumOfBooks], selection))
    {
        totalBooks++;
        cout << "Book placed successfully!" << endl;
    }
    else
    {
        cout << "Failed to place the book!" << endl;
    }

}

// Taking book from the library randomly.
void Library::random_takes()
{
    int selection;
    srand(time(NULL));

    selection = rand() % 5;
    while (selection < 1 || selection > 5)
    {
        selection = rand() % 5;
    }

    cout << "Taking the book from the top bookcase shelf" << endl;
    // take_book() returns true/false.
    if (take_book(selection))
    {
        totalBooks--;
        cout << "You took the book successfully" << endl;
    }
    else
    {
        cout << "Faild to take the book from the shelf!" << endl;
    }
}

// Printing the whole library.
void Library::print()
{
    // Printing every shelf in the library.
    topShelf->print();
    midShelf->print();
    botShelf->print();
    cabinet->print(1);
    cabinet->print(2);
}
// Destroying the library.
Library::~Library()
{
    cout << "A Library is Destructing!" << endl;
    // Deleteing evvery objected where created.
    delete base;
    delete cabinet;
    delete topShelf;
    delete midShelf;
    delete botShelf;
    cout << "A Library Destructed!" <<  endl;
}
