/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:01:34 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/24 15:49:15 by mhummel          ###   ########.fr       */
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

int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	// Calculate differences between adjacent elements
	std::adjacent_difference(sorted.begin(), sorted.end(), sorted.begin());
	// Find and return the minimum difference (skip the first element which is just the first number itself)
	return *std::min_element(sorted.begin() + 1, sorted.end());
}

int Span::longestSpan() const {
	if (_data.size() < 2) {
		throw NoSpanException();
	}
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}
