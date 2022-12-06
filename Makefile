# E89 Pedagogical & Technical Lab
# project:     printf
# created on:  2022-11-22 - 09:39 +0100
# 1st author:  quentin.gimenez - quentin.gimenez
# description: Makefile

NAME	=	printf

SRCS	=	src/main.c			\
		src/printf.c			\
		src/strlen.c			\
		src/nb_len.c			\
		src/puts.c			\
		src/dputs.c			\
		src/pputs.c 			\
		src/pow.c			\
		src/strdup.c			\
		src/cputs.c

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
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

save:
	git status
	git add src/*.c include/*.h Makefile
	git commit -m "$(NAME) save"
	git push

exe:
	make re
	./$(NAME)
	make fclean

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
