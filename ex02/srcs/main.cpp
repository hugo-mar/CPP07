/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:12:40 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/13 11:05:16 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.hpp"

template<typename T>
void	printArray(const Array<T>& arr) {
	std::cout << "( ";
	for (std::size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << ")" << std::endl;
}

// For explicit demonstration
void	printSize(const Array<int>& arr) {
	std::cout << "Array size: " << arr.size() << std::endl;
}

int main() {
	
	Array<int> a1(5);
	for (size_t i = 0; i < a1.size(); ++i)
		a1[i] = i*10;
	printArray(a1);

	Array<std::string> a2(3);
	a2[0] = "Hello";
	a2[1] = "Brave";
	a2[2] = "World";
	printArray(a2);

	try {
		a2[3] = "Of fire";
	} catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;	
	
	}
	
	printSize(Array<int>(5));
	// printSize(5);				// explicit demo
	printSize(a1);
	// printSize(a2);
	return 0;
}
















// #include <iostream>
// #include <string>
// #include "Array.hpp"

// template <typename T>
// void printArray(const Array<T>& arr) {
// 	std::cout << "[ ";
// 	for (std::size_t i = 0; i < arr.size(); ++i)
// 		std::cout << arr[i] << " ";
// 	std::cout << "]\n";
// }

// int main() {
// 	try {
// 		// 1) Default constructor
// 		std::cout << "== Default constructor ==\n";
// 		Array<int> a0;
// 		std::cout << "Size: " << a0.size() << "\n";

// 		// 2) Size constructor
// 		std::cout << "\n== Size constructor ==\n";
// 		Array<int> a1(5);
// 		printArray(a1);

// 		// 3) Write and read
// 		std::cout << "\n== Write and read ==\n";
// 		for (std::size_t i = 0; i < a1.size(); ++i)
// 			a1[i] = static_cast<int>(i * 10);
// 		printArray(a1);

// 		// 4) Copy constructor (deep copy)
// 		std::cout << "\n== Copy constructor ==\n";
// 		Array<int> a2(a1);
// 		a2[0] = 999;
// 		std::cout << "a1: "; printArray(a1);
// 		std::cout << "a2: "; printArray(a2);

// 		// 5) Assignment operator (deep copy)
// 		std::cout << "\n== Assignment operator ==\n";
// 		Array<int> a3(3);
// 		a3 = a1;
// 		a3[1] = 777;
// 		std::cout << "a1: "; printArray(a1);
// 		std::cout << "a3: "; printArray(a3);

// 		// 6) Const correctness
// 		std::cout << "\n== Const correctness ==\n";
// 		const Array<int> ca = a1;
// 		std::cout << "ca[2] = " << ca[2] << "\n";

// 		// 7) Bounds check
// 		std::cout << "\n== Bounds check (exception) ==\n";
// 		try {
// 			std::cout << a1[a1.size()] << "\n";
// 		} catch (const std::exception& e) {
// 			std::cout << "Caught: " << e.what() << "\n";
// 		}

// 		// 8) Test with std::string
// 		std::cout << "\n== Test with std::string ==\n";
// 		Array<std::string> sarr(3);
// 		sarr[0] = "hello";
// 		sarr[1] = "cpp";
// 		sarr[2] = "module07";
// 		printArray(sarr);

// 	} catch (const std::exception& e) {
// 		std::cerr << "Unhandled exception: " << e.what() << "\n";
// 		return 1;
// 	}
// 	return 0;
// }
