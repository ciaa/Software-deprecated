/*! \brief This file give the functionality to ciaaParserIL class.
    \file ciaa_compiler_parser_il.cc
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Mon Jul 28 16:19:42 UTC 2014

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
    \brief , especifically in the [<strong>PC Software subproject</strong>]
    \brief [proyecto-ciaa-PCSoftware-URL] for tests in the Compiler module.\n
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_parser_il.cc

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/

#include "Code/Compiler/IEC61131Standard/Textuals/IL/ciaa_compiler_parser_il.h"


#include "Code/Compiler/IEC61131Standard/Textuals/ciaa_compiler_pou.h"
#include "Code/Compiler/IEC61131Standard/Textuals/Lexer/ciaa_compiler_scanner.h"


#include <iostream>

ciaaParserIL::ciaaParserIL() {
  std::string str{read_from_file("argv[1]")};

  // create the token definition instance needed to invoke the lexical analyzer
    typedef ciaaScanner<std::string::const_iterator> lexer_type;
    lexer_type lexer;

    typedef std::string::const_iterator base_iterator_type;
    typedef lexer_type::iterator_type iterator_type;
    client::error_handler<base_iterator_type, iterator_type>
        error_handler(str.begin(), str.end());             // Our error handler

    ciaa::compiler::iec61131_3::ciaaPOU<lexer_type::iterator_type> parser{lexer};

    std::string ast;

    base_iterator_type first = str.begin();
    base_iterator_type last = str.end();
    bool r{qi::parse(lexer.begin(first, last), lexer.end(), parser, ast)};

    //std::cout << "|" << ast._exp << "|" << std::endl;
    //parser.check(ast);

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
      error_handler.dump_error_line(first);
      std::cout << "Parse failure\n";
    }
}
