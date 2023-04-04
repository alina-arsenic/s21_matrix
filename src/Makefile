PLATFORM := $(shell uname)
CFLAGS = -std=c11 -Wall -Werror -Wextra
TFLAGS = -lc --coverage
PKG = `pkg-config --cflags --libs check`
SRC = s21_*.c
OBJ = *.o
TESTS_SRC = tests/*.c

ifeq ($(PLATFORM), Linux)
OPEN = xdg-open 
else
OPEN = open
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a:
	gcc $(CFLAGS) -c $(SRC)
	ar rcs s21_matrix.a $(OBJ)
	ranlib s21_matrix.a
	rm -f *.o

test: s21_matrix.a
	gcc $(TESTS_SRC) $(SRC) -o ./tests/all_tests $(CFLAGS) $(PKG) $(TFLAGS) s21_matrix.a
	./tests/all_tests

gcov_report: test
	lcov -t "./tests/all_tests" -o gcov.info -c -d .
	genhtml -o gcov_report gcov.info
	@rm -rf ./*.gc* ./tests/*.gc*
	$(OPEN) gcov_report/index.html

style:
	cppcheck *.c *.h
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h tests/*.c
#	clang-format -i *.c *.h tests/*.c
	rm -f ./.clang-format

miniverter:
	cd ../materials/build; sudo sh ./run.sh; cd ../../src

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=VALGRIND.txt ./tests/all_tests

debug:
	gcc debug.c $(SRC) $(PKG); ./a.out

clean:
	rm -f *.o *.a *.gcda *.gcno *.info
	rm -fr gcov_report ./tests/all_tests
	rm -f ./a.out
	rm -rf ./tests/*.o ./tests/*.a ./tests/*.gcda ./tests/*.gcno ./tests/*.info
	rm -rf VALGRIND.txt
