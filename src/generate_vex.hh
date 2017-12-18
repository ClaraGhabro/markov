#ifndef GENERATE_HH_
# define GENERATE_HH_


# include "puzzle.hh"

void create_size_2(Puzzle p, std::string file_out, unsigned size);
void create_size_3(Puzzle p, std::string file_out, unsigned size);
void create_size_4(Puzzle p, std::string file_out, unsigned size);

/*
void create_size_2(Puzzle p, std::ofstream fs);
void create_size_3(Puzzle p, std::ofstream fs);
void create_size_4(Puzzle p, std::ofstream fs);
*/


int generate_vex(std::string file_out, unsigned size);
//int generate_vex(std::ofstream fs);


#endif /* GENERATE_HH_ */
