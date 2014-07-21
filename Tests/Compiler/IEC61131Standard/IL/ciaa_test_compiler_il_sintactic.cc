/*! \brief This file is a test for Compiler/Il module, Parcer functionality.
    \file ciaa_test_compiler_il_sintactic.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Fri Jul 18 18:11:23 UTC 2014

    \attention <h1><center><strong>&copy;COPYRIGHT 2014 </strong>[<strong>ACSE</strong>]
               [ACSE-URL] & [<strong>CADIEEL</strong>][CADIEEL-URL]</center></h1>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.


    \brief This file is part of [<strong>CIAA Project</strong>][proyecto-ciaa-URL]
    \brief especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler/IL module.\n
    \brief This file become from: Tests/Compiler/IEC61131Standard/IL/ciaa_test_compiler_il_sintactic.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

//#include <cstdlib>
//#include <cstdio>
//#include <cassert>

//#include <vector>
//#include <string>

//#include "Code/Compiler/IEC61131Standard/IL/Parser/ciaa_compiler_il_parcer.h"

//int main(int argc, char *argv[]) {
//  assert(argc >= 2);
//  std::vector<std::string> files;
//  for (int i{1}; i < argc; ++i) {
//    files.push_back(std::string{argv[i]});
//  }
//  return EXIT_SUCCESS;
//}


























#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "Code/Compiler/IEC61131Standard/IL/Parser/ciaa_compiler_il_parcer.h"

std::string
read_from_file(char const* infile) {
    std::ifstream instream(infile);
    if (!instream.is_open()) {
        std::cerr << "Couldn't open file: " << infile << std::endl;
        exit(-1);
    }
    instream.unsetf(std::ios::skipws);      // No white space skipping!
    return std::string(std::istreambuf_iterator<char>(instream.rdbuf()),
                       std::istreambuf_iterator<char>());
}

int main(int argc, char *argv[]) {

//  boost::spirit::utree miut;
//  typedef struct astAtribute_t {
//      int val;
//      double t;
//  } astAtribute;
//  astAtribute_t as{10, 45.4};
//  miut.push_back(as);
//  std::cout << "miut.which() " << miut.which() << std::endl;
//    astAtribute_t miut2 = miut.get();
//    std::cout << "val " << miut2.val << " t " << miut2.t << std::endl;













  std::string str = read_from_file(1 == argc ? "/home/adacosta/WORK/Project/CIAA/Software/Tests/Coder/IL/source.in" : argv[1]);

  // create the token definition instance needed to invoke the lexical analyzer
  typedef ciaa::compiler::il::ciaaLexer<lex::lexertl::actor_lexer<>> lexer_type;
  lexer_type lexer;

  char const* first = str.c_str();
  char const* last = &first[str.size()];

  //AST::program ut;
  li_grammar<lexer_type::iterator_type> parser{lexer /*&ut*/};

   bool r = qi::parse(lexer.begin(first, last), lexer.end(), parser);

  if (r) {
    std::printf("OK\n");
//    if (!ut.empty()) {
//      std::printf("[%d]\n", ut.size());
//      for (auto t  : ut) {
//        std::cout << t << std::endl;
//      }
//    }
  } else {
    std::fprintf(stderr, "Failed\n");
  }

  return 0;
}
