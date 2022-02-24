#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include<iostream>
#include <list>
#include "MPQ.h"


/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   std::list<T> sorted_mpq;

public:

   SortedMPQ() : sorted_mpq(std::list<T>()){};

   T remove_min(){
      if(is_empty()){
         throw std::exception();
      }

      T min = sorted_mpq.front();
      sorted_mpq.pop_front();
      return min;
   }

   T min(){
      if(is_empty()){
         throw std::exception();
      }
      return sorted_mpq.front();
   }

   bool is_empty(){
      return sorted_mpq.empty();
   }

   void insert(const T& data){

      if(is_empty()){
         sorted_mpq.push_front(data);
      }

      // else if(data < sorted_mpq.front()){//handle if data is the new min
      //    sorted_mpq.push_front(data);
      // }

      else if (data > sorted_mpq.back()){//handle if data is the max of the list 
         sorted_mpq.push_back(data);
      }

      else {//handle if in the middle of list
         for(typename std::list<T>::iterator it = sorted_mpq.begin(); it != sorted_mpq.end(); ++it){
            if (data < *it){
               sorted_mpq.insert(it, data);
               break;
            }
         }
      }

   }


};


#endif