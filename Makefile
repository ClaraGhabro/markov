CXX= g++
SRC_DIR= src

CXXFLAGS= -std=c++14 -pedantic -Wextra -Wall -Werror -g3 -ofast

SRC= main.cc generate_vex.cc
SRC:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ= ${SRC:.cc=.o}

PROJECT=epivex

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@  -lboost_program_options


check: $(PROJECT)
	./tests/check.sh


clean:
	$(RM) $(OBJ) $(PROJECT)
	$(RM) *.vex


.PHONY: clean check
