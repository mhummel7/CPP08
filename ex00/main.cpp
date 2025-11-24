/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:56:32 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/24 15:31:23 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	// Test with std::vector
	// Vector explanation: A dynamic array that allows random access and can change size.
	// Like a Table where you can access any item directly by its index.
	std::vector<int> vec = {1, 2, 3, 4, 5};
	try {
		auto it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
		easyfind(vec, 10);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	// Test with std::list
	// List explanation: A doubly linked list that allows efficient insertions and deletions.
	// Like a Chain of items where each item points to the next and previous ones.
	std::list<int> lst = {10, 20, 30, 40};
	try {
		auto it = easyfind(lst, 20);
		std::cout << "Found in list: " << *it << std::endl;
		easyfind(lst, 50);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "List error: " << e.what() << std::endl;
	}

	// Test with std::deque
	// Deque explanation: A double-ended queue that allows fast insertions and deletions at both ends.
	// Like a Line of items where you can add or remove items from both the front and back.
	std::deque<int> deq = {100, 200, 300};
	try {
		auto it = easyfind(deq, 200);
		std::cout << "Found in deque: " << *it << std::endl;
		easyfind(deq, 400);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Deque error: " << e.what() << std::endl;
	}

	// Extra Test: Empty container
	std::vector<int> empty_vec;
	try {
		easyfind(empty_vec, 1);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Empty vector error: " << e.what() << std::endl;
	}

	return 0;
}
