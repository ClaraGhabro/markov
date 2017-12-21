#include <cstring>
#include <iostream>
#include <string>

#include "generate_vex.hh"
#include "parse_opt.hh"




int main(int argc, char** argv)
{
  fileName file_name = parse_opt(argc, argv);

  if (file_name.size_get() == 0)
    return 0;

  if (file_name.size_get() == -1 || file_name.size_get() == -2)
    return 1;

  std::cout << "le fichier out: " << file_name.output_get() << std::endl;

  generate_vex(file_name.output_get(), file_name.size_get());


  return 0;
}
