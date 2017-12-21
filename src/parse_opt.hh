#ifndef PARSE_OPT_HH
# define PARSE_OPT_HH

#include <boost/program_options.hpp>
#include <string>

class fileName
{
public:
  fileName(int size)
  {
    this->size = size;
  }

  fileName(const std::string& input,
           const std::string& output,
           int size)
  {
    this->input = input;
    this->output = output;
    this-> size = size;
  }


  std::string input_get()
  {
    return this->input;
  }

  std::string output_get()
  {
    return this->output;
  }

  int size_get()
  {
    return this->size;
  }


private:
  std::string input;
  std::string output;
  int size = 0;
};

fileName parse_opt(int argc, char* argv[]);

#endif /* PARSE_OPT_HH */
