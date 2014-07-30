/*! \brief Do not include this file directly in external modules.
    \file ciaa_compiler_programming_model.h
    \author Alvaro Denis Acosta Quesada <denisacostaq\@gmail.com>
    \date Sun Jul 27 18:05:52 UTC 2014

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
    \brief This file become from: Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_programming_model.h

    [ACSE-URL]: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/ "Asociación Civil para la Investigación, Promoción y Desarrollo de los Sistemas Electrónicos Embebidos"
    [CADIEEL-URL]: http://www.cadieel.org.ar "Cámara de Industrias Electrónicas, Electromecánicas y Luminotécnicas"
    [proyecto-ciaa-URL]: http://proyecto-ciaa.com.ar "Proyecto CIAA(Computador Industrial Abierta Argentina)"
    [proyecto-ciaa-PCSoftware-URL]: http://proyecto-ciaa.com.ar/gggg "PCSoftware bla bla"
*/


#ifndef CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H
#define CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H

#define DEUGGGGGG
#ifdef DEUGGGGGG
#define BOOST_SPIRIT_QI_DEBUG
#endif

#include <boost/spirit/include/qi.hpp>

#include "Code/Compiler/IEC61131Standard/Textuals/Grammar/ciaa_compiler_pou.h"

namespace ciaa {
namespace compiler {
namespace iec61131_3 {
namespace bsqi = boost::spirit::qi;

/*! \brief struct ciaaProgrammingModel implemment B.0 Programming model.
 */
template <typename Iterator>
struct ciaaProgrammingModel : boost::spirit::qi::grammar<Iterator, std::string> {
  ciaaProgrammingModel() : ciaaProgrammingModel::base_type(_library_element_declaration) {
    _library_element_declaration
        =  _function_declaration  // TODO(denisacostaq\@gmail.com): todo
        // function_block_declaration
        // program_declaration
        // configuration_declaration
        ;
  }

  ~ciaaProgrammingModel() = default;

  ciaaProgrammingModel(const ciaaProgrammingModel&) = delete;
  ciaaProgrammingModel& operator=(const ciaaProgrammingModel&) = delete;

  ciaaProgrammingModel(const ciaaProgrammingModel&&) = delete;
  ciaaProgrammingModel& operator=(const ciaaProgrammingModel&&) = delete;

  bsqi::rule<Iterator, std::string> _library_element_name;
  bsqi::rule<Iterator, std::string> _library_element_declaration;
  //ciaaPOU<Iterator> _function_declaration;
  bsqi::rule<Iterator, std::string> _function_declaration;
};
}  // namespace iec61131_3
}  // namespace compiler
}  // namespcae ciaa
#endif  // CIAA_COMPILER_IEC_PROGRAMMING_MODEL_H
