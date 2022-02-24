// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>

// doubly linked list class
template <typename T>
class TemplatedDLList {
public:
// doubly linked list node
  struct DLListNode {
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
  };
private:
  DLListNode header, trailer;
public:
  TemplatedDLList(void): header(T()), trailer(T()){
    header.next = &trailer;
    trailer.prev = &header;
  } // default constructor 

  TemplatedDLList(const TemplatedDLList<T>& dll){
    header.next = &trailer;
    trailer.prev = &header;

    DLListNode *node = dll.first_node();
    while(node != dll.after_last_node()){
      insert_last(node->obj);
      node = node->next;
  }
  } // copy constructor

  TemplatedDLList(TemplatedDLList<T>&& dll){
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

  ~TemplatedDLList(){
    make_empty();
  } // destructor
  TemplatedDLList<T>& operator=(const TemplatedDLList<T>& dll){
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

  TemplatedDLList<T>& operator=(TemplatedDLList<T>&& dll){
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

  // return the pointer to the first node
  DLListNode *first_node(void) const{
    if(is_empty())
      return after_last_node();
    return header.next;
  }

  // return the pointer to the trailer
  DLListNode* after_last_node(void) const{
    return trailer.prev->next;
  }

  // return true if the list is empty
  bool is_empty(void) const{
    return header.next == &trailer || trailer.prev == &header;
  }

  T first(void) const{
    if(is_empty())
      throw std::runtime_error("empty list, nothing to return");
    return header.next->obj;
  } // return the first object

  T last(void) const{
    if(is_empty())
      throw std::runtime_error("empty list, nothing to return");
    return trailer.prev->obj;
  } // return the last object

  void insert_first(const T obj){
    DLListNode *newNode = new DLListNode(obj, &header, header.next);
    header.next ->prev = newNode;
    header.next = newNode;
  } // insert to the first node

  T remove_first(){
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

  void insert_last(const T obj){
    DLListNode *newNode = new DLListNode(obj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
  } // insert to the last node

  T remove_last(){
    if(is_empty())
      throw std::runtime_error("List is empty, nothing to remove");
    DLListNode *cursor = trailer.prev;
    cursor->prev->next = &trailer;
    trailer.prev = cursor->prev;
    int obj = cursor -> obj;
    delete cursor;
    return obj;
  }
  void insert_after(DLListNode &p, const T obj){
    if(is_empty()){//check if the node you want to insert after is in the DLL
      return;
    }
    DLListNode *newNode = new DLListNode(obj,&p,p.next);
    p.next->prev = newNode;
    p.next = newNode;
  }

  void insert_before(DLListNode &p, const T obj){
    if(is_empty()){//check if the node you want to insert after is in the DLL
      return;
    }
    DLListNode *newNode = new DLListNode(obj,p.prev,&p);
    p.prev->next = newNode;
    p.prev = newNode;
  }

  T remove_after(DLListNode &p){
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

  T remove_before(DLListNode &p){
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
    T obj = temp->obj;
    delete temp;
    return obj;
  }

  void make_empty(void){
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
};

// output operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const TemplatedDLList<T>& dll){
  if(dll.is_empty())
  {
    os << ", ";
  }
   typename TemplatedDLList<T>::DLListNode *cursor = dll.first_node();

  while(cursor != dll.after_last_node())
  {
    os << cursor->obj << ", ";
    cursor = cursor->next;
  }
  return os;
}

#endif
