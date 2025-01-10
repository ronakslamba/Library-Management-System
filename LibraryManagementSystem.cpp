//
//  main.cpp
//  Library Project
//
//  Created by Ronak Lamba on 1/8/25.
//

#include "Library.h"

void home(ostream& out, istream& in, Library* myLibrary);

void viewBookDatabase(ostream& out, istream& in, Library* myLibrary);
void viewBookDatabaseAdvanced(ostream& out, istream& in, Library* myLibrary);

void searchBookByISBN(ostream& out, istream& in, Library* myLibrary);

void viewMemberDatabase(ostream& out, istream& in, Library* myLibrary);
void viewMemberDatabaseAdvanced(ostream& out, istream& in, Library* myLibrary);

void searchMemberByIDNumber(ostream& out, istream& in, Library* myLibrary);

void newMembership(ostream& out, istream& in, Library* myLibrary);

void processBorrow(ostream& out, istream& in, Library* myLibrary);

void processReturn(ostream& out, istream& in, Library* myLibrary);

//void help();

string createFourDigitIDNumber(Library* myLibrary);

void defaultSwitch(ostream& out, istream& in, int x, Library* myLibrary);
bool isNumeric(const string& s);

// input
int getValidIntInput(ostream& out, istream& in, int min, int max);
string getValidISBN(ostream& out, istream& in, Library* myLibrary);
string getValidIDNumber(ostream& out, istream& in, Library* myLibrary);
string getValidName(ostream& out, istream& in, Library* myLibrary);
string getValidPhoneNumber(ostream& out, istream& in, Library* myLibrary);


void fillBookDatabase(Library* myLibrary);
void fillMemberDatabase(Library* myLibrary);

int main()
{
    Library myLibrary;
    
    fillBookDatabase(&myLibrary);
    fillMemberDatabase(&myLibrary);
    
    cout << "*********************************************************************" << endl;
    cout << "************* Welcome to the Library Management System! *************" << endl;
    
    home(cout, cin, &myLibrary);
    
}

string createFourDigitIDNumber(Library* myLibrary)
{
    string random = "0000";
    while(1)
    {
        // create random 4 digit number (x)
        //srand(time(0));
        srand(static_cast<unsigned int>(time(0)));
        
        int x = rand() % 9000 + 1000; // (0 to 8999) + 1000 gives us a number in the range 1000-9999
        random = to_string(x);
        
        Member* newMember = myLibrary->findMemberByIDNumber(random);
        
        if(newMember == nullptr) // make sure a member doesn't already have this id number
        {
            return random;
        }
    }
}

void defaultSwitch(ostream& out, istream& in, int x, Library* myLibrary)
{
    switch(x)
    {
        case 0:
            out << "Thank you for using the Library Management System. " << endl;
            exit(0);
        case 1:
            home(out, in, myLibrary);
            break;
        default:
            break;
    }
}

int getValidIntInput(ostream& out, istream& in, int min, int max)
{
    int x;
    while (true) 
    {
        out << "(" << min << "-" << max << ") : ";
        in >> x;
        if (in.fail()) 
        {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            out << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } 
        else if (x < min || x > max) {
            out << "Input out of range. Please enter a number between " << min << " and " << max << ": ";
        } 
        else
        {
            break;
        }
    }
    return x;
}

bool isNumeric(const string& s) 
{
    return all_of(s.begin(), s.end(), ::isdigit);
}

string getValidISBN(ostream& out, istream& in, Library* myLibrary)
{
    string ISBN;
    while (true) {
        in >> ISBN;
        if (isNumeric(ISBN) && ISBN.length() == 13)
        {
            return ISBN;
        }
        else
        {
            if(ISBN == "0")
            {
                defaultSwitch(out, in, 0, myLibrary);
            }
            if(ISBN == "1")
            {
                home(out, in, myLibrary);
            }
            out << "Invalid ISBN." << endl << "Please enter a valid 13 digit ISBN: ";
        }
    }
}

string getValidIDNumber(ostream& out, istream& in, Library* myLibrary)
{
    string ID;
    while (true) {
        in >> ID;
        if (isNumeric(ID) && ID.length() == 4)
        {
            return ID;
        }
        else
        {
            if(ID == "0")
            {
                defaultSwitch(out, in, 0, myLibrary);
            }
            if(ID == "1")
            {
                home(out, in, myLibrary);
            }
            out << "Invalid ID number." << endl << "Please enter a valid 4 digit ID number: ";
        }
    }
}

