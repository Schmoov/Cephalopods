SHELL := /bin/bash
MY_CXX ?=g++-11 -std=c++20
ifeq ($(FF), true)
	CXXFLAGS := -Wall -Wextra -pedantic
endif
ifeq ($(DEBUG), true)
	CXXFLAGS := -Wall -Wextra -pedantic -g3 #-fsanitize=undefined
endif
LIB ?= -lm -lpthread -ldl -lcrypt
COMP := $(MY_CXX) $(CXXFLAGS) $(LIB)

NAME ?= bin
INC := $(wildcard inc/*)
SRC := $(wildcard src/*)

all: $(NAME)

$(NAME):
	#cat $(INC) $(SRC) > $(NAME).txt
	$(COMP) $(SRC) -o $(NAME)

sub:
	cat $(INC) <(tail -q -n+2 $(SRC)) | xclip -selection clipboard

clean:
	rm -f ./bin

re : clean all sub
