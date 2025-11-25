/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:12:04 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/25 11:06:12 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>	// For std::sort, std::min_element, etc.
#include <stdexcept>	// For std::runtime_error
#include <iterator>		// For std::distance
#include <limits>		// For numeric_limits
#include <climits>      // For UINT_MAX

class Span {
private:
	std::vector<int> _data;
	unsigned int _maxSize;

public:
	// Constructors
	Span();
	Span(unsigned int N);
	Span(const Span& other);

	// Operator "=" overload
	Span& operator=(const Span& other);

	// Destructor
	~Span();

	// Member functions
	void addNumber(int n);

	template <typename It>
	void addRange(It begin, It end) {
		size_t dist = std::distance(begin, end);
		if (_data.size() + dist > _maxSize) {
			throw FullException();
		}
		_data.insert(_data.end(), begin, end);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	// Exceptions
	class FullException : public std::logic_error {
	public:
		FullException() : std::logic_error("Span is full") {}
	};

	class NoSpanException : public std::logic_error {
	public:
		NoSpanException() : std::logic_error("No span can be found (not enough elements)") {}
	};
};

#endif
