#pragma once

#include "piece.hh"

inline Tile::Tile(unsigned s, unsigned e, unsigned n, unsigned w)
  : south_(s)
  , east_(e)
  , north_(n)
  , west_(w)
{}

inline unsigned Tile::south_get()
{
  return south_;
}

inline void Tile::south_set(unsigned s)
{
  south_ = s;
}

inline unsigned Tile::east_get()
{
  return east_;
}

inline void Tile::east_set(unsigned e)
{
  east_ = e;
}


inline unsigned Tile::north_get()
{
  return north_;
}

inline void Tile::north_set(unsigned n)
{
  north_ = n;
}

inline unsigned Tile::west_get()
{
  return west_;
}

inline void Tile::west_set(unsigned w)
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
