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

Path::Path(std::string const &path)
  :
  d_path(path)
{
  while(d_path.size() && d_path[d_path.size() -1] == '/')
    d_path = d_path.substr(0, d_path.size() -1);
}