string getValidName(ostream& out, istream& in, Library* myLibrary)
{
    string name;
       bool isValid = false;

       while (!isValid) 
       {
           isValid = true;
           in >> name;

           for (char c : name) 
           {
               if (!isalpha(c))
               {
                   isValid = false;
                   if(name == "0")
                   {
                       defaultSwitch(out, in, 0, myLibrary);
                   }
                   if(name == "1")
                   {
                       home(out, in, myLibrary);
                   }
                   cout << "Invalid name. " << endl << "Name must contain only letters: ";
                   break;
               }
           }

           if (isValid) 
           {
               return name;
           }
       }

       return name;
}

string getValidPhoneNumber(ostream& out, istream& in, Library* myLibrary)
{
    string number;
    while (true) 
    {
        in >> number;
        if (isNumeric(number) && number.length() == 10)
        {
            return number;
        }
        else
        {
            if(number == "0")
            {
                defaultSwitch(out, in, 0, myLibrary);
            }
            if(number == "1")
            {
                home(out, in, myLibrary);
            }
            out << "Invalid phone number." << endl << "Please enter a valid 10 digit phone number: ";
        }
    }
}

void home(ostream& out, istream& in, Library* myLibrary)
{
    cout << "*********************************************************************" << endl;
    cout << "**************************** 1. Home ********************************" << endl;
    cout << "Please enter the corresponding number to access the intended pathway:" << endl;
    cout << "0. End Session" << endl;
    cout << "1. Home" << endl;
    cout << "2. Book Database" << endl;
    cout << "3. Search Book by ISBN" << endl;
    cout << "4. Member Database" << endl;
    cout << "5. Search Member by ID Number" << endl;
    cout << "6. New Membership" << endl;
    cout << "7. Process Borrow" << endl;
    cout << "8. Process Return" << endl;
    cout << "9. Help" << endl;
    cout << "*********************************************************************" << endl;
    cout << endl;
    
    int x = getValidIntInput(out, in, 0, 9);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    else
    {
        switch(x)
        {
            case 2:
                viewBookDatabase(out, in, myLibrary);
                break;
            case 3:
                searchBookByISBN(out, in, myLibrary);
                break;
            case 4:
                viewMemberDatabase(out, in, myLibrary);
                break;
            case 5:
                searchMemberByIDNumber(out, in, myLibrary);
                break;
            case 6:
                newMembership(out, in, myLibrary);
                break;
            case 7:
                processBorrow(out, in, myLibrary);
                break;
            case 8:
                processReturn(out, in, myLibrary);
                break;
            case 9:
                //help();
                break;
            default:
                break;
        }
    }
    
}

void viewBookDatabase(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************ 2. Book Database ***************************" << endl;
    out << endl;
    
    myLibrary->displayAllBooks(out);
    
    out << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Advanced View" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        viewBookDatabaseAdvanced(out, in, myLibrary);
    }
}

void viewBookDatabaseAdvanced(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************ 2. Book Database ***************************" << endl;
    out << endl;
    
    myLibrary->displayAllBooksWithDetails(out);
    
    out << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Simple View" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        viewBookDatabase(out, in, myLibrary);
    }
}

void searchBookByISBN(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "********************** 3. Search Book By ISBN ***********************" << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Conduct Search" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        out << "Enter ISBN: ";
        string s = getValidISBN(out, in, myLibrary);
        
        Book* newBook = myLibrary->findBookByISBN(s);
        
        if(newBook != nullptr)
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "********************** 3. Search Book By ISBN ***********************" << endl;
            out << endl;
            
            out << "ISBN: " << s << endl << endl;
            newBook->displayBookInfo(out);
            out << endl << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                searchBookByISBN(out, in, myLibrary);
            }
        }
        else
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "********************** 3. Search Book By ISBN ***********************" << endl;
            out << endl;
            
            out << "ISBN: " << s << endl << endl;
            out << "No results. " << endl;
            out << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                searchBookByISBN(out, in, myLibrary);
            }
        }
    }
}

