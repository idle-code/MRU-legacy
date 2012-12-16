#ifndef PATTERNS_HPP
#define PATTERNS_HPP

namespace mru
{

template<typename Derived>
class singleton {
public:
  static Derived* get_instance(void);
  //FIXME: add method to destroy an instance?
private:
  static Derived *m_instance;  
};

template<typename Derived, typename ArgType1>
class singleton1 {
public:
  static Derived* get_instance(void);
  static Derived* get_instance(ArgType1 a_arg1);
  //FIXME: add method to destroy an instance?
private:
  static Derived *m_instance;  
};

/* ------------------------------------------------------------------------- */

template<typename Derived>
class factory_method {
public:
  virtual Derived* create(void);
  virtual void destroy(Derived *&a_instance);
};

/* ------------------------------------------------------------------------- */

template<typename Object>
class factory_function {
public:
  typedef factory_function self_type;
  typedef Object* (*create_function_type)(void);
  typedef void (*destroy_function_type)(Object *a_object);
public:
  factory_function(create_function_type a_create_handler, destroy_function_type a_destroy_handler =NULL);
  Object* create(void) const;
  void destroy(Object *&) const;
protected:
  create_function_type  m_create_function;
  destroy_function_type m_destroy_function;
};

} /* namespace mru */

#define PATTERNS_IMPL_HPP
#include "patterns_impl.hpp"
#undef PATTERNS_IMPL_HPP

#endif /* PATTERNS_HPP */
