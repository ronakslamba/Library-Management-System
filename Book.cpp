//
//  Book.cpp
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#include "Book.h"

// when a book is created, these are its default characteristics.
Book::Book()
{
    this->bookTitle = "N/A";
    this->bookAuthor = "N/A";
    this->bookReleaseYear = "N/A";
    this->bookRating = "N/A";
    this->bookISBN = "N/A";
    this->bookBorrowedBy = nullptr;
}

Book::Book(string title, string author, string releaseYear, string rating, string ISBN)
{
    this->bookTitle = title;
    this->bookAuthor = author;
    this->bookReleaseYear = releaseYear;
    this->bookRating = rating;
    this->bookISBN = ISBN;
    this->bookBorrowedBy = nullptr;
}

// accessors

string Book::getBookTitle() const {return bookTitle;}

string Book::getBookAuthor() const {return bookAuthor;}

string Book::getBookReleaseYear() const {return bookReleaseYear;}

string Book::getBookRating() const {return bookRating;}

string Book::getBookISBN() const {return bookISBN;}

bool Book::isBookAvailable() const {return bookIsAvailable;}

Member* Book::getBookBorrowedBy() const {return bookBorrowedBy;}

// mutators
void Book::setBookTitle(string title) {bookTitle = title;}

void Book::setBookAuthor(string author) {bookAuthor = author;}

void Book::setBookReleaseYear(string releaseYear) {bookReleaseYear = releaseYear;}

void Book::setBookRating(string rating) {bookRating = rating;}

void Book::setBookISBN(string ISBN) {bookISBN = ISBN;}

void Book::setBookAvailability(bool availability) {bookIsAvailable = availability;}

void Book::setBookBorrowedBy(Member* myMember) {bookBorrowedBy = myMember;}

// OTHER METHODS

void Book::displayBookInfo(ostream& out) const
{
    out << "Title: " << getBookTitle() << endl;
    out << "Author: " << getBookAuthor() << endl;
    out << "Release Year: " << getBookReleaseYear() << endl;
    out << "Rating: " << getBookRating() << endl;
    out << "ISBN: " << getBookISBN() << endl;
    out << "Availablility: " << isBookAvailable() << endl;
    
    if (getBookBorrowedBy() != nullptr)
    {
        out << "Borrowed By: ";
        getBookBorrowedBy()->displayMember(out);
    }
    
    out << endl;
}

void Book::displayBook(ostream& out) const
{
    out << "'" + bookTitle + "'" + " by " + bookAuthor << endl;
}



