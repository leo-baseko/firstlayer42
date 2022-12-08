NAME =          libftprintf.a

RM =            rm -rf
CC =            gcc
FLAGS =         -Wall -Werror -Wextra

INCLUDE =       libftprintf.h \

SRC =           ft_printf.c \
				ft_putnbr_base.c

SRCBONUS =      ft_printf_bonus.c \

SRCS =          $(SRC)
OBJS =          $(addsuffix .o, $(basename $(SRC)))

OBJSBONUS       = $(SRCBONUS:.c=.o)

INCS =          $(addprefix -I, $(INCLUDE))

all :           $(NAME)

$(NAME) :       $(OBJS)
					ar rcs $@ $^

clean :
				$(RM) $(OBJS) $(OBJSBONUS)

fclean :		clean
					$(RM) $(NAME)

re :            fclean all

.c.o:			$(SRCS)
					$(CC) -c -o $@ $< $(FLAGS)

bonus :			$(OBJSBONUS)
					ar rcs $(NAME) $(OBJSBONUS)

.PHONY: all clean fclean re bonus