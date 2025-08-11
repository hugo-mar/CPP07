/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:42:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/11 17:35:12 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T, typename F>
void iter(T* array, size_t length, F const& function) {
	if (!array || !length)
		return;
	for (size_t i = 0; i < length; ++i)
		function(array[i]);
}

#endif