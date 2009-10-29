#include "path.ih"

#include <stdexcept>

Path Path::home()
{
  char *h = getenv("HOME");

  if (!h)
    throw runtime_error("Unable to correctly get the home directory");

  return Path(h);
}
