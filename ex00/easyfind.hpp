/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:56:04 by mhummel           #+#    #+#             */
/*   Updated: 2025/11/25 10:18:57 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // For std::find
#include <stdexcept>  // For std::runtime_error

template <typename T> // T should be a container type
typename T::const_iterator easyfind(const T& container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::out_of_range("Value not found in container");
	}
	return it;
}

#endif
