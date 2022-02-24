#include "Library.h"
#include <fstream>
#include <iostream>
#include <vector>

int main(){
	Library *my_books = new  Library();

	Record mine1, mine2, mine3, mine4;

	mine1.set_title("Harry Potter And The Chamber Of Secrets");//make records 
	mine1.set_author("J. K. Rowling");
	mine1.set_ISBN("978-0439064873");
	mine1.set_year("2000");
	mine1.set_edition("1st edition");

	mine2.set_title("H is for Hawk");
	mine2.set_author("Helen Macdonald");
	mine2.set_ISBN("978-0802123411");
	mine2.set_year("2015");
	mine2.set_edition("1st edition");

	mine3.set_title("The Kite Runner");
	mine3.set_author("Khaled Hosseini");
	mine3.set_ISBN("978-1594631931");
	mine3.set_year("2013");
	mine3.set_edition("1st edition");

	my_books->add_record(mine1);//put records into library
	my_books->add_record(mine2);
	my_books->add_record(mine3);

	my_books->print_database();//print library

	my_books->remove_record(mine3);//remove 3rd record
	std::cout << "--------------------------------Removing Record 3 --------------------------------\n\n\n" << std::endl;
	my_books->print_database();


	my_books->add_record(mine3);
	mine4.set_title("The Kite Runner");
	mine4.set_author("Khaled Hosseini");
	mine4.set_ISBN("978-1594631931");
	mine4.set_year("2013");
	mine4.set_edition("1st edition");
	my_books->add_record(mine4);

	std::vector<Record> found_books = my_books->search("The Kite Runner");
	std::cout <<"The number of items in the vector should be 2 and IS ::::: " << found_books.size() << std::endl;


	std::cout << "----------------------------------------Importing from a file ----------------------------------\n\n\n" << std::endl;

	Library imported;
	int num = imported.import_database("Book.txt");
	std::cout << "Imported: " << num << std::endl;
	imported.print_database();




}