#include "parse_opt.hh"

#include <fstream>
#include <iostream>

namespace bpo = boost::program_options;


int get_input(std::string in_file) //, Puzzle p)
{
  std::ifstream ifs;
  ifs.open(in_file);
  if (!ifs.good())
    return 3;

  while (!ifs.eof())
  {
    int n = 0;
    char buf[512];
    ifs.getline(buf, 512);

    const char* token[512] = {};
    token[0] = strtok(buf, " ");
    if (token[0])
    {
      if (*token[0] < '0' || *token [0] > '9')
        return 4;
      for (n = 1; n < 512; n++)
      {
        token[n] = strtok(0, " ");
        if (!token[n])
          break;
        if (*token[n] < '0' || *token [n] > '9')
          return 4;
      }

      for (int i = 0; i < n; i++) // n = #of tokens
        std::cout << "Token[" << i << "] = " << token[i] << std::endl;
      std::cout << std::endl;
    }

  }
  ifs.close();

  return 0;

}



fileName parse_opt(int argc, char** argv)
{
  bpo::options_description desc("Options");
  bpo::variables_map vm;

  desc.add_options()
    ("help,h", "Display the help" )
    ("output,o", bpo::value<std::string>()->default_value("out.vex"),
     "Generate/solve puzzle in file out.vex")
    ("input,i", bpo::value<std::string>(), "Solve puzzle in file in.vex")
    ("size,s", bpo::value<int>()->default_value(2) , "Size of the tetravex");

  try
  {
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    std::cout << "size: " << vm.count("size") << std::endl;
    std::cout << "input: " << vm.count("input") << std::endl;
    std::cout << "output: " << vm.count("output") << std::endl;
    std::cout << "help: " << vm.count("help") << std::endl;

    // Check combined options
    if (vm.count("help"))
    {
      std::cout << desc << std::endl;
      return fileName(0);
    }
     if (!vm.count("input"))
     {
       std::cerr << desc << std::endl;
       return fileName(-1);
     }

     fileName file_name(vm["input"].as<std::string>(),
                        vm["output"].as<std::string>(),
                        vm["size"].as<int>());


    return file_name;

  }
  catch (std::exception& e)
  {
    std::cerr << desc;
    return fileName(-2);
  }
}

