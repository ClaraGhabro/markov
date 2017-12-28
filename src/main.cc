#include <cstring>
#include <iostream>
#include <string>

#include "generate_vex.hh"
#include "get_input.hh"
#include "param.hh"
#include "parse_opt.hh"


int main(int argc, char** argv)
{
  Param parametre = parse_opt(argc, argv);

  if (parametre.size_get() == 0)
    return 0;

  Puzzle puzzle;
  if (parametre.input_get() == "no_input")
    puzzle = generate_vex(parametre);
  else
    puzzle = get_input(parametre);

  if (puzzle.size_get() == 0)
    return 1;

  puzzle.print_puzzle(std::cout);
  std::cout << "empty befor solve_me: "
            << puzzle.piece_get().empty() << std::endl;
  puzzle.solve_me();

  puzzle.print_puzzle(std::cout);
  // puzzle.save_me();

  return 0;
}
