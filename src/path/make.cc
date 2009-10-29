#include "path.ih"

bool Path::make()
{
  return !mkdir(d_path.c_str(),S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
}
