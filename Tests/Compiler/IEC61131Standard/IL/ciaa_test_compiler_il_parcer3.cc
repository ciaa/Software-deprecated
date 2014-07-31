//Tue Jul 29 00:46:14 UTC 2014

#include <cstdlib>
#include <cassert>

#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_parser_il.h"

int main(int argc, char *argv[]) {
  assert(argc > 1);
  ciaaParserIL par;
  for(int arg_index{1}; arg_index < argc; ++arg_index) {
    par.reset();
    par.build(std::string{argv[arg_index]}, "");
    if (par.errors().size() > 0) {
      std::vector<std::string> errors{par.errors()};
      for (std::string error : errors) {
        std::cout << "JOJO " << error << " JOJO" << std::endl;
      }
    } else {
      std::cout << "OK" << std::endl;
    }
  }
  return EXIT_SUCCESS;
}
