/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:13:21 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/24 08:50:35 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>	// For rand()
#include <ctime>	// For time()

int main() {
	// Basic test
	std::cout << "---- Basic Test ----" << std::endl;
	Span sp(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;	// Expected: 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;		// Expected: 14
		sp.addNumber(12);	// Should throw
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with addRange
	std::cout << "---- Range Test ----" << std::endl;
	Span sp2(10000);
	std::vector<int> vec;
	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; ++i) {
		vec.push_back(std::rand());
	}
	try {
		sp2.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span (large): " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span (large): " << sp2.longestSpan() << std::endl;
		sp2.addNumber(1);	// Should throw (full)
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Edge cases
	std::cout << "---- Edge Case Test ----" << std::endl;
	Span sp3(1);
	try {
		sp3.addNumber(42);
		sp3.shortestSpan();		// Should throw
	} catch (const std::exception& e) {
		std::cout << "Edge error: " << e.what() << std::endl;
	}

	// Test duplicates and zero span
	std::cout << "---- Duplicates and Zero Span Test ----" << std::endl;
	Span sp4(3);
	try {
		sp4.addNumber(5);
		sp4.addNumber(5);
		sp4.addNumber(10);
		std::cout << "Shortest span (dupes): " << sp4.shortestSpan() << std::endl;  // 0
		std::cout << "Longest span (dupes): " << sp4.longestSpan() << std::endl;   // 5
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test Span(0)
	std::cout << "---- Zero Size Test ----" << std::endl;
	Span sp5(0);
	try {
		sp5.addNumber(1);  // Should throw immediately
	} catch (const std::exception& e) {
		std::cout << "Zero size error: " << e.what() << std::endl;
	}

	// Test negatives
	std::cout << "---- Negatives Test ----" << std::endl;
	Span sp6(3);
	try {
		sp6.addNumber(-5);
		sp6.addNumber(0);
		sp6.addNumber(5);
		std::cout << "Shortest span (neg): " << sp6.shortestSpan() << std::endl;  // 5
		std::cout << "Longest span (neg): " << sp6.longestSpan() << std::endl;   // 10
		sp6.addNumber(-10);  // Should throw
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
