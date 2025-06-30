#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string id, name, author;
    fstream file;
public:
    void addBook();
    void showAll();
    void extractBook();
};

int main() {
    char choice;
    temp obj;

    cout << "-------------------\n";
    cout << "1-Show All Books\n";
    cout << "2-Extract Book\n";
    cout << "3-Add Books(Admin)\n";
    cout << "4-Exit\n";
    cout << "-------------------\n";
    cout << "Enter Your Choice :: ";
    cin >> choice;

    switch (choice) {
        case '1':
            cin.ignore();
            obj.showAll();
            break;

        case '2':
            cin.ignore();
            obj.extractBook();
            break;

        case '3':
            cin.ignore();
            obj.addBook();
            break;

        case '4':
            break;

        default:
            cout << "Invalid Choice!!";
            return 0;
    }
    return 0;
}

void temp::addBook() {
    cout << "Enter Book ID:: ";
    getline(cin, id);
    cout << "Enter Book Name:: ";
    getline(cin, name);
    cout << "Enter Book's Author name:: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp::showAll() {
    file.open("bookData.txt", ios::in);
    cout << "\n\n";
    cout << "\t\tBook ID \t\t\t Book Name \t\t\t Author's Name" << endl;

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        cout << "\t\t " << id << "\t\t\t" << name << "\t\t\t" << author << endl;
    }
    file.close();
}

void temp::extractBook() {
    string search;

    cin.ignore();
    showAll();
    cout << "Enter Book Id:: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    cout << "\n\n";
    cout << "\t\tBook ID \t\t\t Book Name \t\t\t Author's Name" << endl;

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        if (search == id) {
            cout << "\t\t " << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout << "Book Extracted Successfully";
        }
    }
    file.close();
}
