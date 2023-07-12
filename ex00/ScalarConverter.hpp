/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/12 10:09:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CPP
#define SCALARCONVERTER_CPP

#include "ScalarConverter.h"

// https://www.tutorialspoint.com/how-to-create-a-static-class-in-cplusplus#:~:text=There%20is%20no%20such%20thing,of%20objects%20of%20the%20class.
class ScalarConverter {
   private:
	// OCF
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& obj);

	typedef enum e_type { NONE, FPE, CHAR, INT, FLOAT, DOUBLE } t_type;
	typedef struct s_scalar {
		char c;
		int i;
		float f;
		double d;
	} t_scalar;

	class JudgeType {
	   private:
		// OCF
		JudgeType();
		JudgeType(const JudgeType& obj);
		~JudgeType();
		JudgeType& operator=(const JudgeType& obj);

		typedef ScalarConverter::t_type (*t_judge_type)(const t_scalar&, std::string, char*);
		static ScalarConverter::t_type isFpe(std::string str, const double& scalar);
		static ScalarConverter::t_type isChar(const t_scalar& scalar, std::string str, char* endptr);
		static ScalarConverter::t_type isInt(const t_scalar& scalar, std::string str, char* endptr);
		static ScalarConverter::t_type isFloat(const t_scalar& scalar, std::string str, char* endptr);
		static ScalarConverter::t_type isDouble(const t_scalar& scalar, std::string str, char* endptr);

	   public:
		static ScalarConverter::t_type judgeType(const t_scalar& scalar, std::string str, char* endptr);
	};

	class PrintScalar {
	   private:
	   	const static std::string _types[5];

		// OCF
		PrintScalar();
		PrintScalar(const PrintScalar& obj);
		~PrintScalar();
		PrintScalar& operator=(const PrintScalar& obj);

		static void printNonDisplayable(const t_type &type);
		static void printImpossible(const t_type &type);
		static void printType(const t_type& type);

	   public:
		static void printScalar(const t_scalar& scalar, const t_type& type);
		static void printChar(const char& scalar);
		static void printFpe(std::string str, const double &scalar);
	};

	class InvalidInputException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};

	class IncorrectNumberOfArgsException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};

   public:
	typedef enum e_err { ERR_ARGS, ERR_INPUT } t_err;
	static void convert(std::string str);
	static void error(t_err err);
	
};


#endif
