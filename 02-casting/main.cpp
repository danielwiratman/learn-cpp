#include <iostream>
#include <string>

using namespace std;

int
main()
{
	int x = 12;
	float y = 3.14;
	string s = "Life is a highway!";

	void *void_ptr;

	cout << "Size of void_ptr: " << sizeof(void_ptr) << endl;

	void_ptr = &x;
	cout << "void_ptr: " << void_ptr << endl;
	cout << "casted as x: " << *(int *) void_ptr << endl;
	cout << "cpp style: " << *static_cast<int *>(void_ptr) << endl;

	void_ptr = &y;
	cout << "void_ptr: " << void_ptr << endl;
	cout << "casted as x: " << *(float *) void_ptr << endl;
	cout << "cpp style: " << *static_cast<float *>(void_ptr) << endl;

	void_ptr = &s;
	cout << "void_ptr: " << void_ptr << endl;
	cout << "casted as x: " << *(string *) void_ptr << endl;
	cout << "cpp style: " << *static_cast<string *>(void_ptr) << endl;
}
