# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 13:51:31 by afuchs            #+#    #+#              #
#    Updated: 2022/06/20 01:13:16 by afuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SPATH	= src/

OPATH	= obj/

LPATH	= libft/

HPATH	= header/

SRC		=	main.c operation.c checkint.c issorted.c smartrot.c				\
			lstdel_last.c ft_abs.c cleanout.c tryout.c bruteforce.c			\
			quickinsert.c pshbetween.c iscyclesort.c choose.c				\

OBJ		= $(SRC:%.c=$(OPATH)%.o)

OPTIONS	= -Wall -Wextra -Werror

HEADERS	= -I$(HPATH) -I$(LPATH)

LIB		= $(LPATH)libft.a

NAME	= push_swap

SIL		= --no-print-directory

$(NAME)		:	$(OPATH) $(LIB) $(OBJ)
				@gcc $(OPTIONS) $(OBJ) $(LIB) -o $@
				@echo "\033[32mLinking $(NAME) complete!\033[0m"

$(OPATH)%.o	:	$(SPATH)%.c
				@gcc $(OPTIONS) $(HEADERS) -c $< -o $@
				@echo "\033[90mObject file $(@:$(OPATH)%=%) has been made.\033[0m"

$(OPATH)	:
				@mkdir $@
				@echo "\033[90mDirectory $@ created.\033[0m"

$(LIB)		:
				@(cd $(LPATH) && $(MAKE) $(SIL) bonus clean)
				@echo "\033[90mCompiled $(LIB:$(LPATH)%=%).\033[0m"

all			:	$(NAME)

clean		:
				@(rm -rf $(OPATH) && cd $(LPATH) && $(MAKE) $(SIL) fclean)
				@echo "\033[31mObject files and static libraries deleted.\033[0m"

fclean		:	clean
				@rm -rf $(NAME)
				@echo "\033[31mCleaned all made up files.\033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re
