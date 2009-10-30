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

/*
Path const & Path::rooted()
{
  //If it exists, use the os realpath
  if(exists())
  {
    realPath();
    return *this;
  }
  //If this is a relative path, then root it with cwd
  if(isRelative())
    *this = currentWorkingDirectory() / *this;
  return *this;
}
*/
