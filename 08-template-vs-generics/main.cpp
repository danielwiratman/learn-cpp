#include <iostream>
#include <string>

using namespace std;

template<typename T, int N> class MyArray
{
	T arr[N];

  public:
	int
	get_size()
	{
		return N;
	};

	// subscript opereator
	T &
	operator[](int index)
	{
		return arr[index];
	};
};

int
main()
{
	MyArray<string, 10> my_str_array;

	for (int i = 0; i < my_str_array.get_size(); i++)
	{
		my_str_array[i] = "Hello Number " + to_string(i + 1);
	}

	for (int i = 0; i < my_str_array.get_size(); i++)
	{
		cout << "my_str_array[" << i << "]: " << my_str_array[i] << endl;
	}
}
