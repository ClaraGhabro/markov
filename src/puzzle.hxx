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

inline std::ostream& Puzzle::print_puzzle_2(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 2)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();

    o << "  " << n1 << "     " << n2 << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << std::endl;
    o << "  " << s1 << "     " << s2 << std::endl;

  }
  return o;
}


inline std::ostream& Puzzle::print_puzzle_3(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 3)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int n3 = piece_[i + 2].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int w3 = piece_[i + 2].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int e3 = piece_[i + 2].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();
    int s3 = piece_[i + 2].south_get();

    o << "  " << n1 << "     " << n2 << "     " << n3 << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << " "
      << w3 << "   " << e3 << std::endl;
    o << "  " << s1 << "     " << s2 << "     " << s3 << std::endl;

  }
  return o;
}

inline std::ostream& Puzzle::print_puzzle_4(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 4)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int n3 = piece_[i + 2].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int w3 = piece_[i + 2].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int e3 = piece_[i + 2].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();
    int s3 = piece_[i + 2].south_get();

    o << "  " << n1 << "     " << n2 << "     " << n3 << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << " "
      << w3 << "   " << e3 << std::endl;
    o << "  " << s1 << "     " << s2 << "     " << s3 << std::endl;

  }
  return o;
}

inline std::ostream& Puzzle::print_puzzle(std::ostream& o)
{
  // std::string north = "  " + piece_[0].north_get();
  // north += "     " + piece_[1].north_get();
  // o << north << std::endl;
  if (size_ == 2)
    print_puzzle_2(o);
  else if (size_ == 3)
    print_puzzle_3(o);
  else if (size_ == 4)
    print_puzzle_4(o);

  // o << piece_[0] << piece_[1] << std::endl;
  // o << piece_[2] << piece_[3] << std::endl;

  return o;
}

inline std::ostream& operator<<(std::ostream& o, Puzzle p)
{
  return p.print_puzzle(o);
}
