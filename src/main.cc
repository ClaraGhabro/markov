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

  if (parametre.size_get() == -1 || parametre.size_get() == -2)
    return 1;

  auto puzzle = std::make_unique<Puzzle>();
  std::cout << "le fichier out: " << parametre.output_get() << std::endl;
  if (parametre.input_get() == "no_input")
    puzzle = generate_vex(parametre);
  else
    puzzle = get_input(parametre);

  puzzle.solve_me();

  return 0;
}
