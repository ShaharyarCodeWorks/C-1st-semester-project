
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define Student structure
struct Student {
int studentID;
string name;
};

// Define Book structure
struct Book {
string isbn, title, author, edition, publication;
Student student; // Include student directly in the Book structure
bool issued;
};

const int maxBooks = 100;
Book books[maxBooks]; // Array to store books

// Function prototypes
void addBook(int& counter);
void deleteBook(int& counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void issueBook(int counter);
void issuedBookList(int& counter);

// Function to add a book

void addBook(int& counter) {
if (counter < maxBooks) {
cout << "ADD BOOK\n\n";
cout << "Enter ISBN: ";
getline(cin, books[counter].isbn);
cout << "Enter Title: ";
getline(cin, books[counter].title);
cout << "Enter Author: ";
getline(cin, books[counter].author);
cout << "Enter Edition: ";
getline(cin, books[counter].edition);
cout << "Enter Publication: ";
getline(cin, books[counter].publication);
counter++; // Increment the counter as a new book has been added
cout << "\nBOOK ADDED SUCCESSFULLY!\n";
} else {
cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n";
}
}

// Function to delete a book (restricted)
void deleteBook(int& counter) {
cout << "RESTRICTED!\n";
}

// Function to search for a book
void searchBook(int counter) {
if (counter == 0) {
cout << "THERE IS NO BOOK TO SEARCH!\n";
return;
}

string searchISBN;
cout << "SEARCH BOOK\n\n";
cout << "Enter ISBN to search: ";
getline(cin, searchISBN);

bool bookFound = false;

for (int i = 0; i < counter; i++) {
if (books[i].isbn == searchISBN) {
cout << "\nBOOK FOUND!\n\n";
cout << "ISBN: " << books[i].isbn << endl;
cout << "TITLE: " << books[i].title << endl;
cout << "AUTHOR: " << books[i].author << endl;
cout << "EDITION: " << books[i].edition << endl;
cout << "PUBLICATION: " << books[i].publication << endl;
bookFound = true;
break; // No need to continue searching once the book is found
}
}

if (!bookFound) {
cout << "\nBOOK NOT FOUND!\n";
}
}

// Function to view all books
// Function to view all books and save to "khan1.txt"
void viewAllBooks(int counter) {
    cout << "VIEW ALL BOOKS\n\n";

    ofstream File("khan1.txt", ios::app); // Open "khan1.txt" for appending

    if (File.is_open()) {
        for (int i = 0; i < counter; i++) {
            cout << "BOOK DETAILS\n\n";
            cout << "ISBN: " << books[i].isbn << endl;
            cout << "TITLE: " << books[i].title << endl;
            cout << "AUTHOR: " << books[i].author << endl;
            cout << "EDITION: " << books[i].edition << endl;
            cout << "PUBLICATION: " << books[i].publication << endl << endl;

            // Save to "khan1.txt"
            File << "BOOK DETAILS\n\n";
            File << "ISBN: " << books[i].isbn << endl;
            File << "TITLE: " << books[i].title << endl;
            File << "AUTHOR: " << books[i].author << endl;
            File << "EDITION: " << books[i].edition << endl;
            File << "PUBLICATION: " << books[i].publication << endl << endl;
        }

        File.close();
        cout << "BOOK RECORDS SAVED SUCCESSFULLY!\n";
    } else {
        cout << "UNABLE TO OPEN FILE  FOR WRITING!\n";
    }
}

// Function to issue a book
void issueBook(int counter) {
if (counter == 0) {
cout << "THERE IS NO BOOK TO ISSUE!\n";
return;
}

string issueISBN;
cout << "ISSUE BOOK\n\n";
cout << "Enter ISBN to issue: ";
getline(cin, issueISBN);

for (int i = 0; i < counter; i++) {
if (books[i].isbn == issueISBN) {
if (!books[i].issued) {
// Mark the book as issued
books[i].issued = true;

// Get student information
cout << "Enter Student ID: ";
cin >> books[i].student.studentID;
cin.ignore(); // Ignore the newline character in the input buffer

cout << "Enter Student Name: ";
getline(cin, books[i].student.name);

cout << "\nBOOK ISSUED SUCCESSFULLY!\n";
} else {
cout << "\nBOOK IS ALREADY ISSUED!\n";
}
return;
}
}

cout << "\nBOOK NOT FOUND!\n";
}

// Function to display the list of issued books
void issuedBookList() {
ofstream File("Khan.txt", ios::app);

if (File.is_open()) {
File << "ISSUED BOOK LIST\n\n";

for (int i = 0; i < maxBooks; i++) {
if (books[i].issued) {
cout << "ISBN: " << books[i].isbn << endl;
cout << "TITLE: " << books[i].title << endl;
cout << "AUTHOR: " << books[i].author << endl;
cout<< "EDITION: " << books[i].edition << endl;
cout << "PUBLICATION: " << books[i].publication << endl;
cout << "ISSUED TO:\n";
cout << "Student ID: " << books[i].student.studentID << endl;
cout << "Student Name: " << books[i].student.name << endl << endl;
}
}
File.close();
cout << "ISSUED BOOK LIST SAVED SUCCESSFULLY!\n";

} else {
cout << "UNABLE TO OPEN FILE FOR WRITING!\n";
}
}
int main() {
int counter = 0;
string choice;

do {
// Display menu
cout<<endl;
cout<<"SOFTWARE DEVELOPED BY SHAHARYAR KHAN\n\n";
cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
cout << "[1] ADD BOOK\n";
cout << "[2] DELETE BOOK\n";
cout << "[3] SEARCH BOOK\n";
cout << "[4] VIEW ALL BOOKS\n";
cout << "[5] ISSUE BOOK\n";
cout << "[6] ISSUED BOOK LIST\n";
cout << "[7] QUIT\n\n";
cout << "ENTER CHOICE: ";
getline(cin, choice);
system("CLS");
// Process user choice
switch (stoi(choice)) {
case 1:
addBook(counter);
break;
case 2:
deleteBook(counter);
break;
case 3:
searchBook(counter);
break;
case 4:
viewAllBooks(counter);
break;
case 5:
issueBook(counter);
break;
case 6:
issuedBookList();
break;
case 7:
exit(0);
default:
break;

}
} while (true);
return 0;
}





