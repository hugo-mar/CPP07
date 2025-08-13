/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:13:54 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/12 17:06:56 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# ifndef ARRAY_HPP
#  include "Array.hpp"
# endif

# include <cstddef>
# include <stdexcept>

template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n)
	: _data(n ? new T[n]() : NULL), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other)
	: _data(other._size ? new T[other._size] : NULL), _size(other._size) {
	for (std::size_t i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template<typename T>
Array<T>::~Array() {
	delete[] _data;	
}

template<typename T>
void	Array<T>::_swap(Array& other) {
	T*	tmpPtr = _data;
	_data = other._data;
	other._data = tmpPtr;

	std::size_t tmpSize = _size;
	_size = other._size;
	other._size = tmpSize;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		Array tmp(other);
		_swap(tmp);
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](std::size_t idx) {
	if (idx >= _size)
		throw std::out_of_range("Array: Index out of range");
	return _data[idx];
}

template<typename T>
const T&	Array<T>::operator[](std::size_t idx) const {
	if (idx >= _size)
		throw std::out_of_range("Array: Index out of range");
	return _data[idx];
}

template<typename T>
std::size_t	Array<T>::size() const {
	return _size;
}

#endif