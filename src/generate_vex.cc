#include "generate_vex.hh"

#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>



/*
int main(void)
{
  Tile t1(1, 2, 3, 4);
  t1.print_tile(std::cout);
  std::cout << t1 << '\n';

  Tile t2(5, 6, 7, 8);
  Tile t3(2, 4, 6, 8);
  Tile t4(1, 3, 5, 7);

  Puzzle p(2);
  std::cout << "get size: " << p.size_get() << '\n';

  p.add_tile(t1, 0, 0);

  p.add_tile(t2, 0, 1);
  p.add_tile(t3, 1, 0);
  p.add_tile(t4, 1, 1);

  p.print_puzzle(std::cout);
  std::cout << '\n';

  std::cout << p << '\n';

}*/

Puzzle create_size_2(Param parametre)
{
  Puzzle puzzle(parametre.size_get());
  int a1 = std::rand() % 10;
  int a2 = std::rand() % 10;
  int a3 = std::rand() % 10;
  int a4 = std::rand() % 10;
  puzzle.add_tile(Tile(a2, a1, std::rand() % 10, std::rand() % 10));
  puzzle.add_tile(Tile(a3, std::rand() % 10, std::rand() % 10, a1));
  puzzle.add_tile(Tile(std::rand() % 10, a4, a2, std::rand() % 10));
  puzzle.add_tile(Tile(std::rand() % 10, std::rand() % 10, a3, a4));

  std::ofstream fs;
  fs.open(parametre.output_get(), std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << parametre.size_get() << "\n" << puzzle;
  fs.close();

  puzzle.shuffle_me();
  return puzzle;
}

Puzzle create_size_3(Param parametre)
{
  Puzzle puzzle(parametre.size_get());

  int a1  = std::rand() % 10;
  int a2  = std::rand() % 10;
  int a3  = std::rand() % 10;
  int a4  = std::rand() % 10;
  int a5  = std::rand() % 10;
  int a6  = std::rand() % 10;
  int a7  = std::rand() % 10;
  int a8  = std::rand() % 10;
  int a9  = std::rand() % 10;
  int a10 = std::rand() % 10;
  int a11 = std::rand() % 10;
  int a12 = std::rand() % 10;


  puzzle.add_tile(Tile(a3, a1, std::rand() % 10, std::rand() % 10));
  puzzle.add_tile(Tile(a4, a2, std::rand() % 10, a1));
  puzzle.add_tile(Tile(a6, std::rand() % 10, std::rand() % 10, a2));
  puzzle.add_tile(Tile(a8, a5, a3, std::rand() % 10));
  puzzle.add_tile(Tile(a9, a7, a4, a5));
  puzzle.add_tile(Tile(a11, std::rand() % 10, a6, a7));
  puzzle.add_tile(Tile(std::rand() % 10, a10, a8, std::rand() % 10));
  puzzle.add_tile(Tile(std::rand() % 10, a12, a9, a10));
  puzzle.add_tile(Tile(std::rand() % 10, std::rand() % 10, a11, a12));

  std::ofstream fs;
  fs.open(parametre.output_get(), std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << parametre.size_get() << "\n" << puzzle;
  fs.close();

  puzzle.shuffle_me();
  return puzzle;
}


Puzzle create_size_4(Param parametre)
{
  Puzzle puzzle(parametre.size_get());

  int a1  = std::rand() % 10;
  int a2  = std::rand() % 10;
  int a3  = std::rand() % 10;
  int a4  = std::rand() % 10;
  int a5  = std::rand() % 10;
  int a6  = std::rand() % 10;
  int a7  = std::rand() % 10;
  int a8  = std::rand() % 10;
  int a9  = std::rand() % 10;
  int a10 = std::rand() % 10;
  int a11 = std::rand() % 10;
  int a12 = std::rand() % 10;
  int a13 = std::rand() % 10;
  int a14 = std::rand() % 10;
  int a15 = std::rand() % 10;
  int a16 = std::rand() % 10;
  int a17 = std::rand() % 10;
  int a18 = std::rand() % 10;
  int a19 = std::rand() % 10;
  int a20 = std::rand() % 10;
  int a21 = std::rand() % 10;
  int a22 = std::rand() % 10;
  int a23 = std::rand() % 10;
  int a24 = std::rand() % 10;

  puzzle.add_tile(Tile(a3, a1, std::rand() % 10, std::rand() % 10));
  puzzle.add_tile(Tile(a4, a2, std::rand() % 10, a1));
  puzzle.add_tile(Tile(a6, a13, std::rand() % 10, a2));
  puzzle.add_tile(Tile(a8, a5, a3, std::rand() % 10));
  puzzle.add_tile(Tile(a9, a7, a4, a5));
  puzzle.add_tile(Tile(a11, a15, a6, a7));
  puzzle.add_tile(Tile(a18, a10, a8, std::rand() % 10));
  puzzle.add_tile(Tile(a19, a12, a9, a10));
  puzzle.add_tile(Tile(a20, std::rand() % 10, a11, a12));
  puzzle.add_tile(Tile(a14, std::rand() % 10, std::rand() % 10, a13));
  puzzle.add_tile(Tile(a16, std::rand() % 10, std::rand() % 10, a15));
  puzzle.add_tile(Tile(a23, std::rand() % 10, std::rand() % 10, a17));
  puzzle.add_tile(Tile(std::rand() % 10, a20, a18, std::rand() % 10));
  puzzle.add_tile(Tile(std::rand() % 10, a22, a19, a20));
  puzzle.add_tile(Tile(std::rand() % 10, a24, a21, a22));
  puzzle.add_tile(Tile(std::rand() % 10, std::rand() % 10, a23, a24));

  std::ofstream fs;
  fs.open(parametre.output_get(), std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << parametre.size_get() << "\n" << puzzle;

  fs.close();

  puzzle.shuffle_me();
  return puzzle;
}


Puzzle generate_vex(Param parametre)
{
  std::srand(std::time(0));
  //  std::cout << "size: " << size << '\n';

  unsigned size = parametre.size_get();
  if (size == 2)
    return create_size_2(parametre);

  else if (size == 3)
    return create_size_3(parametre);

  else
    return create_size_4(parametre);
}
