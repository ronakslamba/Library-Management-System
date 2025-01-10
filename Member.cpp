//
//  Member.cpp
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#include "Member.h"

Member::Member()
{
    this->memberFirstName = "N/A";
    this->memberLastName = "N/A";
    this->memberIDNumber = "N/A";
    this->memberPhoneNumber = "N/A";
}

Member::Member(string firstName, string lastName, string IDNumber, string phoneNumber)
{
    this->memberFirstName = firstName;
    this->memberLastName = lastName;
    this->memberIDNumber = IDNumber;
    this->memberPhoneNumber = phoneNumber;
}

// accessors
string Member::getMemberFirstName() const {return memberFirstName;}

string Member::getMemberLastName() const {return memberLastName;}

string Member::getMemberIDNumber() const {return memberIDNumber;}

string Member::getMemberPhoneNumber() const {return memberPhoneNumber;}

vector<Book*> Member::getMemberBooksBorrowed() const {return memberBooksBorrowed;}

string Member::getMemberFullName() const {return memberFirstName + " " + memberLastName;}

// mutators
void Member::setMemberFirstName(string firstName) {memberFirstName = firstName;}
    
void Member::setMemberLastName(string lastName) {memberLastName = lastName;}
    
void Member::setMemberIDNumber(string idNumber) {memberIDNumber = idNumber;}
    
void Member::setMemberPhoneNumber(string phoneNumber) {memberPhoneNumber = phoneNumber;}

void Member::addMemberBookBorrowed(Book* myBook)
{
    // add book to the end of the list (vector)
    memberBooksBorrowed.push_back(myBook);
}

void Member::removeMemberBookBorrowed(Book* myBook)
{
    // find myBook in the vector
    auto it = find(memberBooksBorrowed.begin(), memberBooksBorrowed.end(), myBook);

    // if myBook is found in the vector, remove (erase) it from the vector
    if (it != memberBooksBorrowed.end())
    {
        memberBooksBorrowed.erase(it);
    }
}


// OTHER METHODS

void Member::displayMemberInfo(ostream& out) const
{
    out << "Name: " << getMemberFullName() << endl;
    out << "ID Number: " << getMemberIDNumber() << endl;
    out << "Contact: " << getMemberPhoneNumber() << endl;
    
    if(memberBooksBorrowed.size() > 0)
    {
        out << "Books Borrowed: ";
        
        vector<Book*> books = getMemberBooksBorrowed();
        
        for(int i = 0; i < books.size(); i++)
        {
            out << "'" << (books.at(i))->getBookTitle() << "'";
            if(i != books.size() - 1)
            {
                out << ", ";
            }
        }
        
        out << endl;
    }
    
    out << endl;
}

void Member::displayMember(ostream& out) const
{
    out << memberLastName << ", " << memberFirstName << endl;
}

void Member::borrowBook(Book* book, ostream& out)
{
    if(book->isBookAvailable())
    {
        book->setBookAvailability(0);
        book->setBookBorrowedBy(this); // so we can see which member is borrowing this book
        addMemberBookBorrowed(book); // so we can see which book this member is borrowing
        
        out << "Success. " << "'" << book->getBookTitle() << "'" << " has been borrowed by " << "'" << getMemberFullName() << "'." << endl << endl;
    }
    
    else
    {
        out << "Error. " << "'" << book->getBookTitle() << "'" << " is currently being borrowed by another member." << endl << endl;
    }
}

void Member::returnBook(Book* book, ostream& out)
{
    if(!(this->isBookBorrowed(book))) // make sure the right Member is returning it
    {
        out << "Error. " << "'" << book->getBookTitle() << "'" << " is not currently being borrowed by " << "'";
        displayMember(out);
        out << "'" << "." << endl << endl;
    }
    
    else
    {
        book->setBookAvailability(1);
        book->setBookBorrowedBy(nullptr);
        removeMemberBookBorrowed(book);
        
        out << "Success. " << "'" << book->getBookTitle() << "'" << " has been returned by " << "'" << getMemberFullName() << "', and is now eligible to be borrowed by other members." << endl << endl;
    }
    
}

bool Member::isBookBorrowed(Book* book) const
{
    // search for book in vector
    auto it = find(memberBooksBorrowed.begin(), memberBooksBorrowed.end(), book);

    // if it doesn't equal the end, it means the book is somewhere in the vector.
    return it != memberBooksBorrowed.end();
}
