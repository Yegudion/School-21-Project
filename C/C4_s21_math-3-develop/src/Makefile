LIB=s21_math
NAME=$(LIB).a
HEADERS_DIR = .
HEADERS_FILES=$(LIB).h

HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
SRCS	= \
			s21_math.c

OBJ=$(SRCS:.c=.o)
INCLUDES=-I./

TEST_INCLUDES_DIR=.
TEST_INCLUDES=$(TEST_INCLUDES_DIR)/tests.h

TEST_DIR=tests
TEST_NAME=test.bin
TEST_SRCS_FILES= \
			test_main.c \
			test_pow.c \
			test_ceil.c \
			test_floor.c
TEST_SRCS = $(addprefix $(TEST_DIR)/, $(TEST_SRCS_FILES))
TEST_OBJS=$(TEST_SRCS:%.c=%.o)

REPORT_NAME=report.html

OS = $(shell uname)
ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lm -lpthread -lrt -lsubunit 
endif

CC=gcc -Wall -Wextra -std=c11 #-Werror 
CC_GCOV=gcc -Wall -Wextra -Werror -std=c11 \
			-fcf-protection=full -static-libgcc --coverage -lgcov
THREADS = 8

all: CC=$(CC_GCOV)
all:
	$(MAKE) -j$(THREADS) $(NAME)

gcov_report: CC=$(CC_GCOV)
gcov_report: fclean test
	gcovr -r . -f src --html -o $(REPORT_NAME)
	chmod +x *
	lcov -t $(TEST_NAME) -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info

test: $(TEST_NAME)
	@exec ./$(TEST_NAME)

style_check:
	clang-format -style=google -i *.c
	clang-format -style=google -i ./$(TEST_DIR)/*.c
	clang-format -style=google -i *.h
	clang-format -style=google -i ./$(TEST_DIR)/*.h

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC) $(FLAGS) $(TEST_OBJS) $(OBJ) -o $@ $(TEST_LIBS)

$(TEST_DIR)/%.o:$(TEST_DIR)/%.c $(TEST_INCLUDES)
	$(CC) $(FLAGS) -I./$(TEST_DIR)/includes -I./includes -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	

%.o:%.c $(HEADERS)
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo $<

# check: test
# 	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
# 	cp ../materials/linters/CPPLINT.cfg .
# 	python3 ../materials/linters/cpplint.py --extension=c *.c *.h *.c
# 	rm -rf CPPLINT.cfg
# 	make test
		
clean:
	@rm -rf **/*.o *.o gcov_test *.html *.css ./GcovReport **/*.gcno **/*.gcda *.gcno *.gcda ./report ./*.info ./math_o ./*.dSYM ./CPPLINT* 

fclean:
	@make -s clean
	@rm -rf ./*.a $(TEST_NAME)
re: fclean all

.PHONY: lib clean fclean all re multi
