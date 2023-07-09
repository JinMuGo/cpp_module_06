/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/09 12:14:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isPrintChar(const int c) {
	return (' ' <= c && c <= '~');
}

int ScalarConverter::prtErr(const std::string msg) {
	std::cerr << msg;
	return (EXIT_FAILURE);
}

void ScalarConverter::convert(const std::string &str) {
	const double raw = std::atof(str.c_str());
	
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return "Invalid input! try the right value";
}
