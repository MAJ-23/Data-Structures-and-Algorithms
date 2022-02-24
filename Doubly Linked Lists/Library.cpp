#include "Library.h"
#include <vector>
#include <iostream>
#include <istream>

int get_index(Record r);



std::vector<Record> Library::search(const std::string title) const{
	Record temp;
	temp.set_title(title);
	int index = get_index(temp);//ok now I have the index 

	std::vector<Record> found;
	TemplatedDLList<Record>::DLListNode *cursor = book_db.at(index).first_node();

	while(cursor != book_db.at(index).after_last_node()){
		if(cursor->obj.get_title() == title){
			found.push_back(cursor->obj);
		}
		cursor = cursor->next;
	}
	return found;
}

int Library::import_database(const std::string filename){
	std::ifstream ifs(filename);

    int counter = 0;
    Record rec;
    
    while(ifs >> rec){
    	counter++;
    	add_record(rec);
    }

    return counter;
}

int Library::export_database(const std::string filename) const{
	std::ofstream of;

	of.open(filename);

	int counter = 0;
	for(int i = 0; i < 26; i++){
		TemplatedDLList<Record>::DLListNode *cursor = book_db.at(i).first_node();

		while (cursor != book_db.at(i).after_last_node()){
			of << cursor->obj << std::endl;
			counter++;
			cursor = cursor->next;
		}
	}

	of.close();

	return counter;
}


void Library::print_database() const{
	for(int i = 0; i < 26; i++){
		TemplatedDLList<Record>::DLListNode *cursor = book_db.at(i).first_node();

		while (cursor != book_db.at(i).after_last_node()){
			std::cout << cursor->obj << std::endl;
			cursor = cursor->next;
		}
	}
}

bool Library::add_record(const Record r){
	int index = get_index(r);
	book_db.at(index).insert_last(r);
	return true;
}

void Library::remove_record(const Record r){
	int index = get_index(r);
	if(index == -1){//not in latin alphabet 
		return;
	}
	TemplatedDLList<Record>::DLListNode *cursor = book_db.at(index).first_node();

	while(cursor != book_db.at(index).after_last_node()){
		if(r == cursor->obj){
			cursor = cursor->next;
			TemplatedDLList<Record>::DLListNode& ref = *cursor;
			book_db.at(index).remove_before(ref);
			break;
		}
		cursor = cursor->next;
	}
}




/*bool Library::isDup(Record r, int index){//not going to work on mimir
	TemplatedDLList<Record>::DLListNode *cursor = book_db.at(index).first_node();

	if(book_db.at(index).is_empty()){
		return false;
	}

	while(cursor != (book_db.at(index).after_last_node())){
		if(r == cursor->obj){
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}
*/


int get_index(Record r){

	//return toupper(r.get_title())[0] - 'A'

	if(r.get_title()[0] == 'A' || r.get_title()[0] == 'a'){
		return 0;
	}

	if(r.get_title()[0] == 'B' || r.get_title()[0] == 'b'){
		return 1;
	}

	if(r.get_title()[0] == 'C' || r.get_title()[0] == 'c'){
		return 2;
	}

	if(r.get_title()[0] == 'D' || r.get_title()[0] == 'd'){
		return 3;
	}

	if(r.get_title()[0] == 'E' || r.get_title()[0] == 'e'){
		return 4;
	}

	if(r.get_title()[0] == 'F' || r.get_title()[0] == 'f'){
		return 5;
	}

	if(r.get_title()[0] == 'G' || r.get_title()[0] == 'g'){
		return 6;
	}

	if(r.get_title()[0] == 'H' || r.get_title()[0] == 'h'){
		return 7;
	}

	if(r.get_title()[0] == 'I' || r.get_title()[0] == 'i'){
		return 8;
	}

	if(r.get_title()[0] == 'J' || r.get_title()[0] == 'j'){
		return 9;
	}

	if(r.get_title()[0] == 'K' || r.get_title()[0] == 'k'){
		return 10;
	}

	if(r.get_title()[0] == 'L' || r.get_title()[0] == 'l'){
		return 11;
	}

	if(r.get_title()[0] == 'M' || r.get_title()[0] == 'm'){
		return 12;
	}

	if(r.get_title()[0] == 'N' || r.get_title()[0] == 'n'){
		return 13;
	}

	if(r.get_title()[0] == 'O' || r.get_title()[0] == 'o'){
		return 14;
	}

	if(r.get_title()[0] == 'P' || r.get_title()[0] == 'p'){
		return 15;
	}

	if(r.get_title()[0] == 'Q' || r.get_title()[0] == 'q'){
		return 16;
	}

	if(r.get_title()[0] == 'R' || r.get_title()[0] == 'r'){
		return 17;
	}

	if(r.get_title()[0] == 'S' || r.get_title()[0] == 's'){
		return 18;
	}

	if(r.get_title()[0] == 'T' || r.get_title()[0] == 't'){
		return 19;
	}

	if(r.get_title()[0] == 'U' || r.get_title()[0] == 'u'){
		return 20;
	}

	if(r.get_title()[0] == 'V' || r.get_title()[0] == 'v'){
		return 21;
	}

	if(r.get_title()[0] == 'W' || r.get_title()[0] == 'w'){
		return 22;
	}

	if(r.get_title()[0] == 'X' || r.get_title()[0] == 'x'){
		return 23;
	}

	if(r.get_title()[0] == 'Y' || r.get_title()[0] == 'y'){
		return 24;
	}

	if(r.get_title()[0] == 'Z' || r.get_title()[0] == 'z'){
		return 25;
	}

	std::cout<< "FAILLLLLLLLLLL: " << r.get_title() << std:: endl;
	return 3;

}