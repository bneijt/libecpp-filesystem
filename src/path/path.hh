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

    /**
     *  Create a path with path.
     */
    Path(std::string const &path);

    Path const &clean();

    Path const &cleaned() const;

    /**
     *  @returns true if the path exists on the filesystem.
     */
    bool exists() const;

    /**
     *  @returns true if this is an absolute path.
     */
    bool isAbsolute() const;

    /**
     *  @returns true if this is a relative path.
     */
    bool isRelative() const;

    /* realPath apparently not yet implemented!

    Path const &rooted();
    Path const &absolute() const
    {
    return Path(*this).rooted();
    }
    */
    //    Path const& realPath();

    /** \brief FUTURE Return the shortest accurate path possible

    This will create various notations and return the
    shortest version.

    Path const &simplify();
    Path const &simplified() const
    {
    return Path(*this).clean();
    }
    */

    ///\brief Join two or paths
    Path operator/(Path const &other) const;

    ///\brief Concatenate two paths
    Path operator+(Path const &other) const;


    /**
     *  Erases the first part of this path as far as it compares to other
     *  and returns this.
     */
    Path operator-(Path const &other) const;

    /**
     *  @returns a string representation of the path.
     */
    std::string const &str() const;

    /**
     *  @returns one directory up.
     */
    Path up() const;

    /**
     *  Attempt to make the path (as in mkdir).
     */
    bool make();

    ///Static members

    /**
     *  @returns the current working directory.
     */
    static Path currentWorkingDirectory();

    /**
     *  @returns the home directory of the current user.
     */
    static Path home();

  };

  inline std::ostream &operator<<(std::ostream &s, Path const &p)
  {
    return s << p.str();
  }

  inline Path const &Path::cleaned() const
  {
    return Path(*this).clean();
  }

  inline bool Path::isAbsolute() const
  {
    return d_path.size() && d_path[0] == '/';
  }

  inline bool Path::isRelative() const
  {
    return !isAbsolute();
  }

  inline std::string const &Path::str() const
  {
    return d_path;
  }



}//end of namespace cpp

#endif
