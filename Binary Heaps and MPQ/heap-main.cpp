#include "BinaryHeap.h"
#include <vector>
#include <iostream>

int main(){
	BinaryHeap<int> h;

	h.insert(70);
	h.insert(231);
	h.insert(999);
	h.insert(879);
	h.insert(448);
	h.insert(483);
	h.insert(315);
	h.insert(251);
	h.insert(778);
	h.insert(992);

	

	for(int i = 0; i < 10; i ++){
		std::cout << h.elements[i] << ", ";
	}

	std::cout << std::endl << "Ok, bad" << std::endl<< "Remove everything" << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;
	std::cout << h.remove_min() << std::endl;

}