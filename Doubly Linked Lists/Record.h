#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>

class Record {
private:
    //member variables
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    std::string edition;
public:
    //accessor/mutator functions
    std::string get_title(void) const;
    std::string get_author(void) const;
    std::string get_ISBN(void) const;
    std::string get_year(void) const;
    std::string get_edition(void) const;

    void set_title(std::string s);
    void set_author(std::string s);
    void set_ISBN(std::string s);
    void set_year(std::string s);
    void set_edition(std::string s);

    
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
bool operator<(const Record& lhs, const Record& rhs);
#endif