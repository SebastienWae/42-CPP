NAME = phonebook

RM = rm -rf

CC = c++
CFLAGS = -std=c++98 -g
WARNING = -Wall -Wextra -Werror

SRCS = main.cpp utils.cpp PhoneBook.cpp Contact.cpp
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
