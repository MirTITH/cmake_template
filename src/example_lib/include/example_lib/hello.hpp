#pragma once

#include <example_lib/export_example_lib.hpp>
#include <string>

namespace Greeter {
/// Example class that is explicitly exported into a library
class EXAMPLE_LIB_EXPORT Hello {
public:
  Hello(const std::string &name) : name_{name} {}

  void greet() const;

private:
  const std::string name_;
};
} // namespace Greeter