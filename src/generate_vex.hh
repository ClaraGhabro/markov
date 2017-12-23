#ifndef GENERATE_HH_
# define GENERATE_HH_

# include <memory>

# include "param.hh"
# include "puzzle.hh"

std::unique_ptr<Puzzle> create_size_2(Param parametre);
std::unique_ptr<Puzzle> create_size_3(Param parametre);
std::unique_ptr<Puzzle> create_size_4(Param parametre);

/*
void create_size_2(Puzzle p, std::ofstream fs);
void create_size_3(Puzzle p, std::ofstream fs);
void create_size_4(Puzzle p, std::ofstream fs);
*/


std::unique_ptr<Puzzle> generate_vex(Param parametre);
//int generate_vex(std::ofstream fs);


#endif /* GENERATE_HH_ */
