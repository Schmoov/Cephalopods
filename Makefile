SHELL := /bin/bash
MY_CXX ?=g++-11 -std=c++20

ifeq ($(FF), true)
	CXXFLAGS := -Wall -Wextra -pedantic -fsanitize=undefined
endif

ifeq ($(DEBUG), true)
	CXXFLAGS := -Wall -Wextra -pedantic -g3 #
endif

LIB ?= -lm -lpthread -ldl -lcrypt
COMP := $(MY_CXX) $(CXXFLAGS) $(LIB)
COMP_BENCH := $(MY_CXX) -pg $(LIB)

NAME ?= bin
SRC := cepha.cpp

all: $(NAME)

$(NAME):
	$(COMP) $(SRC) -o $(NAME)

text :
	cat $(INC) $(SRC) > $(NAME).txt

test: re
	./test/run.sh

sub:
	xclip -selection clipboard < $(SRC)

bench: clean
	#$(COMP_BENCH) $(SRC) -o bench
	$(COMP_BENCH) -DBENCH $(SRC) -o bench
	./bench < test/txt/extra.txt
	gprof bench gmon.out | sed -E 's/std:://g; s/__detail::_//g; s/\bconst\b//g; s/<[^>]*>//g' > bench.txt
	#gprof bench gmon.out | grep -v "std::" > bench.txt
	rm gmon.out

clean:
	rm -f ./bin
	rm -f ./bin.txt
	rm -f ./bench
	rm -f ./bench.txt

re : clean all
