/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someFewFunctions.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:11:52 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/11 15:28:05 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOMEFEWFUNCTIONS_HPP
# define SOMEFEWFUNCTIONS_HPP

template<typename T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T const& max(T const& x, T const& y) {
	return ((x > y) ? x : y);
}

template<typename T>
T const& min(T const&x, T const& y) {
	return ((x < y) ? x : y);
}

#endif