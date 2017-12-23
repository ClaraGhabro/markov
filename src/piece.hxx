#pragma once

#include "piece.hh"

inline Tile::Tile(int s, int e, int n, int w)
  : south_(s)
  , east_(e)
  , north_(n)
  , west_(w)
{}

inline int Tile::south_get()
{
  return south_;
}

inline void Tile::south_set(int s)
{
  south_ = s;
}

inline int Tile::east_get()
{
  return east_;
}

inline void Tile::east_set(int e)
{
  east_ = e;
}


inline int Tile::north_get()
{
  return north_;
}

inline void Tile::north_set(int n)
{
  north_ = n;
}

inline int Tile::west_get()
{
  return west_;
}

inline void Tile::west_set(int w)
{
  west_ = w;
}


inline std::ostream& Tile::print_tile(std::ostream& o)
{
  o << south_ << " " << east_ << " " << north_ << " " << west_;

  return o;
}

inline std::ostream& operator<<(std::ostream& o, Tile t)
{
  return t.print_tile(o);
}
