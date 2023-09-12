#include "stuff.h"

int Stuff::compareCount = 0;

Stuff::Stuff(bool israndom, int x, int y, int z)
{
  if (israndom)
	{
	  a = rand() % 1000;
	  b = rand() % 1000;
	  c = rand() % 1000;
	}
  else
	{
	  a = x;
	  b = y; 
	  c = z;
	}
}

Stuff::Stuff(const Stuff& s)
{
   a = s.a;
   b = s.b;
   c = s.c;
}


bool Stuff::operator<(const Stuff& s)
{
   if (a < s.a)
	return true;
   else if (a == s.a)
	{
	   if (b < s.b)
		return true;
	   else if ((b == s.b) && (c < s.c))
		return true;
	}
   Stuff::compareCount++;
   return false;
}

ostream& operator<<(ostream& os, const Stuff& s)
{
   os << "(" << s.a << " " << s.b << " " << s.c << ")";
   return os;
}

istream& operator>>(istream& is, Stuff& s)
{
   is >> s.a >> s.b >> s.c;
   return is;
}
