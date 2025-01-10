//
//  Book.h
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#ifndef Book_h
#define Book_h

#include "Member.h"
#include <string>
#include <iostream>

using namespace std;

//

class Member; // forward declaration

class Book {
    
private:
    string bookTitle;
    string bookAuthor;
    string bookReleaseYear;
    string bookRating;
    string bookISBN;
    bool bookIsAvailable = true;
    Member* bookBorrowedBy = nullptr;
    
public:
    Book();

    Book(string title, string author, string releaseYear, string rating, string ISBN);
    
    // accessors
    string getBookTitle() const;
    string getBookAuthor() const;
    string getBookReleaseYear() const;
    string getBookRating() const;
    string getBookISBN() const;
    bool isBookAvailable() const;
    Member* getBookBorrowedBy() const;
    
    // mutators
    void setBookTitle(string title);
    void setBookAuthor(string author);
    void setBookReleaseYear(string releaseYear);
    void setBookRating(string rating);
    void setBookISBN(string ISBN);
    void setBookAvailability(bool availability);
    void setBookBorrowedBy(Member* myMember);

// OTHER METHODS
    
    void displayBookInfo(ostream& out) const;
    void displayBook(ostream& out) const;
    
};


#endif /* Book_h */
