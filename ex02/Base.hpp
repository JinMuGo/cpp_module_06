/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:04:10 by jgo               #+#    #+#             */
/*   Updated: 2023/07/12 16:38:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "Base.h"

class Base {
   public:
	typedef enum e_abc { A, B, C } t_abc;

	virtual ~Base();
};

#endif
