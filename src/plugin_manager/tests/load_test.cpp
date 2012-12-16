#define PLUGIN_HOST
#include "test_module.hpp"
#undef NDEBUG_L
#include <debug_l.h>

int
main(int argc, char const *argv[])
{
  DEBUG_L_FILTER(debug_l::lAll);
  //DEBUG_L_OUTPUT_FORMAT(debug_l::oAll);
  FO("main()");
  using namespace mru;
  MyPluginManager::set_instance(new MyPluginManager("MyPlugin"));
  YourPluginManager::set_instance(new YourPluginManager("YourPlugin"));

  MyPluginManager* my_pm = MyPluginManager::get_instance();
  YourPluginManager* your_pm = YourPluginManager::get_instance();

  VAL(my_pm);
  VAL(your_pm);

  if(0 == my_pm->load_module("./test_module1")) {
    ERR("No module named test_module1 found");
    //return 1;
  }

  if(0 == your_pm->load_module("./test_module2")) {
    ERR("No module named test_module2 found");
    //return 2;
  }

  MyPlugin *mplg1 = my_pm->create_plugin("MPlg1");
  MyPlugin *mplg2 = my_pm->create_plugin("MPlg2");
  YourPlugin *yplg = your_pm->create_plugin("YPlg");
  YourPlugin *yplg2 = your_pm->create_plugin("YPlg");


  if(mplg1)
    mplg1->say_hello();
  if(mplg2)
    mplg2->say_hello();
  if(yplg)
    yplg->say_goodbye();
  if(yplg2)
    yplg2->say_goodbye();

  data_tree::print_tree(my_pm->tree()); 
  data_tree::print_tree(your_pm->tree()); 

  my_pm->destroy_plugin(mplg1); 
  my_pm->destroy_plugin(mplg2); 
  your_pm->destroy_plugin(yplg);
  your_pm->destroy_plugin(yplg2);
  
  my_pm->destroy();
  my_pm = NULL;
  your_pm->destroy();
  your_pm = NULL;

  
  return 0;
}
