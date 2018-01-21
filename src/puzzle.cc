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
  std::random_device rd;
  std::mt19937 gen(rd());
  int err = 0;
  float temperature = 1000;
  std::srand(std::time(0));
  std::uniform_int_distribution<int> pos_dist(0, size_ * size_ - 1);
  std::uniform_real_distribution<float> dist(0.0f, 1.0f);

  int iteration_good = 0;
  int iteration_degradation = 0;
  int nothing = 0;

  for (size_t i = 0; i < piece_.size(); ++i)
    err += this->error(i);

  int tmp_error = 0;

  while (temperature > 0.01 && err != 0)
  {
    int pos_1 = pos_dist(gen);
    int pos_2 = pos_dist(gen);

    if (pos_1 != pos_2)
    {
      this->swap_elt(pos_1, pos_2);
      tmp_error = 0;
      for (size_t i = 0; i < piece_.size(); ++i)
        tmp_error += this->error(i);

      float alea = dist(gen);
      if (tmp_error < err)
      {
        iteration_good++;
        err = tmp_error;
      }
      else if (alea < std::exp((err - tmp_error) / temperature))
      {
        iteration_degradation++;
        err = tmp_error;
      }
      else
      {
        this->swap_elt(pos_1, pos_2);
        nothing++;
      }

      std::cout << "temperature: " << temperature << std::endl;
      std::cout << "error: " << err << '\n' << std::endl;

      if ((iteration_good + iteration_degradation + nothing) % 40 == 0)
        temperature *= 0.997;
    }
  }

  std::cout << "iteration good:         " << iteration_good << '\n'
            << "iteration degradation : " << iteration_degradation << '\n'
            << "doing noting: " << nothing << std::endl;
}
