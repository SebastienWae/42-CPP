NAME = tests

RM = rm -rf

CC = c++
CFLAGS = -std=c++98
WARNING = -Wall -Wextra -Werror

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	$(COMPILE.c) $< $(WARNING) -o $@

.PHONY: clean fclean re
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(OBJS)
re: fclean all
