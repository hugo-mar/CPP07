/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:03:04 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/13 23:19:04 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>

template<typename T>
class Array
{
public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array&		operator=(const Array& other);
	
	T&			operator[](std::size_t idx);
	const T&	operator[](std::size_t idx) const;

	std::size_t	size() const;

private:
	T* 			_data;
	std::size_t	_size;

	void		_swap(Array& other);
};

# include "Array.tpp"

#endif
