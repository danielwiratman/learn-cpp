#include <functional>
#include <iostream>
using namespace std;
int
main()
{
	/* ALL 3 are valid options, though auto more commonly used */

	// auto greet = [](string name) { cout << "Hello " << name << "!" << endl;
	// };

	// function greet = [](string name) {
	// 	cout << "Hello " << name << "!" << endl;
	// };

	function<void(string)> greet = [](string name) {
		cout << "Hello " << name << "!" << endl;
	};

	string s = "Daniel";
	greet(s);

	s[2] = 'b';
	greet(s);
}
