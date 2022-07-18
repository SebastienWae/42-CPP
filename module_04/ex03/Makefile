NAME = ex03

RM = rm -rf

CC = clang++
CFLAGS = -std=c++98 -gdwarf-4
WARNING = -Wall -Wextra -Werror

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(COMPILE.c) $< $(WARNING) -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

.PHONY: clean fclean re
clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
