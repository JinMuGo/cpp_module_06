/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/10 19:43:41 by jgo              ###   ########.fr       */
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

bool ScalarConverter::isPrintChar(const int c) {
	return (' ' <= c && c <= '~');
}

void ScalarConverter::error(t_err err) {
	switch (err) {
		case ERR_ARGS:
			throw ScalarConverter::IncorrectNumberOfArgsException();
			break;
		case ERR_INPUT:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}

bool ScalarConverter::checkArgs(const std::string& str, const t_scalar& scalar, const char* endptr) {
	if (scalar.d == 0 && (str[0] != '-' && str[0] != '+') && isdigit(str[0]) == false)
		return (true);
	if (endptr[0] && endptr[0] != 'f' || endptr[1])
		return (true);
	return (false);
}

t_type ScalarConverter::judgeType(const t_scalar &scalar)
{

}

//floating point exception
void ScalarConverter::fpe(t_scalar &scalar)
{

}

void ScalarConverter::convert(const std::string& str) {
	char* endptr = NULL;
	const double d = strtod(str.c_str(), &endptr);
	const t_scalar scalar = {static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d};

	if (ScalarConverter::checkArgs(str, scalar, endptr))
		ScalarConverter::error(ERR_INPUT);

}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input! try the right value";
}

const char* ScalarConverter::IncorrectNumberOfArgsException::what() const throw() {
	return "Incorrect number of arguments";
}
