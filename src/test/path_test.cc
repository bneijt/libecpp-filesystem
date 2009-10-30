#include <iostream>

#include "../path/path.hh"

using namespace std;
using namespace ecpp;

int main()
{
  Path p0("/home/test/bla/foo/bar");
  Path p1("/home/test");
  Path p2("./bla/foo");

  cout << "p0 = " << p0 << endl;
  cout << "p1 = " << p1 << endl;
  cout << "p2 = " << p2 << endl;
  cout << "p0 - p1 = " << (p0 - p1) << endl;
  cout << "p0.up() = " << p0.up() << endl;
  cout << "p0 / p1 = " << p0 / p1 << endl;
  cout << "p0.isRelative() = " << p0.isRelative() << endl;
  cout << "p2.isRelative() = " << p2.isRelative() << endl;

  return 0;
}
