#pragma once

#include "puzzle.hh"

#include <algorithm>
#include <random>

inline Puzzle::Puzzle()
  : size_(0)
  , piece_{}
{
}

inline Puzzle::Puzzle(unsigned size)
  : size_(size)
  , piece_{}
{
}

inline unsigned Puzzle::size_get()
{
  return size_;
}

inline std::vector<Tile> Puzzle::piece_get()
{
  return piece_;
}

inline void Puzzle::add_tile(Tile t)
{
  piece_.push_back(t);
  std::cout << "taille apres add_tile: " << piece_.size() << std::endl;
}

inline void Puzzle::shuffle_me()
{
  static auto rng = std::default_random_engine {};
  std::shuffle(std::begin(piece_), std::end(piece_), rng);
}

inline std::ostream& Puzzle::print_puzzle(std::ostream& o)
{
  // std::string north = "  " + piece_[0].north_get();
  // north += "     " + piece_[1].north_get();
  // o << north << std::endl;
  if (size_ == 2)
    return print_puzzle_2(o);
  if (size_ == 3)
    return print_puzzle_3(o);
  if (size_ == 4)
    return print_puzzle_4(o);
  if (size_ == 5)
    return print_puzzle_5(o);
  if (size_ == 6)
    return print_puzzle_6(o);

  return o;
}

inline std::ostream& operator<<(std::ostream& o, Puzzle p)
{
  return p.print_puzzle(o);
}
