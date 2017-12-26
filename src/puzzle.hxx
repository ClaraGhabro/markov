#pragma once

#include "puzzle.hh"

#include <algorithm>
#include <random>

inline Puzzle::Puzzle()
  : size_(0)
  , piece_()
{
}

inline Puzzle::Puzzle(unsigned size)
  : size_(size)
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

inline void Puzzle::shuffle_me()
{
  auto rng = std::default_random_engine {};
  std::shuffle(std::begin(piece_), std::end(piece_), rng);
}


inline std::ostream& Puzzle::print_puzzle(std::ostream& o)
{
  for (unsigned i = 0; i < this->size_; i++)
    for (unsigned j = 0; j < this->size_; j++)
      o << piece_[i * size_ + j] << std::endl;

  return o;
}

inline std::ostream& operator<<(std::ostream& o, Puzzle p)
{
  return p.print_puzzle(o);
}
