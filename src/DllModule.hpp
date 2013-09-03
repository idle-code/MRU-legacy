#ifndef DLL_MODULE_HPP
#define DLL_MODULE_HPP

#include "MruException.hpp"
#include "types.hpp"
#include <boost/shared_ptr.hpp>

namespace mru {

class DllModule {
public:
  typedef boost::shared_ptr<DllModule> Pointer;
  class Exception;
public:
  virtual ~DllModule(void) { }

  virtual void load(const FilePath &module_file) = 0;
  virtual bool isLoaded(void) const = 0;
  virtual void unLoad(void) = 0;

  virtual void* getSymbol(const char *symbol) = 0;

  template<typename SymbolType>
  SymbolType get(const char *symbol)
  {
    return reinterpret_cast<SymbolType>(getSymbol(symbol));
  }
};

class DllModule::Exception : public MruException {
public:
  Exception(const UnicodeString &message) throw()
    : MruException(message)
  { }
  
  ~Exception(void) throw()
  { }
};

} /* namespace mru  */

#endif /* DLL_MODULE_HPP */

