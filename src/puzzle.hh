#ifndef PUZZLE_HH_
# define PUZZLE_HH_

# include "piece.hh"

# include <vector>
# include <iostream>


class Puzzle
{
  public:
    Puzzle(unsigned s);
//    ~Puzzle();

    unsigned size_get();
    void add_tile(Tile t/*, unsigned x, unsigned y*/);

    std::ostream& print_puzzle(std::ostream& o);

  private:
    unsigned size_;
    std::vector<Tile> piece_;
};

std::ostream& operator<<(std::ostream& o, Puzzle p);

# include "puzzle.hxx"

#endif /* !PUZZLE_HH_ */
