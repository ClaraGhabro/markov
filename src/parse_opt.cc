#include "parse_opt.hh"

#include <boost/program_options.hpp>
#include <iostream>
#include <string>

#include "param.hh"

namespace bpo = boost::program_options;

Param parse_opt(int argc, char** argv)
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

    std::string input;

    // Check combined options
    if (vm.count("help"))
    {
      std::cout << desc << std::endl;
      return Param(0);
    }

     if (!vm.count("input"))
       input = "no_file";
     else
       input = vm["input"].as<std::string>();

     Param parametre(input,
                        vm["output"].as<std::string>(),
                        vm["size"].as<int>());

    return parametre;
  }
  catch (std::exception& e)
  {
    std::cerr << desc;
    return Param(-2);
  }
}

