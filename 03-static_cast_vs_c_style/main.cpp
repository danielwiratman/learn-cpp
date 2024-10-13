#include <iostream>

using namespace std;

int
main()
{
	char c = 'a';

	cout << c << endl;
	cout << (void *) &c << endl;
	cout << static_cast<void *>(&c) << endl;

	return 0;
}
