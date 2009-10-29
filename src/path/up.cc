#include "path.ih"

Path Path::up() const
{
  vector<string> split = String::split(d_path,"/");

  if (!split.empty())
    split.pop_back();

  return Path(String::combine(split,"/"));
}
