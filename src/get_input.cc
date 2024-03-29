#include "get_input.hh"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "puzzle.hh"


Puzzle get_input(Param parametre)
{
  std::ifstream ifs;
  ifs.open(std::string(parametre.input_get()));
  if (!ifs.good())
    return Puzzle(0);

  Puzzle puzzle(parametre.size_get());
  while (!ifs.eof())
  {
    int n = 0;
    char buf[32];
    ifs.getline(buf, 32);

    const char* token[32] = {};
    token[0] = strtok(buf, " ");
    if (token[0])
    {
      if (*token[0] < '0' || *token [0] > '9')
        return Puzzle(0);
      for (n = 1; n < 32; n++)
      {
        token[n] = strtok(0, " ");
        if (!token[n])
          break;
        if (*token[n] < '0' || *token [n] > '9')
          return Puzzle(0);
      }
      // std::cout << "n: " << n << std::endl;

      if (n > 1)
      {
        int i = 0;
        unsigned north = std::atoi(token[i]);
        unsigned east = std::atoi(token[i + 1]);
        unsigned south = std::atoi(token[i + 2]);
        unsigned west = std::atoi(token[i + 3]);
        Tile tile(south, east, north, west);
        puzzle.add_tile(tile);
        // std::cout << "empty after add: " << puzzle.piece_get().empty() << std::endl;
      }

      // std::cout << "empty after for: " << puzzle.piece_get().empty() << std::endl;

      // for (int i = 0; i < n; i++) // n = #of tokens
      // std::cout << "Token[" << i << "] = " << token[i] << std::endl;
      // std::cout << std::endl;
    }

  }
  puzzle.print_puzzle(std::cout);
  puzzle.shuffle_me();
  puzzle.print_puzzle(std::cout);
  ifs.close();

  return puzzle;
}
