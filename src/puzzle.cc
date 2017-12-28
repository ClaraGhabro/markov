#include "puzzle.hh"

#include <algorithm>
#include <ctime>
#include <cstdlib>

//   a     a
// b   c c   e
//   d     f
//   d     f
// g   h h   i
//   j     k

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

void Puzzle::swap_elt(int pos_1, int pos_2)
{
  std::iter_swap(this->piece_.begin() + pos_1, this->piece_.begin() + pos_2);
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
  std::random_device rd;
  std::mt19937 gen(rd());
  int error = 0;
  int temperature = 100000;
  std::srand(std::time(0));

  int iteration = 0;

  for (size_t i = 0; i < piece_.size(); ++i)
    error += this->error_2(i);
  error /= 2;
  int tmp_error = 0;

  while (temperature > 0.1 && error != 0)
  {
    int pos_1 = std::rand() % 4;
    int pos_2 = std::rand() % 4;
    // std::cout << "pos 1: " << pos_1 << std::endl;
    // std::cout << "pos 2: " << pos_2 << std::endl;

    if (pos_1 != pos_2)
    {
      this->swap_elt(pos_1, pos_2);
      tmp_error = 0;
      for (size_t i = 0; i < piece_.size(); ++i)
        tmp_error += this->error_2(i);
      tmp_error /= 2;

      double alea = std::generate_canonical<double, 10>(gen);
      // TODO calculer les proba de garder config degradante
      std::cout << "temperature: " << temperature << std::endl;
      if (tmp_error < error
          || alea < std::exp((error - tmp_error) / temperature))
      {
        iteration++;
        error = tmp_error;
      }
      else
        this->swap_elt(pos_1, pos_2);

      if (iteration % 20 == 0)
        temperature *= 0.999;
      std::cout << "error: " << error << std::endl;
    }
  }
}

// void Puzzle::solve_me_3()
// {
// }
//
// void Puzzle::solve_me_4()
// {
// }
