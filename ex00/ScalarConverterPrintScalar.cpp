/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPrintScalar.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:38:40 by jgo               #+#    #+#             */
/*   Updated: 2023/07/11 21:07:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void ScalarConverter::PrintScalar::printNonDisplayable(void) {
	std::cout << "Non displayable" << std::endl;
};
void ScalarConverter::PrintScalar::printImpossible(void) {
	std::cout << "Impossible" << std::endl;
};

void ScalarConverter::PrintScalar::printFpe(std::string str, const double &scalar) {
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
		if (str.compare((*it)[0]) == 0)
		{
			std::cout << "char: " << (*it)[1] << std::endl;
			std::cout << "int: " << (*it)[2] << std::endl;
			std::cout << "float: " << (*it)[3] << std::endl;
			std::cout << "double: " << (*it)[4] << std::endl;
			return ;
		}
	}
}

void ScalarConverter::PrintScalar::printScalar(const char& scalar, const t_type &type){
	if (std::isprint(scalar) || type == CHAR)
		std::cout << "char: " << scalar << std::endl;
	else
		printNonDisplayable();
};
void ScalarConverter::PrintScalar::printScalar(const int& scalar, const t_type &type){
	if (type == INT)
		std::cout << "int: " << scalar << std::endl;
	else
		printNonDisplayable();
};
void ScalarConverter::PrintScalar::printScalar(const float& scalar, const t_type &type){};
void ScalarConverter::PrintScalar::printScalar(const double& scalar, const t_type &type){};

void ScalarConverter::PrintScalar::printType(const t_type &type){
	const std::string	types[] = {"Floating Point Execption", "Char", "Int", "Float", "Double"};

	std::cout << "Type: " << types[type - 1] << std::endl;
};

void ScalarConverter::PrintScalar::printScalar(const t_scalar& scalar, const t_type& type) {
	printType(type);

	printScalar(scalar.c, type);
	printScalar(scalar.i, type);
	printScalar(scalar.f, type);
	printScalar(scalar.d, type);
}
// 흠... 어떻게 처리하는게 좋을까..... 일단 t_scalar의 type을 알았는ㄷ....
// scalar의 field들을 모두 순회하면서 print하면 되지 않을까.
// 그러면 그냥 overloading하면 될 것 같은데
