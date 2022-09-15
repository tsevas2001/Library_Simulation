#include <iostream>
#include <time.h>
#include "library.h"


int main()
{   
    int SpaceShelf, NumOfBooks, NumOfPlaces, NumOfTakes;

    cout << "Enter the space for the Shelfs: ";
    cin >> SpaceShelf;
    cout << "Enter the number of books to create: ";
    cin >> NumOfBooks;
    cout << "Enter the number of how many random places will be: ";
    cin >> NumOfPlaces;
    cout << "Enter the number of how many random takes will be: ";
    cin >>  NumOfTakes;

    Book** books = new Book*[NumOfBooks];
    string Names[] = {"William Shakespeare", "Emily Dickinson", "H. P. Lovecraft", "Arthur Conan Doyle", "Leo Tolstoy", "Edgar Allan Poe", "Robert Ervin Howard", "Rabindranath Tagore"};
    string BookNames[] = {"In Search of Lost Time", "Ulysses", "Don Quixote", "One Hundred Years of Solitude", "The Great Gatsby", "Moby Dick", "War and Peace", "Hamlet"};
    srand(time(NULL));
    for(int i = 0; i < NumOfBooks; i++)
    {
        books[i] = new Book(BookNames[rand() % 8], Names[rand() % 8], rand() % 9999);
    }
    Library library(SpaceShelf);
    
    for (int i = 0; i < NumOfPlaces; i++)
        library.random_places(books, NumOfBooks);

    for (int i = 0; i < NumOfTakes; i++)
        library.random_takes();

    library.print();
    // Destroying every book.
    for (int i = 0; i < NumOfBooks; i++)
        delete books[i];
    delete[] books;
    return 0;
}