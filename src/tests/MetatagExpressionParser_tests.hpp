#ifndef METATAG_EXPRESSION_PARSER_TESTS_HPP
#define METATAG_EXPRESSION_PARSER_TESTS_HPP

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "MetatagExpressionParser.hpp"
#include "types.hpp"

using namespace CppUnit;
using namespace mru;

class MetatagExpressionParser_tests : public TestCase {
public:
  void setUp(void);

  void empty_expr(void);
  void static_expr(void);
  void flat_expr(void);
  void nested_expr(void);

  CPPUNIT_TEST_SUITE(MetatagExpressionParser_tests);
    //CPPUNIT_TEST(empty_expr);
    //CPPUNIT_TEST(static_expr);
    CPPUNIT_TEST(flat_expr);
    //CPPUNIT_TEST(nested_expr);
  CPPUNIT_TEST_SUITE_END();

private:
  typedef MetatagExpression::Parser Parser;
  Parser parser;
  Parser::TagEntry::Pointer expected_expression_root;
  Parser::TagEntry::Pointer expression_root;
  UnicodeString expr_str;

  void compare_entry_trees(const Parser::TagEntry::Pointer provided_expression_root) const;
  void compare_entries(const Parser::TagEntry::Pointer expected_entry, const Parser::TagEntry::Pointer provided_entry) const;
};

#define ADD_ENTRY(POS,NAME,ARGS) \
  areaOfEffectMembers.push_back(Parser::TagEntry::Pointer(new Parser::TagEntry(POS,NAME,ARGS)))


#endif /* METATAG_EXPRESSION_PARSER_TESTS_HPP */

