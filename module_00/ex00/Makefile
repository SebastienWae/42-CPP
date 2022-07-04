NAME = megaphone

RM = rm -rf
MKDIR = mkdir -p

SRC_DIR = src
OUT_DIR = out
DEBUG_DIR = debug

CC = c++
CFLAGS = -std=c++98
WARNINGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(addprefix $(OUT_DIR)/,$(SRCS:%.cpp=%.o))
OBJS_DEBUG = $(addprefix $(DEBUG_DIR)/,$(SRCS:%.cpp=%.o))

.PHONY: all
all: $(NAME)

$(OUT_DIR)/%.o: %.cpp
	$(MKDIR) $(@D)
	$(COMPILE.c) $< $(WARNING) -o $@

$(DEBUG_DIR)/%.o: %.cpp
	$(MKDIR) $(@D)
	$(COMPILE.c) $< $(WARNING) -o $@

.PHONY: clean fclean re
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
clean: 
	$(RM) $(OUT_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: debug debug_clean debug_fclean debug_re
debug: CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer \
	-fno-optimize-sibling-calls
debug: WARNING = -Wall -Wextra
debug: $(OBJS_DEBUG)
	$(CC) $(CFLAGS) $(OBJS_DEBUG) $(LDFLAGS) -o $(NAME)_debug
debug_clean:
	$(RM) $(DEBUG_DIR)
debug_fclean: debug_clean
	$(RM) $(NAME)_debug
debug_re: debug_fclean debug

.PHONY: cc check_cc check_infer check_gcc
cc:
	bear -- make re
check_cc: cc
	codechecker analyze compile_commands.json -o .cc
	codechecker parse .cc
check_infer: re
	infer run -- make re
check_gcc: CFLAGS = -fanalyzer
check_gcc:
	$(MAKE) CFLAGS=$(CFLAGS) OUT_DIR=check NAME=$(NAME)_check
	$(RM) check
	$(RM) $(NAME)_check
