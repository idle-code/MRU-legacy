#ifndef OUTPUT_PLUGIN_HPP
#define OUTPUT_PLUGIN_HPP

#include "plugins/MruPlugin.hpp"

namespace mru
{

/* ------------------------------------------------------------------------- */

class OutputPlugin : public MruPlugin {
public:
  typedef boost::shared_ptr<OutputPlugin> Pointer;
  MODULE_EXCEPTION(OutputPlugin, MruPlugin::Exception);

  OutputPlugin(void)
    : create_new_path(false), override_target(false)
  { }

  virtual void createDirectory(const FilePath &path) = 0;
  virtual void removeDirectory(const FilePath &path) = 0;

  virtual bool exists(const FilePath &path) const = 0;

  virtual void move(const FilePath &source_path, const FilePath &destination_path) = 0;
  virtual void copy(const FilePath &source_path, const FilePath &destination_path) = 0;
  virtual void link(const FilePath &source_path, const FilePath &destination_path) = 0;
  virtual FilePath resolveLink(const FilePath &path) const = 0;

  void createNewPath(bool create)
  {
    create_new_path = create;
  }
  bool createNewPath(void) const
  {
    return create_new_path;
  }

  void overrideTarget(bool override)
  {
    override_target = override;
  }
  bool overrideTarget(void) const
  {
    return override_target;
  }

private:
  bool create_new_path;
  bool override_target;
};

typedef PluginManager<OutputPlugin> OutputPluginManager;

} /* namespace mru */

#define EXPORT_OUTPUT_PLUGIN_FACTORY(factory) \
  extern "C" { \
    void register_output_plugin(OutputPluginManager::Pointer plugin_manager) { \
      assert(plugin_manager); \
      plugin_manager->registerFactory(factory); \
    } \
  }


#endif /* OUTPUT_PLUGIN_HPP */

