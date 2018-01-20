#ifndef PUZZLE_HH_
# define PUZZLE_HH_

# include "piece.hh"

# include <vector>
# include <iostream>


class Puzzle
{
public:
  Puzzle();
  Puzzle(unsigned size);
  //    ~Puzzle();

  unsigned size_get();
  std::vector<Tile> piece_get();
  void add_tile(Tile t);
  void shuffle_me();
  void solve_me();

private:
  void solve_me_2();
  void solve_me_3();
  void solve_me_4();
  void swap_elt(int pos_1, int pos_2);

  int error(unsigned tile_pos);
  int error_2(unsigned tile_pos);
  // int error_3(unsigned tile_pos);
  // int error_4(unsigned tile_pos);
  // int error_5(unsigned tile_pos);
  // int error_6(unsigned tile_pos);

public:
  std::ostream& print_puzzle(std::ostream& o);

private:
  std::ostream& print_puzzle_2(std::ostream& o);
  std::ostream& print_puzzle_3(std::ostream& o);
  std::ostream& print_puzzle_4(std::ostream& o);
  // std::ostream& print_puzzle_5(std::ostream& o);
  // std::ostream& print_puzzle_6(std::ostream& o);

private:
  unsigned size_;
  std::vector<Tile> piece_;
};

std::ostream& operator<<(std::ostream& o, Puzzle p);

# include "puzzle.hxx"

#endif /* !PUZZLE_HH_ */
