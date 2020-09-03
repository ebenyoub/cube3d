# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 15:23:25 by ebenyoub          #+#    #+#              #
#    Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libft_cub.a
SRCS		=	ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strjoin.c\
				ft_strncmp.c ft_substr.c ft_calloc.c ft_isdigit.c  ft_memcmp.c\
				ft_split.c  ft_strlcat.c ft_strnstr.c ft_tolower.c ft_isalnum.c\
				ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c\
				ft_toupper.c ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c\
				ft_strdup.c ft_strlen.c ft_strtrim.c ft_strcpy.c ft_calloc.c\
				ft_strcat.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_free_tab.c 
BSRC		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
				ft_lstmap_bonus.c
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRC:.c=.o)
HEAD		=	libft_cub.h
CC			=	gcc
RM			=	rm -f


%.o:%.c		$(HEAD)
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			@$(CC) $(CFLAGS) -IINCL -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			@ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			@echo "\033[0;32m     \033[0m       \033[0;33m Suppression en cours...\033[0m"
			@$(RM) $(OBJS)
			@echo "\033[0;32m--> Fichers Objets Supprimés\033[0m"
			@$(RM) $(BOBJ)
			@echo "\033[0;32m--> Fichers Bonus Supprimés\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[0;32m--> Ficher libft_cub.a Supprimé\033[0m"

re:			fclean all

bonus:		$(OBJS) $(HEAD) $(BOBJ)
			@ar rc $(NAME) $(OBJS) $(BOBJ)
			ranlib $(NAME)

.PHONY: all clean fclean re bonus
