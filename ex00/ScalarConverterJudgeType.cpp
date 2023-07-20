/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterJudgeType.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:02:03 by jgo               #+#    #+#             */
/*   Updated: 2023/07/20 17:22:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::JudgeType::JudgeType() {}

ScalarConverter::JudgeType::JudgeType(const ScalarConverter::JudgeType& obj) {
	*this = obj;
}
ScalarConverter::JudgeType::~JudgeType() {}

ScalarConverter::JudgeType& ScalarConverter::JudgeType::operator=(const ScalarConverter::JudgeType& obj) {
	if (this != &obj)
		return *this;
	return *this;
}

ScalarConverter::t_type ScalarConverter::JudgeType::isFpe(const std::string& str, const double& scalar) {
	const std::string fpes[] = {"+inff", "inff", "-inff", "nanf", "+inf", "inf", "-inf", "nan"};
	const std::string* begin = fpes;
	const std::string* end = fpes + sizeof(fpes) / sizeof(fpes[0]);

	if (std::isnan(scalar) || std::isinf(scalar))
		return (FPE);
	for (std::string* it = const_cast<std::string*>(begin); it != end; ++it) {
		if (str.compare(*it) == 0)
			return (FPE);
	}
	return (NONE);
}
ScalarConverter::t_type ScalarConverter::JudgeType::isChar(const t_scalar& scalar, const std::string str,
														   const char* endptr) {
	if (str.length() != 1 || std::isdigit(scalar.c) || std::isprint(endptr[0]) == false)
		return (NONE);
	return (CHAR);
}
ScalarConverter::t_type ScalarConverter::JudgeType::isInt(const t_scalar& scalar, const std::string str,
														  const char* endptr) {
	const std::string::size_type dot = str.find_first_of(".");

	if (scalar.d != scalar.i || endptr[0] || str.length() > 11 || dot != std::string::npos)
		return (NONE);
	return (INT);
}
ScalarConverter::t_type ScalarConverter::JudgeType::isFloat(const t_scalar& scalar, const std::string str,
															const char* endptr) {
	if (endptr[0] != 'f' || std::abs(scalar.d - scalar.f) > EPSION || str[0] == 'f')
		return (NONE);
	return (FLOAT);
}
ScalarConverter::t_type ScalarConverter::JudgeType::isDouble(const t_scalar& scalar, const std::string str,
															 const char* endptr) {
	const std::string::size_type forward = str.find_first_of(".");
	const std::string::size_type backward = str.find_last_of(".");

	static_cast<void>(scalar);
	if (forward != backward || endptr[0])
		return (NONE);
	return (DOUBLE);
}

ScalarConverter::t_type ScalarConverter::JudgeType::judgeType(const t_scalar& scalar, const std::string str,
															  char* endptr) {
	if (isFpe(str, scalar.d))
		return (FPE);
	const t_judge_type funcs[] = {isChar, isInt, isFloat, isDouble};
	const t_judge_type* begin = funcs;
	const t_judge_type* end = funcs + sizeof(funcs) / sizeof(funcs[0]);
	t_type type;

	for (t_judge_type* it = const_cast<t_judge_type*>(begin); it != end; ++it) {
		type = (*it)(scalar, str, endptr);
		if (type != NONE)
			return type;
	}
	return NONE;
}
