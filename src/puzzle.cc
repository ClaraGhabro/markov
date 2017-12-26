#include "puzzle.hh"

int error(unsigned tile_pos)
{
  tile_pos++;
  int error = 0;

  return error;
}

void Puzzle::solve_me()
{
  if (this->size_ == 2)
    this->solve_me_2();
  else if (this->size_ == 3)
    this->solve_me_3();
  else if (this->size_ == 4)
    this->solve_me_4();
}
