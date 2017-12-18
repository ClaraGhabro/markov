#pragma once

#include "puzzle.hh"

inline Puzzle::Puzzle(unsigned s)
  : size_(s)
  , piece_()
{
}

inline unsigned Puzzle::size_get()
{
  return size_;
}

inline void Puzzle::add_tile(Tile t)
{
  piece_.push_back(t);

}

inline std::ostream& Puzzle::print_puzzle(std::ostream& o)
{
  for (unsigned i = 0; i < this->size_; i++)
  {
    for (unsigned j = 0; j < this->size_; j++)
      o << piece_[i * size_ + j] << '\n';
  }

  return o;
}

inline std::ostream& operator<<(std::ostream& o, Puzzle p)
{
  return p.print_puzzle(o);
}
