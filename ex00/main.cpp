/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:56:32 by mhummel           #+#    #+#             */
/*   Updated: 2025/08/06 12:42:25 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	// Test with std::vector
	std::vector<int> vec = {1, 2, 3, 4, 5};
	try {
		auto it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
		easyfind(vec, 10);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	// Test with std::list
	std::list<int> lst = {10, 20, 30, 40};
	try {
		auto it = easyfind(lst, 20);
		std::cout << "Found in list: " << *it << std::endl;
		easyfind(lst, 50);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "List error: " << e.what() << std::endl;
	}

	// Test with std::deque
	std::deque<int> deq = {100, 200, 300};
	try {
		auto it = easyfind(deq, 200);
		std::cout << "Found in deque: " << *it << std::endl;
		easyfind(deq, 400);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Deque error: " << e.what() << std::endl;
	}

	return 0;
}
