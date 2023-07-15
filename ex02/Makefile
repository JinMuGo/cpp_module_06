# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/07/15 10:19:51 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_config/Color.mk
include ../make_config/Funcs.mk
include ../make_config/Flags.mk
include ../make_config/Rules.mk

SRCS := Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
		main.cpp

NAME :=	Identify_real_type

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk
