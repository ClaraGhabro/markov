#include "puzzle.hh"

#include <algorithm>
#include <ctime>
#include <cstdlib>


int Puzzle::error(unsigned tile_pos)
{
  int error = 0;
  if (!((tile_pos + 1) % size_ == 0 && size_ * (size_ - 1)))
    if (piece_[tile_pos].east_get() != piece_[tile_pos + 1].west_get())
      error += 1;

  if (tile_pos < size_ * (size_ - 1))
    if (piece_[tile_pos].south_get() != piece_[tile_pos + size_].north_get())
      error += 1;

  return error;
}

void Puzzle::swap_elt(int pos_1, int pos_2)
{
  std::iter_swap(this->piece_.begin() + pos_1, this->piece_.begin() + pos_2);
}

void Puzzle::solve_me()
{
  // if (this->size_ == 2)
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
  int err = 0;
  float temperature = 100000;
  std::srand(std::time(0));

  int iteration = 0;

  for (size_t i = 0; i < piece_.size(); ++i)
    err += this->error(i);
  int tmp_error = 0;

  while (temperature > 0.1 && err != 0)
  {
    int pos_1 = std::rand() % (this->size_ * this->size_);
    int pos_2 = std::rand() % (this->size_ * this->size_);
    // std::cout << "pos 1: " << pos_1 << std::endl;
    // std::cout << "pos 2: " << pos_2 << std::endl;

    if (pos_1 != pos_2)
    {
      this->swap_elt(pos_1, pos_2);
      tmp_error = 0;
      for (size_t i = 0; i < piece_.size(); ++i)
        tmp_error += this->error(i);

      double alea = std::generate_canonical<double, 10>(gen);
      std::cout << "temperature: " << temperature << std::endl;
      if (tmp_error < err
          || alea < std::exp((err - tmp_error) / temperature))
      {
        iteration++;
        err = tmp_error;
      }
      else
        this->swap_elt(pos_1, pos_2);

      if (iteration % 20 == 0)
        temperature *= 0.999;
      std::cout << "error: " << err << std::endl;
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
