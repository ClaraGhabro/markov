
//#include "parse_opt.hh"
#include "generate_vex.hh"


# include <boost/program_options.hpp>

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


namespace bpo = boost::program_options;

bpo::options_description desc("Options");
bpo::variables_map vm;

int parse_opt(int argc, char** argv)
{
  desc.add_options()
    ("help,h", "Display the help" )
    ("output,o", bpo::value<std::string>()->default_value("out"),
     "Generate/solve puzzle in file out.vex")
    ("input,i", bpo::value<std::string>(), "Solve puzzle in file in.vex")
    ("size,s", bpo::value<int>()->default_value(3) , "Size of the tetravex");


  try
  {
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    // Check combined options
    if (vm.count("input") && vm.count("help"))
    {
      std::cerr << desc << '\n';
      return 2;
    }

    if (vm.count("input") && vm.count("output"))
    {
      return 0;
    }

    if (vm.count("input") && vm.count("size"))
    {
      std::cerr << desc << '\n';
      return 2;
    }

/*
    if (vm.count("output") && vm.count("help"))
      return 2;
*/
    // Check if there is the help option
    if (vm.count("help"))
    {
      std::cout << desc << '\n';
      return 0;
    }

//  size
    if (vm.count("size"))
      return 0;
    else
      return 0;

  }
  catch (std::exception& e)
  {
    std::cerr << desc;
    return 2;
  }

}


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

/*    for (int i = 0; i < n; i++) // n = #of tokens
      std::cout << "Token[" << i << "] = " << token[i] << std::endl;
    std::cout << std::endl;
 */   }

  }

  return 0;

}







int main(int argc, char** argv)
{
  int parse = parse_opt(argc, argv);

  if (parse)
    return parse;

  std::string out_file;
  unsigned size;
  std::string in_file;

  if (vm.count("output"))
    out_file = vm["output"].as<std::string>();
  else
    out_file = "out";

  if (vm.count("input"))
  {
    in_file = vm["input"].as<std::string>();

    std::ifstream ifs;
    ifs.open(in_file);
    if (!ifs.is_open())
      return 3;
    if (get_input(in_file))
      return 4;

  }
  if (vm.count("size"))
    size = vm["size"].as<int>();
  else
    size = 3;


  //  std::cout << "le fichier out: " << out_file << '\n';

  generate_vex(out_file + ".vex", size);


  //  ifs.close();
  return 0;
}
