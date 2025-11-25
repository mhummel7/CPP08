/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:01:34 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/25 10:55:23 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_data = other._data;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_data.size() >= _maxSize) {
		throw FullException();
	}
	_data.push_back(n);
}

unsigned int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	unsigned int min_span = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i) { // goes through sorted from index 1 to end
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]); // difference between sorted1 and sorted0
		if (diff < min_span) // if current difference is smaller than min_span
			min_span = diff;
	}
	return min_span;
}

unsigned int Span::longestSpan() const {
	if (_data.size() < 2) {
		throw NoSpanException();
	}
	auto min_it = std::min_element(_data.begin(), _data.end()); // auto = std::vector<int>::const_iterator
	auto max_it = std::max_element(_data.begin(), _data.end());

	return static_cast<unsigned int>(*max_it - *min_it); // from int to unsigned int
}
