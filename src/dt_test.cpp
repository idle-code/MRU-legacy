#include <registry.hpp>
#include <debug_l.h>

int
main(int argc, char const *argv[])
{
  FO("main()");

  data_tree::registry dtree;

  int a = 3;
  data_tree::registry::path_type path = "root";
  //VAL(std::string(path));
  dtree.set(path/"a", static_cast<void*>(&a));
  dtree.set(path/"a"/"b", static_cast<void*>(NULL));
  dtree.set(path/"a"/"c", static_cast<void*>(NULL));
  //VAL(std::string(path/"foo"));
  dtree.set(path/"d", 123);
  //VAL(std::string(path/"bar"));
  dtree.set(path/"e", "some text");

  dtree.set(path/"e"/"f", "FFFF text");
  dtree.set(path/"e"/"f"/"g", "GGGGG");
  dtree.set("ala.kot", "mru");
  
  //VAL(dtree.get_or(path/"a", static_cast<void*>(NULL)).type());

  //VAL(dtree.get("test_sub.foo.bar").type());
  data_tree::print_tree(dtree);

  return 0;
}

