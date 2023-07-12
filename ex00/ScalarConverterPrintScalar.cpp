/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPrintScalar.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:38:40 by jgo               #+#    #+#             */
/*   Updated: 2023/07/12 14:05:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const std::string ScalarConverter::PrintScalar::_types[5] = {"Floating Point Execption", "Char", "Int", "Float",
															 "Double"};

ScalarConverter::PrintScalar::PrintScalar() {}

ScalarConverter::PrintScalar::PrintScalar(const ScalarConverter::PrintScalar& obj) {
	*this = obj;
}
ScalarConverter::PrintScalar::~PrintScalar() {}

ScalarConverter::PrintScalar& ScalarConverter::PrintScalar::operator=(const ScalarConverter::PrintScalar& obj) {
	if (this != &obj)
		return *this;
	return *this;
}

void ScalarConverter::PrintScalar::printNonDisplayable(const t_type& type) {
	std::cout << _types[type - 1] << ": Non displayable" << std::endl;
};
void ScalarConverter::PrintScalar::printImpossible(const t_type& type) {
	std::cout << _types[type - 1] << ": Impossible" << std::endl;
};

void ScalarConverter::PrintScalar::printFpe(std::string str, const double& scalar) {
	const std::string fpes[][5] = {
		{"+inff", "impossible", "impossible", "inff", "inf"},	{"inff", "impossible", "impossible", "inff", "inf"},
		{"-inff", "impossible", "impossible", "-inff", "-inf"}, {"nanf", "impossible", "impossible", "nanf", "nan"},
		{"+inf", "impossible", "impossible", "inff", "inf"},	{"inf", "impossible", "impossible", "inff", "inf"},
		{"-inf", "impossible", "impossible", "-inff", "-inf"},	{"nan", "impossible", "impossible", "nanf", "nan"}};
	const std::string(*begin)[5] = fpes;
	const std::string(*end)[5] = fpes + sizeof(fpes) / sizeof(fpes[0]);

	printType(FPE);
	if (std::isnan(scalar))
		str = "nan";
	if (std::isinf(scalar))
		str = "inf";
	for (std::string(*it)[5] = const_cast<std::string(*)[5]>(begin); it != end; ++it) {
		if (str.compare((*it)[0]) == 0) {
			std::cout << "char: " << (*it)[1] << std::endl;
			std::cout << "int: " << (*it)[2] << std::endl;
			std::cout << "float: " << (*it)[3] << std::endl;
			std::cout << "double: " << (*it)[4] << std::endl;
			return;
		}
	}
}

void ScalarConverter::PrintScalar::printType(const t_type& type) {
	std::cout << "Type: " << _types[type - 1] << std::endl;
};

void ScalarConverter::PrintScalar::printChar(const char& scalar) {
	std::cout << "char: \'" << scalar << "\'" << std::endl;
	std::cout << "int: " <<  static_cast<int>(scalar) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(scalar) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(scalar) << std::endl;
}

void ScalarConverter::PrintScalar::printScalar(const t_scalar& scalar, const t_type& type) {
	// printType(type);
	static_cast<void>(type);
	if (CHAR_MIN > scalar.i || scalar.i > CHAR_MAX)
		printImpossible(CHAR);
	else if (std::isprint(scalar.i) == 0)
		printNonDisplayable(CHAR);
	else
		std::cout << "char: \'" << scalar.c << "\'" << std::endl;
	if (INT_MIN <= scalar.d && scalar.d <= INT_MAX)
		std::cout << "int: " << scalar.i << std::endl;
	else
		printImpossible(INT);
	if (std::abs(scalar.d - scalar.f) < EPSION)
		std::cout << std::fixed << std::setprecision(1) << "float: " << scalar.f << "f" << std::endl;
	else
		printImpossible(FLOAT);
	std::cout << std::fixed << std::setprecision(1) << "double: " << scalar.d << std::endl;
}