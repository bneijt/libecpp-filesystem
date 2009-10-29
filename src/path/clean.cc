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

#include "path.ih"

Path const &Path::clean()
{
	//TODO Use a standard function for this, I might overlook something here
 	//Strip filename of excess ../ parts
 	__debug(2, "Clean path from: " << d_path);
 	istringstream f(d_path);
  size_t partNum = 0;
 	vector<string> path;
	//Split path into parts
 	while(true)
 	{
		string part;
		getline(f, part, '/');
    ++partNum;
		if(!f)
			break;
	  
	  //Double slash lower in the path is ignored ("//" or "/hello//something")
	  //  but we can not ignore the first empty part, so we keep partNum as a reference
	  if(part.empty() && partNum != 1)
	    continue;
	  
	  //Skip pushing a single .
	  if(part == ".")
	    continue;

	  //If it's .. , then pop the last pushed part
	  if(part == ".." && path.size() > 0)
	  {
	    path.pop_back();
	    continue;
	  }
      
    __debug(4, "push " << part << "/");
		path.push_back(part + "/");
	}
	string clean = accumulate(path.begin(), path.end(), string());

 	//Strip last "/" if it is not the first slash
 	if(clean.size() > 1)
   	clean = clean.substr(0, clean.length() -1);
 	
 	//Strip superflourous './' for local path
  if(clean[0] == '.' && clean[1] == '/')
 	  clean = clean.substr(2);
  //Return a single "." if we want the current path
 	if(clean.empty())
 	  clean = ".";
  __debug(2, "Cleaned path to: " << clean);
  d_path = clean;
  return *this;
}
