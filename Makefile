# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 13:51:31 by afuchs            #+#    #+#              #
#    Updated: 2022/06/21 13:41:03 by afuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SPATH	= src/

OPATH	= obj/

BPATH	= bobj/

LPATH	= libft/

HPATH	= header/

SRC		=	main.c operation.c checkint.c issorted.c smartrot.c stacks.c	\
			lstdel_last.c ft_abs.c cleanout.c doop.c bruteforce.c			\
			quickinsert.c pshbetween.c iscyclesort.c choose.c				\

BSRC	=	checker_bonus.c checkint.c issorted.c stacks.c doop.c			\
			operation.c														\

OBJ		= $(SRC:%.c=$(OPATH)%.o)

BOBJ	= $(BSRC:%.c=$(BPATH)%.o)

OPTIONS	= -Wall -Wextra -Werror

HEADERS	= -I$(HPATH) -I$(LPATH)

LIB		= $(LPATH)libft.a

NAME	= push_swap

BNAME	= checker

SIL		= --no-print-directory

$(NAME)		:	$(OPATH) $(LIB) $(OBJ)
				@gcc $(OPTIONS) $(OBJ) $(LIB) -o $@
				@echo "\033[32mLinking $(NAME) complete!\033[0m"

$(OPATH)%.o	:	$(SPATH)%.c
				@gcc $(OPTIONS) $(HEADERS) -c $< -o $@
				@echo "\033[90mObject file $(@:$(OPATH)%=%) has been made.\033[0m"

$(BPATH)%.o	:	$(SPATH)%.c
				@gcc $(OPTIONS) $(HEADERS) -c $< -o $@
				@echo "\033[90mObject file $(@:$(BPATH)%=%) has been made.\033[0m"

$(OPATH)	:
				@mkdir $@
				@echo "\033[90mDirectory $@ created.\033[0m"

$(BPATH)	:
				@mkdir $@
				@echo "\033[90mDirectory $@ created.\033[0m"

$(LIB)		:
				@(cd $(LPATH) && $(MAKE) $(SIL) bonus clean)
				@echo "\033[90mCompiled $(LIB:$(LPATH)%=%).\033[0m"

all			:	$(NAME) $(BNAME)

clean		:
				@(rm -rf $(OPATH) $(BPATH) && cd $(LPATH) && $(MAKE) $(SIL) fclean)
				@echo "\033[31mObject files and static libraries deleted.\033[0m"

fclean		:	clean
				@rm -rf $(NAME) $(BNAME)
				@echo "\033[31mCleaned all made up files.\033[0m"

re			:	fclean all

$(BNAME)	:	$(BPATH) $(LIB) $(BOBJ)
				@gcc $(OPTIONS) $(BOBJ) $(LIB) -o $(BNAME)
				@echo "\033[32mLinking $(BNAME) complete!\033[0m"

bonus		:	$(BNAME)

.PHONY		:	all clean fclean re bonus
