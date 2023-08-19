/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:04:49 by jgo               #+#    #+#             */
/*   Updated: 2023/07/12 10:16:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_C
#define SCALARCONVERTER_C

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include "color.h"

#define EPSION 1e-6

#define SC_DFLT_CTOR GREEN "- ScalarConverter: Default constructor called" RESET
#define SC_CTOR DARK_GREEN "- ScalarConverter: constructor called" RESET
#define SC_CTR LIGHT_CYAN "- ScalarConverter: constructor called" RESET
#define SC_CPY_CTOR CYAN "- ScalarConverter: Copy constructor called" RESET
#define SC_CPY_ASGMT_OP_CALL DARK_CYAN "- ScalarConverter: Copy assignment operator called" RESET
#define SC_DTOR ORANGE "- ScalarConverter: Destructor called" RESET
#define SC_MEMBER_FUNC_CALL "- FScalarConverter member function called"

#endif
