# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/07/15 10:19:36 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./make_config/Color.mk
include ./make_config/Funcs.mk
include ./make_config/Flags.mk
include ./make_config/Rules.mk

PROJECT_NAME := cpp_module_06

DIRS := ex00 ex01

$(DIRS):
	$(MAKE) -C $@ $(J)

all bonus:
	$(Q)$(call color_printf,$(YELLOW),$(PROJECT_NAME),🎯 Start compiling)
	$(MAKE) $(DIRS)
	$(Q)$(call color_printf,$(GREEN),$(PROJECT_NAME),✨ compiled!)

fclean clean re:
	$(Q)$(foreach dir, $(DIRS), $(MAKE) -C $(dir) $@;)

.PHONY: all clean fclean re bonus $(DIRS)
