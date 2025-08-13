/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:12:40 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/14 00:14:52 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr) {
	std::cout << "[ ";
	for (std::size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << "]\n";
}

// // For explicit contructor demonstration only
// void	printSize(const Array<int>& arr) {
// 	std::cout << "Array size: " << arr.size() << std::endl;
// }

int main() {
	try {

		std::cout << "== Default constructor ==\n";
		Array<int> a0;
		std::cout << "Size: " << a0.size() << "\n";

		std::cout << "\n== Size constructor ==\n";
		Array<int> a1(5);
		printArray(a1);

		std::cout << "\n== Write and read ==\n";
		for (std::size_t i = 0; i < a1.size(); ++i)
			a1[i] = static_cast<int>(i * 10);
		printArray(a1);

		std::cout << "\n== Copy constructor (deep copy) ==\n";
		Array<int> a2(a1);
		a2[0] = 999;
		std::cout << "a1: "; printArray(a1);
		std::cout << "a2: "; printArray(a2);

		std::cout << "\n== Assignment operator (deep copy) ==\n";
		Array<int> a3(3);
		a3 = a1;
		a3[0] = 777;
		std::cout << "a1: "; printArray(a1);
		std::cout << "a3: "; printArray(a3);

		std::cout << "\n== Const correctness ==\n";
		const Array<int> ca = a1;
		std::cout << "ca[2] = " << ca[2] << "\n";

		std::cout << "\n== Bounds check (exception) ==\n";
		try {
			std::cout << a1[a1.size()] << "\n";
		} catch (const std::exception& e) {
			std::cout << "Caught: " << e.what() << "\n";
		}

		std::cout << "\n== Test with std::string ==\n";
		Array<std::string> sarr(3);
		sarr[0] = "Hello";
		sarr[1] = "Brave";
		sarr[2] = "World";
		printArray(sarr);

		// // Explicit constructor relevance demonstration
		// printSize(Array<int>(5));	// Always OK (explicit)
		// printSize(a1);				// Ok
		// // printSize(5);				// Won't compile WITH 'explicit' (compiles if you remove 'explicit')
		// // a0 = 5;					// Won't compile WITH 'explicit' (compiles if you remove 'explicit')

	} catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << "\n";
		return 1;
	}
	return 0;
}
