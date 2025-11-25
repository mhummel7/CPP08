/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:14:35 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/25 11:23:42 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>	// Underlying container for std::stack

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Constructors
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}

	// Operator "=" overload
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}
	// Destructor
	~MutantStack() {}

	// Member functions
	// Stack has underlzing container which is default deque. Stack has protected c which is why we can use pop etc, but im accessing here directly to get the iterators.
	typedef typename std::stack<T>::container_type::iterator iterator; // acces to underlying container's iterator type.
	iterator begin() { return this->c.begin(); } // 'c' is the protected member of std::stack that holds the underlying container
	iterator end() { return this->c.end(); }

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }

};

#endif
