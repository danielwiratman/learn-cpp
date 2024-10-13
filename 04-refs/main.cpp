#include <iostream>
using namespace std;

void
swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int
main()
{
	int a = 1;
	int b = 2;
	swap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
