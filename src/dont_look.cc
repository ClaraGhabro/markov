#include "puzzle.hh"

//   a     a     a
// b   c c   e e   n
//   d     f     l
//   d     f     l
// g   h h   i e   n
//   j     k     m
//   j     k     m
// o   p p   q q   r
//   s     t     u

int Puzzle::error_2(unsigned tile_pos)
{
  int error = 0;
  switch (tile_pos)
  {
  case 0:
  {
    if (piece_[0].east_get() != piece_[1].west_get())
      error += 1;
    if (piece_[0].south_get() != piece_[2].north_get())
      error += 1;
    break;
  }
  case 1:
  {
    if (piece_[1].west_get() != piece_[0].east_get())
      error += 1;
    if (piece_[1].south_get() != piece_[3].north_get())
      error += 1;
    break;
  }
  case 2:
  {
    if (piece_[2].east_get() != piece_[3].west_get())
      error += 1;
    if (piece_[2].north_get() != piece_[0].south_get())
      error += 1;
    break;
  }
  case 3:
  {
    if (piece_[3].west_get() != piece_[2].east_get())
      error += 1;
    if (piece_[3].north_get() != piece_[1].south_get())
      error += 1;
    break;
  }
  }

  return error;
}

/**
   s
 a a a a
 a a a a
 a a a a
 a a a a
if (tile_pos + 1 % size_ == 0 && tile_pos < size_ * (size_ - 1) )
  ne pas faire le voisin de droite
if (tile_pos > size_ * (size_ - 1))
  ne pas faire le voisin du dessous


  */


