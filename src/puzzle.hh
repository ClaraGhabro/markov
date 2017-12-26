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

  int error(unsigned tile_pos);

public:
  std::ostream& print_puzzle(std::ostream& o);

private:
  unsigned size_;
  std::vector<Tile> piece_;
};

std::ostream& operator<<(std::ostream& o, Puzzle p);

# include "puzzle.hxx"

#endif /* !PUZZLE_HH_ */
