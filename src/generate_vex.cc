
#include "generate_vex.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include <ctime>
#include <cstdlib>


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

void create_size_2(Puzzle p, std::string file_out, unsigned size)
{
  int a1 = std::rand() % 10;
  int a2 = std::rand() % 10;
  int a3 = std::rand() % 10;
  int a4 = std::rand() % 10;
  p.add_tile(Tile(a2, a1, std::rand() % 10, std::rand() % 10));
  p.add_tile(Tile(a3, std::rand() % 10, std::rand() % 10, a1));
  p.add_tile(Tile(std::rand() % 10, a4, a2, std::rand() % 10));
  p.add_tile(Tile(std::rand() % 10, std::rand() % 10, a3, a4));

  std::ofstream fs;
  fs.open(file_out, std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << size << "\n" << p;
}

void create_size_3(Puzzle p, std::string file_out, unsigned size)
{
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


  p.add_tile(Tile(a3, a1, std::rand() % 10, std::rand() % 10));
  p.add_tile(Tile(a4, a2, std::rand() % 10, a1));
  p.add_tile(Tile(a6, std::rand() % 10, std::rand() % 10, a2));
  p.add_tile(Tile(a8, a5, a3, std::rand() % 10));
  p.add_tile(Tile(a9, a7, a4, a5));
  p.add_tile(Tile(a11, std::rand() % 10, a6, a7));
  p.add_tile(Tile(std::rand() % 10, a10, a8, std::rand() % 10));
  p.add_tile(Tile(std::rand() % 10, a12, a9, a10));
  p.add_tile(Tile(std::rand() % 10, std::rand() % 10, a11, a12));

  std::ofstream fs;
  fs.open(file_out, std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << size << "\n" << p;
}


void create_size_4(Puzzle p, std::string file_out, unsigned size)
{
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

  p.add_tile(Tile(a3, a1, std::rand() % 10, std::rand() % 10));
  p.add_tile(Tile(a4, a2, std::rand() % 10, a1));
  p.add_tile(Tile(a6, a13, std::rand() % 10, a2));
  p.add_tile(Tile(a8, a5, a3, std::rand() % 10));
  p.add_tile(Tile(a9, a7, a4, a5));
  p.add_tile(Tile(a11, a15, a6, a7));
  p.add_tile(Tile(a18, a10, a8, std::rand() % 10));
  p.add_tile(Tile(a19, a12, a9, a10));
  p.add_tile(Tile(a20, std::rand() % 10, a11, a12));
  p.add_tile(Tile(a14, std::rand() % 10, std::rand() % 10, a13));
  p.add_tile(Tile(a16, std::rand() % 10, std::rand() % 10, a15));
  p.add_tile(Tile(a23, std::rand() % 10, std::rand() % 10, a17));
  p.add_tile(Tile(std::rand() % 10, a20, a18, std::rand() % 10));
  p.add_tile(Tile(std::rand() % 10, a22, a19, a20));
  p.add_tile(Tile(std::rand() % 10, a24, a21, a22));
  p.add_tile(Tile(std::rand() % 10, std::rand() % 10, a23, a24));

  std::ofstream fs;
  fs.open(file_out, std::ofstream::out | std::ofstream::trunc);
  if (fs.is_open())
    fs << size << "\n" << p;
}


int generate_vex(std::string file_out, unsigned size)
{
  std::srand(std::time(0));
//  std::cout << "size: " << size << '\n';


  Puzzle p(size);
  if (size == 2)
    create_size_2(p, file_out, size);

  else if (size == 3)
    create_size_3(p, file_out, size);

  else
    create_size_4(p, file_out, size);

  return 0;

}
