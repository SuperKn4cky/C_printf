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
		src/strdup.c			\
		src/cputs.c			\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

AR	:= 	make test

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
	$(CC) $(CFLAGS) src/main.c printf.a -o printf

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
