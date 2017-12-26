#ifndef PIECE_HH_
# define PIECE_HH_

# include <iostream>

class Tile
{
public:
  Tile(unsigned south, unsigned east, unsigned north, unsigned west);
  //    Tile(Tile& t);

  unsigned south_get();
  unsigned east_get();
  unsigned north_get();
  unsigned west_get();

  void south_set(unsigned s);
  void east_set(unsigned e);
  void north_set(unsigned n);
  void west_set(unsigned w);

  std::ostream& print_tile(std::ostream& o);

private:
  unsigned south_;
  unsigned east_;
  unsigned north_;
  unsigned west_;
};

std::ostream& operator<<(std::ostream& o, Tile t);

# include "piece.hxx"

#endif /* !PEICE_HH_ */
