#ifndef GENERATE_HH_
# define GENERATE_HH_

# include <memory>

# include "param.hh"
# include "puzzle.hh"

Puzzle create_size_2(Param parametre);
Puzzle create_size_3(Param parametre);
Puzzle create_size_4(Param parametre);

Puzzle generate_vex(Param parametre);

#endif /* GENERATE_HH_ */