void viewMemberDatabase(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************* 4. Member Database ************************" << endl;
    out << endl;
    
    myLibrary->displayAllMembers(out);
    
    out << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Advanced View" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        viewMemberDatabaseAdvanced(out, in, myLibrary);
    }
}

void viewMemberDatabaseAdvanced(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************* 4. Member Database ************************" << endl;
    out << endl;
    
    myLibrary->displayAllMembersWithDetails(out);
    
    out << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Simple View" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        viewMemberDatabase(out, in, myLibrary);
    }
}

void searchMemberByIDNumber(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "******************* 5. Search Member By ID Number *******************" << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Conduct Search" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        out << "Enter ID Number: ";
        string s = getValidIDNumber(out, in, myLibrary);
        
        Member* newMember = myLibrary->findMemberByIDNumber(s);
        
        if(newMember != nullptr)
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "******************* 5. Search Member By ID Number *******************" << endl;
            out << endl;
            
            out << "ID Number: " << s << endl << endl;
            newMember->displayMemberInfo(out);
            out << endl << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                searchMemberByIDNumber(out, in, myLibrary);
            }
        }
        
        else
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "******************* 5. Search Member By ID Number *******************" << endl;
            out << endl;
            
            out << "ID Number: " << s << endl << endl;
            out << "No results. " << endl;
            out << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                searchMemberByIDNumber(out, in, myLibrary);
            }
        }
    }
}


void newMembership(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************* 6. New Membership *************************" << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Begin Membership Process" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        string firstName, lastName, phoneNumber, idNumber;
        int a = 0, b = 0, c = 0, d = 0;
        
        while(d != 1)
        {
            while(a != 1)
            {
                out << endl;
                out << "New Member's First Name: ";
                firstName = getValidName(out, in, myLibrary);
                
                out << endl;
                out << "Entered First Name: " << firstName << endl;
                out << "Enter 0 to try again. Enter 1 to confirm first name. " << endl;
                a = getValidIntInput(out, in, 0, 1);
            }
            
            while(b != 1)
            {
                out << endl;
                out << "New Member's Last Name: ";
                lastName = getValidName(out, in, myLibrary);
                
                out << endl;
                out << "Entered Last Name: " << lastName << endl;
                out << "Enter 0 to try again. Enter 1 to confirm last name. " << endl;
                b = getValidIntInput(out, in, 0, 1);
            }
            
            while(c != 1)
            {
                out << endl;
                out << "New Member's Phone Number: ";
                phoneNumber = getValidPhoneNumber(out, in, myLibrary);
                
                out << endl;
                out << "Entered Phone Number: " << phoneNumber << endl;
                out << "Enter 0 to try again. Enter 1 to confirm phone number. " << endl;
                c = getValidIntInput(out, in, 0, 1);
            }
            
            out << endl << "Process Complete... " << endl << endl;
            
            out << "New Member Details: " << endl;
            out << "Name: " << firstName << " " << lastName << endl;
            out << "Phone Number: " << phoneNumber << endl << endl;
            
            out << "Enter 0 to exit membership process." << endl << "Enter 1 to confirm details and complete membership registration." << endl << "Enter 2 to restart membership process." << endl;
            d = getValidIntInput(out, in, 0, 2);
                
            if(d == 0)
            {
                home(out, in, myLibrary);
                break;
            }
            
            a = 0; b = 0; c = 0;
        }
            
        idNumber = createFourDigitIDNumber(myLibrary);
        
        Member newMember(firstName, lastName, idNumber, phoneNumber);
        myLibrary->addMember(newMember);
        
        out << endl;
        out << "*********************************************************************" << endl;
        out << "************************* 6. New Membership *************************" << endl;
        out << endl;
        
        out << "Success. New member added to the system: " << endl << endl;
        newMember.displayMemberInfo(out);
        
        out << "Please enter the corresponding number to access the intended pathway:" << endl;
        out << "0 - End Session" << endl;
        out << "1 - Home" << endl;
        out << "*********************************************************************" << endl;
        out << endl;
        
        int x = getValidIntInput(out, in, 0, 1);
        
        if(x == 0 || x == 1)
        {
            defaultSwitch(out, in, x, myLibrary);
        }
    }
}



