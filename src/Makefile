GCC = g++ -std=c++17 -Wall -Werror -Wextra
BI = BUILD/
TST = test/
FLAGS = -lgtest -lpthread -lrt -lm
GCOV = -fprofile-arcs -ftest-coverage
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
    FLAGS = -lgtest
    GCOV = --coverage
endif

ifeq ($(UNAME),Linux)
    FLAGS = -lgtest -lpthread -lrt -lm
    GCOV = -fprofile-arcs -ftest-coverage
endif

SOURSES_1 := *.cpp
SOURSES := $(wildcard $(SOURSES_1))
OBJECTS := $(patsubst %.cpp, $(BI)%.o, $(SOURSES))

.PHONY: all clean test s21_matrix_oop.a style cppcheck

all: clean s21_matrix_oop.a

clean:
	rm -rf $(BI)*.o
	rm -rf $(BI)*.a
	rm -rf $(BI)test_
	rm -rf *.gcda *.gcno *.info report $(BI)gcov_rep

clean_lib:
	rm -rf lib

s21matrix.o: $(OBJECTS)

$(BI)%.o: %.cpp
	$(GCC) -c $< -o $@

s21_matrix_oop.a: s21matrix.o
	ar rcs $(BI)s21_matrix.a $(OBJECTS)
	ranlib $(BI)s21_matrix.a
	cp $(BI)s21_matrix.a $(BI)libs21_matrix.a

test: s21_matrix_oop.a test_fun
	$(GCC) $(TST)test.cpp $(BI)test_fun.o $(BI)s21_matrix.a $(FLAGS) -o $(BI)test_
	./$(BI)test_


gcov_report: test_fun
	$(GCC) -c -o $(BI)test.o $(TST)test.cpp $(FLAGS)
	$(GCC) $(GCOV) $(BI)test.o $(BI)test_fun.o $(SOURSES) $(FLAGS) -o $(BI)gcov_rep
	./$(BI)gcov_rep
	lcov -t "gcov_rep" --no-external --output-file=coverag.info --capture --directory .
	genhtml -o ./report coverag.info
	rm -rf *.gcda *.gcno *.info

test_fun:
	$(GCC) -c -o $(BI)test_fun.o $(TST)test_fun.cpp

style:
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem *.cpp *.h test/*.cpp

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(BI)test_

#main:
#	g++ main.cpp operators.cpp constructors.cpp operations.cpp calc_complements.cpp determinant.cpp inverse_matrix.cpp accessor_mutator.cpp -o mains
#	./mains

download:
	mkdir "lib"
	git clone https://github.com/google/googletest.git lib
