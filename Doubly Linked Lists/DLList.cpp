// implementation of the DLList class


/*
NOTES

make sure nothing can be inserted before header nor after trailer 
add insert last before going to mimir

*/
#include "DLList.h"


DLList::DLList(): header(0), trailer(0){
	header.next = &trailer;
	trailer.prev = &header;
}

DLList::DLList(const DLList& dll){
	header.next = &trailer;
	trailer.prev = &header;

	DLListNode *node = dll.first_node();
	while(node != dll.after_last_node()){
		insert_last(node->obj);
		node = node->next;
	}
}// copy constructor

DLList::DLList(DLList&& dll){//FIXME handle if the list is empty
	if(dll.is_empty()){
		header.next = &trailer;
		trailer.prev = &header;
		return;
	}
	header.next = dll.header.next;
	trailer.prev = dll.trailer.prev;

	dll.header.next->prev = &header;
	trailer.prev->next = &trailer;

	dll.header.next = &dll.trailer;
	dll.trailer.prev = &dll.header;
} // move constructor

DLList::~DLList(){
	make_empty();
} // destructor

DLList& DLList::operator=(const DLList& dll){
	if(this != &dll)
	{
		if(!this->is_empty())
		{
			make_empty();
		}
		
		DLListNode *node = dll.first_node();
		while(node != dll.after_last_node())
		{
			insert_last(node->obj);
			node = node->next;
		}
	}
	return *this;
} // copy assignment operator

DLList& DLList::operator=(DLList&& dll){
	if(this != &dll)
	{
		if(!(this->is_empty()))
		{
			make_empty();
		}
		header.next = dll.header.next;
		trailer.prev = dll.trailer.prev;

		dll.header.next->prev = &header;
		trailer.prev->next = &trailer;

		dll.header.next = &dll.trailer;
		dll.trailer.prev = &dll.header;
	}
	return *this;
} // move assignment operator

// return the pointer to the first node (header's next)
DLList::DLListNode* DLList::first_node() const{
	if(is_empty())
		return after_last_node();
	return header.next;
}

// return the pointer to the trailer
DLList::DLListNode* DLList::after_last_node() const{
	return trailer.prev->next;
}

// return if the list is empty
bool DLList::is_empty() const{
	return header.next == &trailer || trailer.prev == &header;
}
int DLList::first() const{
	if(is_empty())
		throw std::runtime_error("empty list, nothing to return");
	return header.next->obj;
} // return the first object

int DLList::last() const{
	if(is_empty())
		throw std::runtime_error("empty list, nothing to return");
	return trailer.prev->obj;
} // return the last object

void DLList::insert_first(const int obj){
	DLListNode *newNode = new DLListNode(obj, &header, header.next);
	header.next ->prev = newNode;
	header.next = newNode;

}// insert to the first node

int DLList::remove_first(){
	if(is_empty()){
		throw std::runtime_error("Nothing to remove, list is empty");
	}
	DLListNode *cursor = header.next;
	cursor->next->prev = &header;
	header.next = cursor->next;
	int obj = cursor->obj;
	delete cursor;
	return obj;
} // remove the first node

void DLList::insert_last(const int obj){
	DLListNode *newNode = new DLListNode(obj, trailer.prev,&trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
} // insert to the last node

int DLList::remove_last(){
	if(is_empty())
		throw std::runtime_error("List is empty, nothing to remove");
	DLListNode *cursor = trailer.prev;
	cursor->prev->next = &trailer;
	trailer.prev = cursor->prev;
	int obj = cursor -> obj;
	delete cursor;
	return obj;
} // remove the last node

void DLList::insert_after(DLListNode &p, const int obj){
	if(is_empty()){//check if the node you want to insert after is in the DLL
		return;
	}
	DLListNode *newNode = new DLListNode(obj,&p,p.next);
	p.next->prev = newNode;
	p.next = newNode;
}

void DLList::insert_before(DLListNode &p, const int obj){
	if(is_empty()){//check if the node you want to insert after is in the DLL
		return;
	}
	DLListNode *newNode = new DLListNode(obj,p.prev,&p);
	p.prev->next = newNode;
	p.prev = newNode;
}
int DLList::remove_after(DLListNode &p){

	if(is_empty()){
		throw std::exception();
	}
	if(p.next == &trailer){//this was changed from &p == 
		throw std::exception();//trying to remove the trailer 
	}
	DLListNode *temp = p.next;
	temp->next->prev = &p;
	p.next = temp->next;
	int obj = temp->obj;
	delete temp;
	return obj;
	
}
int DLList::remove_before(DLListNode &p){
	if(is_empty()){
		throw std::exception();
	}
	if(p.prev == &header)
	{
		throw std::exception();
	}
	DLListNode *temp = p.prev;
	temp->prev->next = &p;
	p.prev = temp->prev;
	int obj = temp->obj;
	delete temp;
	return obj;
}

void DLList::make_empty(void){//will work after oveloading the operators 
	DLListNode *previous, *cursor = header.next;
	while(cursor != &trailer)
	{
		previous = cursor; 
		cursor = cursor->next;
		delete previous;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

std::ostream& operator<<(std::ostream &out, const DLList &dll){
	if(dll.is_empty())
	{
		out << ", ";
	}
	DLList::DLListNode *cursor = dll.first_node();
	while(cursor != dll.after_last_node())
	{
		out << cursor->obj << ", ";
		cursor = cursor->next;
	}
	return out;
}
