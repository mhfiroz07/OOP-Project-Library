#include<iostream>
#include<fstream>
using namespace std;
class temp{
    string id, name, author;
    fstream file;
public:
    void addTheNewBook();
    void ShowTheAllBooks();
    void ExtractAnyBook();
};
int main(){
    char choice;
    temp obj;

    cout << "-------------------\n";
    cout << "1-Show The books in collection\n";
    cout << "2-Extract any Book\n";
    cout << "3-Add any wanted Books(Admin)\n";
    cout << "4-Exit\n";
    cout << "-------------------\n";
    cout << "Enter Your Choice what you want:: ";
    cin >> choice;
    switch(choice){
        case '1':
            cin.ignore();
            obj.ShowTheAllBooks();
            break;
        case '2':
            cin.ignore();
            obj.ExtractAnyBook();
            break;
        case '3':
            cin.ignore();
            obj.addTheNewBook();
            break;
        case '4':
            break;
        default:
            cout << "Invalid Choice!!";
            return 0;
    }
    return 0;
}
void temp::addTheNewBook(){
    cout << "Enter the Book ID:: ";
    getline(cin, id);
    cout << "Enter the Book Name:: ";
    getline(cin, name);
    cout << "Enter the Book's Author name:: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}
void temp::ShowTheAllBooks(){
    file.open("bookData.txt", ios::in);
    cout << "\n\n";
    cout << "\t\tBook ID \t\t\t Book Name \t\t\t Author's Name" << endl;

    while(getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)){
        cout << "\t\t " << id << "\t\t\t" << name << "\t\t\t" << author << endl;
    }
    file.close();
}
void temp::ExtractAnyBook(){
    string search;
    cin.ignore();
    ShowTheAllBooks();
    cout << "Enter Book Id:: ";
    getline(cin, search);
    file.open("bookData.txt", ios::in);
    cout << "\n\n";
    cout << "\t\tBook ID \t\t\t Book Name \t\t\t Author's Name" << endl;
    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)){
        if (search == id) {
            cout << "\t\t " << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout << "Book Extracted Successfully in the history.";
        }
    }
    file.close();
}
