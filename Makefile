SRCS = ./src/ft_printf.c ./src/store_info.c ./src/verify_format.c ./src/utils.c \
		./print_types/print_controller.c ./print_types/print_d.c ./print_types/print_expression.c \
		./print_types/print_c.c ./print_types/print_u.c  ./print_types/print_s.c \
		./print_types/print_x.c ./print_types/print_p.c ./print_types/print_per.c


OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = 
CC = clang 

RM = rm -f

LIB_SOURCE = ./libft

MAIN = main.c

INCLUDE = ./include

all: $(NAME)

$(NAME): make_lib $(OBJS)
	cp $(LIB_SOURCE)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: make_lib $(OBJS)
	cp $(LIB_SOURCE)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME) $(MAIN:.c=.o)
	$(CC) $(CFLAGS) -o a.out $(MAIN:.c=.o) print.c -L. -lftprintf
	./a.out

make_lib:
	make -C $(LIB_SOURCE)

lib_fclean:
	make fclean -C $(LIB_SOURCE)

.PHONY: all clean fclean re make_lib lib_fclean