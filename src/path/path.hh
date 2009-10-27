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
    {}
    
    Path const &clean();
    Path const &cleaned() const
    {
      return Path(*this).clean();
    }
    
};

}//end of namespace cpp
