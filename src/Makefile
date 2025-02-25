CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck

TARGET=s21_string.a

SRC=$(wildcard s21_*.c)
TEST_SRC=$(wildcard ./unit_tests/*.c)
OBJ=$(patsubst %.c,%.o, $(SRC))


OS= $(shell uname -s)

ifeq ($(OS), Darwin)
	OPEN_CMD = open
else
	OPEN_CMD = xdg-open
endif

all: $(TARGET)
$(TARGET): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC) 
	@ar rcs $@ $(OBJ)
	@ranlib $@
	@rm -rf *.o

test: $(TARGET)
ifeq ($(OS), Darwin)
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $^ -o unit_test $(LIBS) 
else
	@rm -f *.gcda
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $^ -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	@./unit_test

gcov_report: clean test
	@lcov -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	@$(OPEN_CMD) ./report/index.html

clang:
	@clang-format -i *.c *.h
	@clang-format -i ./unit_tests/*.c ./unit_tests/*.h
	@clang-format -n *.c *.h
	@clang-format -n ./unit_tests/*.c ./unit_tests/*.h

clean:
	@rm -rf *.o
	@rm -rf *.a
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf report
	@rm -rf unit_test

.PHONY: all test gcov_report clang clean
