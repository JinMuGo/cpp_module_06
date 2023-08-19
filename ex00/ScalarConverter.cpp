/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/08/19 17:53:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << SC_DFLT_CTOR << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& obj) {
	std::cout << SC_CPY_CTOR << std::endl;
	*this = obj;
}
ScalarConverter::~ScalarConverter() {
	std::cout << SC_DTOR << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
	std::cout << SC_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &obj)
		return *this;
	return *this;
}

void ScalarConverter::error(const t_err err) {
	switch (err) {
		case ERR_ARGS:
			throw ScalarConverter::IncorrectNumberOfArgsException();
			break;
		case ERR_INPUT:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}

void ScalarConverter::convert(std::string str) {
	char* endptr = NULL;
	const double d = strtod(str.c_str(), &endptr);
	const t_scalar scalar = {static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d};
	const t_type type = ScalarConverter::JudgeType::judgeType(scalar, str, endptr);

	switch (type) {
		case NONE:
			ScalarConverter::error(ERR_INPUT);
			break;
		case FPE:
			ScalarConverter::PrintScalar::printFpe(str, scalar.d);
			break;
		case CHAR:
			ScalarConverter::PrintScalar::printChar(str[0]);
			break;
		default:
			ScalarConverter::PrintScalar::printScalar(scalar, type);
			break;
	}
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input! try the right value";
}

const char* ScalarConverter::IncorrectNumberOfArgsException::what() const throw() {
	return "Incorrect number of arguments";
}
