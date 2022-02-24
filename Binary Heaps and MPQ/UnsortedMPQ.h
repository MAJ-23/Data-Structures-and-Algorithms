#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include<iostream>
#include <vector>
#include "MPQ.h"


/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   std::vector<T> unsorted_mpq;

public:
   T remove_min(){//9:43am
      if(is_empty()){
         throw std::exception();
      }

      T min = unsorted_mpq[0];
      auto pos = unsorted_mpq.begin();
      for(auto it = unsorted_mpq.begin(); it != unsorted_mpq.end(); ++it){
         if(*it < min){
            min = *it;
            pos = it;
         }
      }

      unsorted_mpq.erase(pos);
      return min;
   }

   T min(){

      if(unsorted_mpq.empty()){
         throw std::exception();
      }

      T min = unsorted_mpq[0];

      for(unsigned int i  = 1; i < unsorted_mpq.size(); ++i){
         if(unsorted_mpq[i] < min){
            min = unsorted_mpq[i];
         }
      }

      return min;

   }

   inline bool is_empty(){
      return unsorted_mpq.empty();
   }

   inline void insert(const T& data){
      unsorted_mpq.push_back(data);
      
   }
};

#endif