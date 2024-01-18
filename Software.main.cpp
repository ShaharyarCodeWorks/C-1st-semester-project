#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    string name;
    string phoneNumber;
    int id;
    string program;
    double marks;
    char grade;
};

void writeToFile(Student students[], int count) {
    ofstream file("D:\\ARSALAN\\student_result.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << students[i].name << "\n" << students[i].phoneNumber << "\n"
                 << students[i].id << "\n" << students[i].program << "\n"
                 << students[i].marks << endl;
        }
        file.close();
    } else {
        cout << "Error in opening file." << endl;
    }
}

void readFromFile(Student students[],int & count) {
    ifstream file("D:\\ARSALAN\\student_result.txt");
    if (file.is_open()) {
        count = 0;
        while (file >> students[count].name >> students[count].phoneNumber >> students[count].id
                     >> students[count].program >> students[count].marks >> students[count].grade) {
            count++;
        }
        file.close();
    } else {
        cout << "File not found." << endl;
    }
}

void displayStudent(const Student &student) {
    cout << "Name: \t" << student.name << endl;
    cout << "Phone Number: " << student.phoneNumber << endl;
    cout << "ID:  \t " << student.id << endl;
    cout << "Program:\t" << student.program << endl;
    cout << "Marks:\t " << student.marks << endl;
}

int main() {
    Student students[100];
    int studentCount = 0;

    readFromFile(students, studentCount);

    int choice;
    do {
        cout << "1. Register a student\n";
        cout << "2. Search for a student by ID\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:

                    cout << "Enter student details:\n";
                    cout << "Name: ";
                    cin >> students[studentCount].name;
                    cout << "Phone Number: ";
                    cin >> students[studentCount].phoneNumber;
                    cout << "ID: ";
                    cin >> students[studentCount].id;
                    cout << "Program: ";
                    cin >> students[studentCount].program;
                    cout << "Marks: ";
                    cin >> students[studentCount].marks;

                    studentCount++;
                   writeToFile(students, studentCount);
                   cout<<"Registration successful. \n\n";

                break;
            case 2:
                int searchId;
                cout << "Search by ID: "<<endl;
                cin >> searchId;

                bool found=false;

                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == searchId) {
                        displayStudent(students[i]);
                        found = true;
                        break;
                    }
                }
                     if (!found) {
                    cout << "Student not found.\n";
                }
                        break;

            Default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice <= 2);

    return 0;
}
