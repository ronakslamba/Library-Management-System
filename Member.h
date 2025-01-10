//
//  Member.h
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#ifndef Member_h
#define Member_h

#include "Book.h"
#include <string>
#include <vector>
#include <algorithm> // for find()

using namespace std;

//

class Book; // forward declaration, without this line there is a circular dependency error since this class uses a Book object. same thing in the Book class since it uses a Member object

class Member {
    
private:
    
    string memberFirstName;
    string memberLastName;
    string memberIDNumber;
    string memberPhoneNumber;
    vector<Book*> memberBooksBorrowed;
    
public:
    
    Member();
    Member(string firstName, string lastName, string idNumber, string phoneNumber);
    
    // accessors
    string getMemberFirstName() const;
    string getMemberLastName() const;
    string getMemberIDNumber() const;
    string getMemberPhoneNumber() const;
    vector<Book*> getMemberBooksBorrowed() const;
    
    string getMemberFullName() const;
    
    // mutators
    void setMemberFirstName(string firstName);
    void setMemberLastName(string lastName);
    void setMemberIDNumber(string idNumber);
    void setMemberPhoneNumber(string phoneNumber);
    
    void addMemberBookBorrowed(Book* myBook);
    void removeMemberBookBorrowed(Book* myBook);
    
// OTHER METHODS
    
    void displayMemberInfo(ostream& out) const;
    void displayMember(ostream& out) const;
    
    void borrowBook(Book* book, ostream& out);
    void returnBook(Book* book, ostream& out);
    
    bool isBookBorrowed(Book* book) const;
    
};


#endif /* Member_h */
