#ifndef PIECE_HH_
# define PIECE_HH_

# include <iostream>

class Tile
{
public:
  Tile(int south, int east, int north, int west);
  //    Tile(Tile& t);

  int south_get();
  int east_get();
  int north_get();
  int west_get();

  void south_set(int s);
  void east_set(int e);
  void north_set(int n);
  void west_set(int w);

  std::ostream& print_tile(std::ostream& o);

private:
  int south_;
  int east_;
  int north_;
  int west_;
};

std::ostream& operator<<(std::ostream& o, Tile t);

# include "piece.hxx"

#endif /* !PEICE_HH_ */
