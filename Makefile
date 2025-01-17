# E89 Pedagogical & Technical Lab
# project:     printf
# created on:  2022-11-22 - 09:39 +0100
# 1st author:  quentin.gimenez - quentin.gimenez
# description: Makefile

NAME	=	printf.a

SRCS	=	src/printf.c			\
		src/strlen.c			\
		src/nb_len.c			\
		src/puts.c			\
		src/dputs.c			\
		src/pputs.c 			\
		src/pow.c			\
		src/cputs.c			\
		src/opt_s.c			\
		src/opt_d.c			\
		src/opt_c.c			\
		src/opt_p.c			\
		src/d_bourrage.c		\
		src/skip_bourrage.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

test:
	$(CC) $(CFLAGS) src/test_main.c printf.a -o printf

save:
	git status
	git add src/*.c include/*.h Makefile
	git commit -m "$(NAME) save"
	git push

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
