#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>


/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        inline void insert(const T& data){
            elements.push_back(data);
            up_heap(size);
            size++;
            
        };
        // Return true if BinaryHeap is empty otherwise false
        inline bool is_empty(){
            return elements.empty();
        };
        // Return minimum element in the BinaryHeap
        inline T min(){
            if(is_empty()){
                throw std::exception();
            }

            return elements.at(0);
        };
        // Remove minimum element in the BinaryHeap and return it
        inline T remove_min(){
            if(is_empty()){
                throw std::exception();
            }
            T min_item = elements[0];
            swap(0, size-1);
            elements.pop_back();
            --size;
            down_heap(0);

            return min_item;
        };

        

    private:
        //
        std::vector<T> elements;
        int size = 0;
        //Implement down heap operation
        void down_heap(int i);
        //Implement up heap operation
        void up_heap(int i);

        //Pre-implemented helper functions
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){//i is an index 
    int parent_index = parent(i);

    while(i >= 0 && elements[i] < elements[parent_index]){
        //swap
        swap(i, parent_index);
        i = parent_index;
        parent_index = parent(i);
    }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){//i should always be zero when doing remove
    int right_index = right_child(i);
    int left_index = left_child(i);
    /*
     * Can be computed iteratively or recursively
     */
    if(is_internal(i)){
        if(right_child(i) >= size){
            if(elements[left_index] < elements[i]){
                swap(i, left_index);
                down_heap(left_index);
            }
        }
        else{
            if(elements[left_index] < elements[right_index]){
                if(elements[left_index] < elements[i]){
                    swap(i, left_index);
                    down_heap(left_index);
                }
            }
            else{
                if(elements[right_index] < elements[i]){
                    swap(i, right_index);
                    down_heap(right_index);
                }
            }
        }
    }
}











#endif