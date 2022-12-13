# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 19:37:44 by lzi-xian          #+#    #+#              #
#    Updated: 2022/12/08 13:42:27 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME		=	push_swap
CHK_NAME	=	checker
SRCS		=	ft_check_and_free.c			\
				ft_chk_and_error.c			\
				ft_get_a.c					\
				ft_get_join_sort.c			\
				ft_ps_atoi.c				\
				ft_put_b_part_a.c			\
				ft_put_b_utils.c			\
				ft_put_b.c					\
				ft_rule_p.c					\
				ft_rule_r.c					\
				ft_rule_rev_r.c				\
				ft_rule_s.c					\
				ft_set_order.c				\
				ft_sort_three.c				\
				ft_stack_and_last_node.c
BONUS		=	ps_bonus/ft_checker.c				\
				get_next_line/get_next_line.c	\
				get_next_line/get_next_line_utils.c	\
				ps_bonus/main.c
SRCS_MAIN	=	ps_main/main.c
SMAIN_OBJ	=	${SRCS_MAIN:.c=.o}
LIBFT		=	libft/libft.a
MAIN_DIR	=	ps_obj/
OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS:.c=.o}
NAME		=	push_swap.a
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${SMAIN_OBJ}
	touch $(NAME)
	cp ${LIBFT} .
	mv libft.a $(NAME)
	${ARCR} ${NAME} ${OBJS}
	make run

run:
	${GCC} ${CFLAGS} ps_main/main.c $(NAME) -o ${PS_NAME}

all:	$(NAME)

clean:
	${RMRF} ${BONUS_OBJS} ${SMAIN_OBJ} ${OBJS}

fclean:	clean
	${RMRF} $(NAME) ${CHK_NAME} ${PS_NAME} bonus 

bonus:	${BONUS_OBJS} ${OBJS}
	touch bonus
	cp ${LIBFT} .
	mv libft.a $(NAME)
	${ARCR} ${NAME} ${OBJS} ${BONUS_OBJS}
	make checker

checker:
	${GCC} ${CFLAGS} $(NAME) -o ${CHK_NAME}

re:	fclean all bonus