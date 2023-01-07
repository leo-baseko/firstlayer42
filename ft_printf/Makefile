NAME =			libftprintf.a

RM =			rm -rf
CC =			gcc
FLAGS =			-Wall -Werror -Wextra

INCLUDE =		ft_printf.h \

SRC =			ft_printf.c \
				ft_putnbr_base.c \
				ft_printf_utils.c

SRCS =			$(SRC)
OBJS =			$(addsuffix .o, $(basename $(SRC)))

INCS =			$(addprefix -I, $(INCLUDE))

all :			$(NAME)

$(NAME) :		$(OBJS)
					ar rcs $@ $^

clean :
				$(RM) $(OBJS)

fclean :		clean
					$(RM) $(NAME)

re :			fclean all

.c.o:			$(SRCS)
					$(CC) -c -o $@ $< $(FLAGS)

.PHONY: all clean fclean re bonus