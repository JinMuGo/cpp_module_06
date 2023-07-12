/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:50:19 by jgo               #+#    #+#             */
/*   Updated: 2023/07/12 16:01:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>
#include "Serializer.hpp"

static inline void decToBin(const uintptr_t d) {
	for (int i = 31; i >= 0; i--) {
		int tmp = (d >> i) & true;
		std::cout << tmp;
	}
	std::cout << std::endl;
}

static inline void hexToBin(const std::string& str) {
	std::stringstream ss;
	uintptr_t n;

	ss << std::hex << str;
	ss >> n;

	decToBin(n);
}

void	printData(const Data &data)
{
	std::cout << "Book Data\n" << std::endl;
	std::cout << "title: " << data.title << std::endl;
	std::cout << "author: " << data.author << std::endl;
	std::cout << "date: " << data.date << "\n" << std::endl;
}

int main(void) {
	Data book1 = {"Norwegian Wood", "Haruki Murakami", 1987};
	Data book2 = {"The Old Man and the Sea", "Ernest Hemingway", 1952};

	const void* address1 = static_cast<const void*>(&book1);
	const void* address2 = static_cast<const void*>(&book2);
	std::stringstream ss;

	const uintptr_t ptr1 = Serializer::serialize(&book1);
	const uintptr_t ptr2 = Serializer::serialize(&book2);
	std::cout << GREEN "\nOriginal value\n" RESET << std::endl;

	printData(book1);
	printData(book2);

	std::cout << ORANGE "Original address value\n" RESET << std::endl;

	std::cout << "Book1: " << &book1 << std::endl;
	std::cout << "Book2: " << &book2 << "\n" << std::endl;

	ss << address1;
	const std::string str1 = ss.str();
	ss.str(std::string());
	ss << address2;
	const std::string str2 = ss.str();

	std::cout << PURPLE "Original address bitmap\n" RESET << std::endl;

	hexToBin(str1);
	hexToBin(str2);

	std::cout << ORANGE "\nSerialized address value\n" RESET << std::endl;

	std::cout << "Book1: " << ptr1 << std::endl;
	std::cout << "Book2: " << ptr2 << "\n" << std::endl;

	std::cout << PURPLE "Serialized address bitmap\n" RESET << std::endl;

	decToBin(ptr1);
	decToBin(ptr2);

	std::cout << RED "\nDeserialized value\n" RESET << std::endl;

	const Data *d_ptr1 = Serializer::deserialize(ptr1);
	const Data *d_ptr2 = Serializer::deserialize(ptr2);

	printData(*d_ptr1);
	printData(*d_ptr2);

	return (0);
}