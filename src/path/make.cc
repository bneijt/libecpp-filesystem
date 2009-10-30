#include "path.ih"

bool Path::make()
{
  return !mkdir(d_path.c_str(),
		S_ISGID | S_IXUSR | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
}
