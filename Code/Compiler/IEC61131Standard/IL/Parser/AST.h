//Fri May 23 19:18:36 CDT 2014

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <string>

#include <string>
#include <vector>

//#include <boost/variant/variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>


namespace AST {

//  struct instruction_declaration;

////  typedef boost::variant
////          <  nil
////          ,  unsigned int
//////          ,  boost::recursive_wrapper<instruction_declaration>
////          >
////  operand;

//  enum class Type {
//    real,
//    lreal
//  };

//  struct instruction {
//  };

//  struct instruction_declaration : public instruction {
//    std::string _id;
//    Type _type;
//  };

////  struct instructions {
////    std::vector<instruction> _instructions;
////  };

//  struct program {
//      instruction first;
//      //std::vector<instruction> rest;
//      std::vector<instruction_declaration> rest;
//  };


  ///////////////////////////////////////////////////////////////////////////
  //  The AST
  ///////////////////////////////////////////////////////////////////////////
  struct nil {};
  struct signed_;
  struct program;

  typedef boost::variant<
          nil
        , unsigned int
        , std::string
        , boost::recursive_wrapper<signed_>
        , boost::recursive_wrapper<program>
      >
  operand;

  struct signed_
  {
      char sign;
      operand operand_;
  };

  struct operation
  {
      char operator_;
      operand operand_;
  };

  struct program
  {
      operand first;
      std::list<operation> rest;
  };
}

BOOST_FUSION_ADAPT_STRUCT(
  AST::signed_,
  (char, sign)
  (AST::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
  AST::operation,
  (char, operator_)
  (AST::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
  AST::program,
  (AST::operand, first)
  (std::list<AST::operation>, rest)
)


//BOOST_FUSION_ADAPT_STRUCT (
//    AST::instruction_declaration,
//    (std::string, _id)
//    (AST::Type, _type)
//  )

//BOOST_FUSION_ADAPT_STRUCT (
//    AST::program,
//    (std::vector<AST::program>, _instructions)
//  )
