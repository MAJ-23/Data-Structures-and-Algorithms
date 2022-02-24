#include "Record.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Record rec;
    vector<Record> vec;

    // Attempt to open the file, exit on error
    ifstream ifs("Book.txt");
    if (!ifs.is_open()) {
        cout << "Book.txt not found";
        return 1;
    }
    std::cout << "Pain" << std::endl;

    // Load the records from the file into the vector,
    while (ifs >> rec) {
        std::cout << rec << "Pain"<<std::endl;
        vec.push_back(rec);
    }



    // Print the records,
    for (auto x: vec) {
        cout << x << endl << endl;
    }

    // Test comparison operation.  With given data, record will only match itself
    for (auto x: vec) {
        cout << "*************************" << endl;
        for (auto y: vec) {
            if (x == y) {
                cout << x.get_title() << endl;
                cout << x.get_author() << endl;
                cout << x.get_ISBN() << endl;
                cout << "***EQUAL***" << endl;
                cout << y.get_title() << endl;
                cout << y.get_author() << endl;
                cout << y.get_ISBN() << endl;
                cout << "-------------------------" << endl;
            }
        }
    }

    Record mine;
    mine.set_title( "Fire and Ice");
    mine.set_author("Someone that made my childhood");
    mine.set_ISBN("432-2343-234");
    mine.set_year("2007");
    mine.set_edition("First edition");
    cout << mine << endl;


    return 0;
}