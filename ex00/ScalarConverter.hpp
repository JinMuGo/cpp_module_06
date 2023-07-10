/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/10 19:42:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CPP
#define SCALARCONVERTER_CPP

#include "ScalarConverter.h"

// https://www.tutorialspoint.com/how-to-create-a-static-class-in-cplusplus#:~:text=There%20is%20no%20such%20thing,of%20objects%20of%20the%20class.
class ScalarConverter {
   private:
	static bool isPrintChar(const int c);
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& obj);

   public:
	typedef enum e_err { ERR_ARGS, ERR_INPUT } t_err;
	typedef enum e_type {FPE, INT, FLOAT, DOUBLE, CHAR} t_type;
	typedef struct s_scalar {
		char c;
		int i;
		float f;
		double d;
	} t_scalar;

	static void convert(const std::string& str);
	static bool checkArgs(const std::string& str, const t_scalar& scalar, const char *endptr);
	static void error(t_err err);
	static t_type judgeType(const t_scalar &scalar);
	static void fpe(t_scalar &scalar);


	class InvalidInputException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};

	class IncorrectNumberOfArgsException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
};

#endif
