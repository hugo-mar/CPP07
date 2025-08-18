/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:22:05 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/19 00:11:31 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Function to print
template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

// Functor to print
template <typename T>
struct princtor {
	void operator()(const T& element) const {
		std::cout << element << " ";
	}
};

// Function to increment
template <typename T>
void increment(T& element) {
	element = element + 1;
}

// Function for strings
void toUpperCase(std::string& str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = static_cast<char>(str[i] - 'a' + 'A');
	}
}

int main() {
	// Test with int array (non-const): print, increment, print
	int numbers[] = {1, 2, 3, 4, 5};
	std::size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Integers before: ";
	iter(numbers, numbersLen, printElement<int>);
	std::cout << "\n";

	iter(numbers, numbersLen, increment<int>);

	std::cout << "Integers after:  ";
	iter(numbers, numbersLen, princtor<int>());
	std::cout << "\n\n";

	// Test with strings (non-const): print, upper, print
	std::string words[] = {"chaine1", "chaine2", "forty-two", "cpp"};
	std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "Strings before: ";
	iter(words, wordsLen, printElement<std::string>);
	std::cout << "\n";

	iter(words, wordsLen, toUpperCase);

	std::cout << "Strings after:  ";
	iter(words, wordsLen, princtor<std::string>());
	std::cout << "\n\n";

	// Test with const int array: only non-modifying functions allowed
	const int constants[] = {10, 20, 30};
	std::size_t constLen = sizeof(constants) / sizeof(constants[0]);

	std::cout << "Const integers: ";
	iter(constants, constLen, printElement<int>);
	std::cout << "\n";

	// iter(constants, constLen, increment<int>); // won't compile (as expected)

	return 0;
}
