//
//  Library.cpp
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#include "Library.h"

void Library::addBook(const Book& book) 
{
    books[book.getBookISBN()] = book;
}

void Library::addMember(const Member& member)
{
    members[member.getMemberIDNumber()] = member;
}

Book* Library::findBookByISBN(const string& isbn)
{
    auto it = books.find(isbn);
    
    if (it != books.end())
    {
        return &(it->second);
    }
    
    return nullptr;
}

Member* Library::findMemberByIDNumber(const string& idNumber)
{
    auto it = members.find(idNumber);
    
    if (it != members.end())
    {
        return &(it->second);
    }
    
    return nullptr;  
}


void Library::displayAllBooks(ostream& out) const
{
    if (books.empty())
    {
        out << "No books available in the library. " << endl;
    }
    
    else
    {
        for (const auto& pair : books)
        {
            pair.second.displayBook(out);
        }
    }
}

void Library::displayAllMembers(ostream& out) const
{
    if (members.empty())
    {
        out << "No members registered with the library. " << endl;
    }
    
    else
    {
        for (const auto& pair : members)
        {
            pair.second.displayMember(out);
        }
    }
}

void Library::displayAllBooksWithDetails(ostream& out) const
{
    if (books.empty())
    {
        out << "No books available in the library. " << endl;
    }
    
    else
    {
        for (const auto& pair : books)
        {
            pair.second.displayBookInfo(out);
        }
    }
}

void Library::displayAllMembersWithDetails(ostream& out) const
{
    if (members.empty())
    {
        out << "No members registred with the library. " << endl;
    }
    
    else
    {
        for (const auto& pair : members)
        {
            pair.second.displayMemberInfo(out);
        }
    }
}
