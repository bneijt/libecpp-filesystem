#include "path.ih"

#include <ecpp/utility/utility.hh>

Path Path::operator/(Path const &other) const
{
  //TODO Move this split into path itself as a string split will not take "\/" into account
  // Split path into separate elements and concatenate.
  vector<string> a = String::split(d_path,"/") + String::split(other.d_path,"/");

  // Normalize path.
  for (vector<string>::iterator i = a.begin(); i != a.end();)
    if ((*i).empty() && i != a.begin())
      i = a.erase(i);
    else
      ++i;

  // combine separate elements back into a path.
  return Path(String::combine(a,"/"));
}

Path Path::operator+(Path const &other) const
{
  // Concat two paths
  if(other.isRelative())
    return Path(d_path + "/" + other.d_path);
  return Path(d_path + other.d_path);  
}

Path Path::operator-(Path const &other) const
{
  Path res(d_path);

  if (d_path.size() >= other.d_path.size() && d_path.substr(0,other.d_path.size()) == other.d_path)
    res.d_path = d_path.substr(other.d_path.size(),d_path.size()-other.d_path.size());

  return res;
}
