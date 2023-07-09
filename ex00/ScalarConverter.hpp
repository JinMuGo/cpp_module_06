/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/09 12:08:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CPP
#define SCALARCONVERTER_CPP

#include "ScalarConverter.h"

// https://www.tutorialspoint.com/how-to-create-a-static-class-in-cplusplus#:~:text=There%20is%20no%20such%20thing,of%20objects%20of%20the%20class.
class ScalarConverter {
   private:
	static bool isPrintChar(const int c);

   public:
	static void convert(const std::string &str);
	static int prtErr(const std::string msg);

	class InvalidInputException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
};

#endif