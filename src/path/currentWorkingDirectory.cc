/*
  This file is part of libecpp-filesystem.

  libecpp-filesystem is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  libecpp-filesystem is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "path.ih"

Path Path::currentWorkingDirectory()
{
#ifdef _GNU_SOURCE
  char *cwd = get_current_dir_name();
  std::string wd(cwd);
  free(cwd);
  return Path(wd);
#else
  #ifndef PATH_MAX
  #define PATH_MAX 1024
  #endif
    char *cwd = new char[PATH_MAX];
    if(getcwd(cwd, PATH_MAX) == 0)
    {
      delete[] cwd;
      throw Problem(Problem::Unable, "Unable to correctly get the current working directory");
    }
    std::string wd(cwd);
    delete[] cwd;
    return Path(wd);
#endif
  
}
