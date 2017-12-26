#pragma once

#include <string>

class Param
{
public:
  Param(unsigned size);
  Param(const std::string& input,
        const std::string& output,
        unsigned size);


  std::string input_get();
  std::string output_get();
  unsigned size_get();


private:
  std::string input_;
  std::string output_;
  unsigned size_;
};

#include "param.hxx"
