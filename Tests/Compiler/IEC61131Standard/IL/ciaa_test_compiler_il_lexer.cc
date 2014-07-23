/*! \brief This file is a test for Compiler/Il module, Scanner functionality.
    \file ciaa_test_compiler_il_lexer.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Thu Jul 17 22:34:52 UTC 2014

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
    \brief This file become from: Tests/Compiler/IEC61131Standard/IL/ciaa_test_compiler_il_lexer.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#include <cstdlib>
#include <cassert>
#include <cstdio>

#include <vector>
#include <string>
#include <fstream>
#include <functional>

#include "Code/Compiler/IEC61131Standard/Textuals/Common/Scanner/ciaa_compiler_lexer.h"

std::string read_from_file(char const* infile) {
    std::ifstream instream(infile);
    if (!instream.is_open()) {
        std::cerr << "Couldn't open file: " << infile << std::endl;
        exit(-1);
    }
    instream.unsetf(std::ios::skipws);      // No white space skipping!
    return std::string(std::istreambuf_iterator<char>(instream.rdbuf()),
                       std::istreambuf_iterator<char>());
}

int main(int argc,  char *argv[]) {
  assert(argc >= 2);
  std::vector<std::string> files;
  for (int i{1}; i < argc; ++i) {
    files.push_back(std::string{argv[i]});
  }

  ciaa::compiler::iec61131_3::text::Scanner scanner;
  for (std::string file : files) {
    std::printf("Building file: %s\n", file.c_str());
    std::string str{read_from_file(file.c_str())};
    char const* first{str.c_str()};
    char const* last{&first[str.size()]};


//    /*<  Create a pair of iterators returning the sequence of generated tokens
//    >*/  ciaa::compiler::il::Scanner::iterator_type iter = scanner.begin(first, last);
//        ciaa::compiler::il::Scanner::iterator_type end = scanner.end();

//    /*<  Here we simply iterate over all tokens, making sure to break the loop
//         if an invalid token gets returned from the lexer
//    >*/  while (iter != end && boost::spirit::lex::lexertl::token_is_valid(*iter))
//            ++iter;


//    boost::spirit::qi::symbols<char, SymbolTable_t> _symbol_table;
    bool r{boost::spirit::lex::tokenize(first,
                                        last,
                                        scanner)};

    /*                          std::bind(adder(),
                                        std::placeholders::_1,
                                        &_symbol_table)*/

    if (r) {
      std::printf("Lexical analysis Ok\n");
    } else {
      std::printf("proceced: %ld\n", first - str.c_str());
      std::printf("Lexical analysis failed\nstopped at: %s\n",
                  std::string{first, last}.c_str());
    }
  }
  return EXIT_SUCCESS;
}
