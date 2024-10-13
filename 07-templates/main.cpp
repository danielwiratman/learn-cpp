#include <iostream>

using namespace std;

template<typename T>
T *
add_prefix(T value)
{
	T *value_copy = new T;
	*value_copy = value;
	return value_copy;
}

int
main()
{
	string *str_ptr = add_prefix<string>("Hello");
	cout << "Value: " << *str_ptr << endl;
	delete str_ptr;

	float *double_ptr = add_prefix<float>(3.14);
	cout << "Value: " << *double_ptr << endl;
	delete double_ptr;

	bool *bool_ptr = add_prefix(true);
	cout << "Value: " << *bool_ptr << endl;
	delete bool_ptr;

	long *int_ptr = add_prefix(92014812490812903);
	cout << "Value: " << *int_ptr << endl;
	delete int_ptr;
}
