//implementation of record class
#include <iostream>
#include <istream>

#include "Record.h"
std::string Record::get_title(void) const{
	return title;
}

 std::string Record::get_author(void) const{
 	return author;
}

std::string Record::get_ISBN(void) const{
	return ISBN;
}

std::string Record::get_year(void) const{
	return year;
}

std::string Record::get_edition(void) const{
	return edition;
}



void Record::set_title(std::string s){
	title = s;
}
void Record::set_author(std::string s){
	author = s;
}
void Record::set_ISBN(std::string s){
	ISBN = s;
}
void Record::set_year(std::string s){
	year = s;
}
void Record::set_edition(std::string s){
	edition = s;
}



std::istream& operator>>(std::istream& is, Record& rec){

	std::string stuff;

	while(std::getline(is,stuff)){
		
		if (stuff.empty()){
			continue;
		}
		rec.set_title(stuff);

		std::getline(is, stuff);
		rec.set_author(stuff);

		std::getline(is, stuff);
		rec.set_ISBN(stuff);

		std::getline(is, stuff);
		rec.set_year(stuff);

		std::getline(is, stuff);
		rec.set_edition(stuff);
		return is;
		

	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Record& rec){

		os << rec.get_title() << std::endl;
		os << rec.get_author() << std::endl;
		os << rec.get_ISBN() << std::endl;
		os << rec.get_year() << std::endl;
		os << rec.get_edition() << std::endl;

	return os;
}



bool operator==(const Record& r1, const Record& r2){
	if(r1.get_title() != r2.get_title()){
		return false;
	}
	if(r1.get_author() != r2.get_author()){
		return false;
	}
	if(r1.get_ISBN() != r2.get_ISBN()){
		return false;
	}

	return true;
}

bool operator<(const Record& lhs, const Record& rhs){
	if(lhs.get_title() > rhs.get_title()){
		return false;
	}
	if(lhs.get_author() > rhs.get_author()){
		return false;
	}
	if(lhs.get_ISBN() > rhs.get_ISBN()){
		return false;
	}
	if(lhs.get_year() > rhs.get_year()){
		return false;
	}
	if(lhs.get_edition() > rhs.get_edition()){
		return false;
	}
	return true;
}