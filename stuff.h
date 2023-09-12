#include <iostream>

using namespace std;


class Stuff {

	friend ostream& operator<<(ostream& os, const Stuff& s);
	friend istream& operator>>(istream& os, Stuff& s);

public:

	Stuff(bool = true, int = 0, int = 0, int = 0);
	Stuff(const Stuff&);

	bool operator<(const Stuff& s);

	static int compareCount;


private:

	int a, b, c;

};
