CXX= g++
SRC_DIR= src

CXXFLAGS= -std=c++14 -pedantic -Wextra -Wall -Werror -O2 #-ofast
LDFLAGS= -lboost_program_options

SRC= main.cc generate_vex.cc parse_opt.cc get_input.cc puzzle.cc dont_look.cc
SRC:= $(addprefix $(SRC_DIR)/, $(SRC))


# OBJ= ${SRC:.cc=.o}

PROJECT=epivex

all: $(PROJECT)

$(PROJECT): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@


check: $(PROJECT)
	./tests/check.sh


clean:
	$(RM) $(OBJ) $(PROJECT)
	# $(RM) *.vex



.PHONY: clean check
