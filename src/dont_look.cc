#include "puzzle.hh"


std::ostream& Puzzle::print_puzzle_2(std::ostream& o)
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


std::ostream& Puzzle::print_puzzle_3(std::ostream& o)
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

std::ostream& Puzzle::print_puzzle_4(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 4)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int n3 = piece_[i + 2].north_get();
    int n4 = piece_[i + 3].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int w3 = piece_[i + 2].west_get();
    int w4 = piece_[i + 3].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int e3 = piece_[i + 2].east_get();
    int e4 = piece_[i + 3].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();
    int s3 = piece_[i + 2].south_get();
    int s4 = piece_[i + 3].south_get();

    o << "  " << n1 << "     " << n2 << "     " << n3 << "     " << n4
      << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << " "
      << w3 << "   " << e3 << " "
      << w4 << "   " << e4 << std::endl;
    o << "  " << s1 << "     " << s2 << "     " << s3 << "     " << s4
      << std::endl;
  }
  return o;
}


std::ostream& Puzzle::print_puzzle_5(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 5)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int n3 = piece_[i + 2].north_get();
    int n4 = piece_[i + 3].north_get();
    int n5 = piece_[i + 4].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int w3 = piece_[i + 2].west_get();
    int w4 = piece_[i + 3].west_get();
    int w5 = piece_[i + 4].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int e3 = piece_[i + 2].east_get();
    int e4 = piece_[i + 3].east_get();
    int e5 = piece_[i + 4].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();
    int s3 = piece_[i + 2].south_get();
    int s4 = piece_[i + 3].south_get();
    int s5 = piece_[i + 4].south_get();

    o << "  "
      << n1 << "     "
      << n2 << "     "
      << n3 << "     "
      << n4 << "     "
      << n5 << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << " "
      << w3 << "   " << e3 << " "
      << w4 << "   " << e4 << " "
      << w5 << "   " << e5 << std::endl;
    o << "  "
      << s1 << "     "
      << s2 << "     "
      << s3 << "     "
      << s4 << "     "
      << s5 << std::endl;
  }
  return o;
}

std::ostream& Puzzle::print_puzzle_6(std::ostream& o)
{
  for (unsigned i = 0; i < size_ * size_ - 1; i += 6)
  {
    int n1 = piece_[i].north_get();
    int n2 = piece_[i + 1].north_get();
    int n3 = piece_[i + 2].north_get();
    int n4 = piece_[i + 3].north_get();
    int n5 = piece_[i + 4].north_get();
    int n6 = piece_[i + 5].north_get();
    int w1 = piece_[i].west_get();
    int w2 = piece_[i + 1].west_get();
    int w3 = piece_[i + 2].west_get();
    int w4 = piece_[i + 3].west_get();
    int w5 = piece_[i + 4].west_get();
    int w6 = piece_[i + 5].west_get();
    int e1 = piece_[i].east_get();
    int e2 = piece_[i + 1].east_get();
    int e3 = piece_[i + 2].east_get();
    int e4 = piece_[i + 3].east_get();
    int e5 = piece_[i + 4].east_get();
    int e6 = piece_[i + 5].east_get();
    int s1 = piece_[i].south_get();
    int s2 = piece_[i + 1].south_get();
    int s3 = piece_[i + 2].south_get();
    int s4 = piece_[i + 3].south_get();
    int s5 = piece_[i + 4].south_get();
    int s6 = piece_[i + 5].south_get();

    o << "  "
      << n1 << "     "
      << n2 << "     "
      << n3 << "     "
      << n4 << "     "
      << n5 << "     "
      << n6 << std::endl;
    o << w1 << "   " << e1 << " "
      << w2 << "   " << e2 << " "
      << w3 << "   " << e3 << " "
      << w4 << "   " << e4 << " "
      << w5 << "   " << e5 << " "
      << w6 << "   " << e6 << std::endl;
    o << "  "
      << s1 << "     "
      << s2 << "     "
      << s3 << "     "
      << s4 << "     "
      << s5 << "     "
      << s6 << std::endl;
  }
  return o;
}