void processBorrow(ostream& out, istream& in, Library* myLibrary)
{
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************* 7. Process Borrow *************************" << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Begin Borrow Process" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        out << "Enter ISBN Number: ";
        string i = getValidISBN(out, in, myLibrary);
        
        Book* book = myLibrary->findBookByISBN(i);
        
        if(book != nullptr)
        {
            out << endl;
            out << "Book: ";
            book->displayBook(out);
            out << "Copies Available: " << book->isBookAvailable() << endl;
            out << endl;
            if(book->isBookAvailable())
            {
                out << "Enter ID Number: ";
                string s = getValidIDNumber(out, in, myLibrary);
                out << endl;
            
                Member* member = myLibrary->findMemberByIDNumber(s);
                member->borrowBook(book, out);
            }
            else
            {
                out << "Book is currently being borrowed by another member. Please try again later." << endl << endl;
            }
            out << endl;
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 1);

            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
        }
        else
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "************************* 7. Process Borrow *************************" << endl;
            out << endl;
            
            out << "ISBN: " << i << endl << endl;
            out << "No results. " << endl;
            out << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                processBorrow(out, in, myLibrary);
            }
        }
        
        
    }
}



void processReturn(ostream& out, istream& in, Library* myLibrary)
{
    // as of now, a book can be returned by the wrong owner. need to fix.
    out << endl;
    out << "*********************************************************************" << endl;
    out << "************************* 8. Process Return *************************" << endl;
    out << "Please enter the corresponding number to access the intended pathway:" << endl;
    out << "0 - End Session" << endl;
    out << "1 - Home" << endl;
    out << "2 - Begin Return Process" << endl;
    out << "*********************************************************************" << endl;
    out << endl;
    
    int x = getValidIntInput(out, in, 0, 2);

    if(x == 0 || x == 1)
    {
        defaultSwitch(out, in, x, myLibrary);
    }
    
    if(x == 2)
    {
        out << "Enter ISBN Number: ";
        string i = getValidISBN(out, in, myLibrary);
        
        out << endl;
        
        Book* book = myLibrary->findBookByISBN(i);
        if(book != nullptr)
        {
            out << endl;
            out << "Book: ";
            book->displayBook(out);
            out << "Copies Available: " << book->isBookAvailable() << endl;
            out << endl;
            if(!(book->isBookAvailable()))
            {
                out << "Enter ID Number: ";
                string s = getValidIDNumber(out, in, myLibrary);
                
                out << endl;
            
                Member* member = myLibrary->findMemberByIDNumber(s);
                
                // check HERE if book is in member's checked out list. if yes, go forward, if not, tell them they don't have it checked out.
                
                member->returnBook(book, out);
            }
            else
            {
                out << "Book is not currently checked out by anyone. If you would like to borrow, please navigate to 'Home' and then select 'Process Borrow'." << endl << endl;
            }
            out << endl;
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 1);

            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
        }
        else
        {
            out << endl;
            out << "*********************************************************************" << endl;
            out << "************************* 8. Process Return *************************" << endl;
            out << endl;
            
            out << "ISBN: " << i << endl << endl;
            out << "No results. " << endl;
            out << endl;
            
            out << "Please enter the corresponding number to access the intended pathway:" << endl;
            out << "0 - End Session" << endl;
            out << "1 - Home" << endl;
            out << "2 - Back" << endl;
            out << "*********************************************************************" << endl;
            out << endl;
            
            int x = getValidIntInput(out, in, 0, 2);
            
            if(x == 0 || x == 1)
            {
                defaultSwitch(out, in, x, myLibrary);
            }
            
            if(x == 2)
            {
                processReturn(out, in, myLibrary);
            }
        }
        
        
    }
}

/*
void help(ostream& out)
{
}
*/

void fillBookDatabase(Library* myLibrary)
{
    Book book1("The Stranger", "Albert Camus", "1946", "4.21/5", "9780679720201");
    Book book2("On the Road", "Jack Kerouac", "1957", "3.80/5", "9780679720534");

    myLibrary->addBook(book1);
    myLibrary->addBook(book2);
}

void fillMemberDatabase(Library* myLibrary)
{
    Member member1("Roger", "Waters", "0001", "9788626545");
    Member member2("Ryan", "Reynolds", "0002", "6035836439");
    
    myLibrary->addMember(member1);
    myLibrary->addMember(member2);
}
