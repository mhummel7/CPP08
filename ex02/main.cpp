/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:14:53 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/24 08:53:49 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	// Test with MutantStack
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// Test reverse iterators
	std::cout << "\nReverse iteration:\n";
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	// Test copy and const
	std::cout << "\nCopy test:\n";
	MutantStack<int> copy(mstack);
	copy.pop();  // Modify copy
	std::cout << "Original size: " << mstack.size() << ", Copy size: " << copy.size() << std::endl;

	const MutantStack<int> const_stack(mstack);
	MutantStack<int>::const_iterator cit = const_stack.begin();
	std::cout << "Const first: " << *cit << std::endl;

	// Same test with std::list (should produce identical output)
	std::cout << "\nTesting with std::list:\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	return 0;
}
