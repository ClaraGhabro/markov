#pragma once

#include "param.hh"

inline Param::Param(unsigned size)
  : size_(size)
{}

inline Param::Param(const std::string& input,
                    const std::string& output,
                    unsigned size)
  : input_(input)
  , output_(output)
  , size_(size)
{}

inline std::string Param::input_get()
{
  return this->input_;
}

inline std::string Param::output_get()
{
  return this->output_;
}

inline unsigned Param::size_get()
{
  return this->size_;
}
