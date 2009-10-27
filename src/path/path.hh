/*
  This file is part of libecpp-module_name.

  libecpp-module_name is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  libecpp-mofule_name is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __inc_ecpp_path_hh__
#define __inc_ecpp_path_hh__

#include <string>

namespace ecpp
{

/**\brief Path handling object

  The path object is meant to handle everything you might want to do with a path:
    create an absolute form,
    join
    split
  
  Manipulating the filesystem:
    create a directory for it
    test it's status
*/
class Path
{
    std::string d_path;
  public:
    Path(std::string const &path)
      :
      d_path(path)
    {
      while(d_path[d_path.size() -1] == '/')
        d_path = d_path.substr(0, d_path.size() -1);
    }
    
    Path const &clean();
    Path const &cleaned() const
    {
      return Path(*this).clean();
    }
    ///\brief Join two or paths
    Path const &operator/(Path const &other) const
    {
      return Path(d_path + "/" + other.d_path);
    }
    
};

}//end of namespace cpp

#endif
