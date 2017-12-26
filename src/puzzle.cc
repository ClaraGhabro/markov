#include "puzzle.hh"

//   a     a
// b   c c   e
//   d     f
//   d     f
// g   h h   i
//   j     k

int Puzzle::error(unsigned tile_pos)
{
  int error = 0;
  switch (tile_pos)
  {
  case 0:
  {
    if (piece_[0].west_get() != piece_[1].east_get())
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

  // int x = tile_pos / this->size_;
  // int y = tile_pos / this->size_;

  tile_pos++;

  return error;
}

void Puzzle::solve_me()
{
  if (this->size_ == 2)
    this->solve_me_2();
  // else if (this->size_ == 3)
    // this->solve_me_3();
  // else if (this->size_ == 4)
    // this->solve_me_4();
}

void Puzzle::solve_me_2()
{
  int error = 0;
  for (size_t i = 0; i < piece_.size(); ++i)
    error += this->error(i);
  error /= 2;
  
  std::cout << "error: " << error << std::endl;

}

// void Puzzle::solve_me_3()
// {
// }
//
// void Puzzle::solve_me_4()
// {
// }
