//
//  Library.hpp
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#ifndef Library_h
#define Library_h

#include "Book.h"
#include "Member.h"

#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

class Library {
    
private:
    map<string, Book> books;  // map with ISBN as key
    map<string, Member> members;  // map with ID number as key

public:

    void addBook(const Book& book);
    
    void addMember(const Member& member);
    
    Book* findBookByISBN(const string& isbn);
    
    Member* findMemberByIDNumber(const string& idNumber);

    void displayAllBooks(ostream& out) const;
    
    void displayAllMembers(ostream& out) const;
    
    void displayAllBooksWithDetails(ostream& out) const;
    
    void displayAllMembersWithDetails(ostream& out) const;
    
};

#endif /* Library_h */
