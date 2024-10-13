#pragma once

#include <iostream>

using namespace std;

inline void
print_story()
{
	cout << "=== STORY ===" << endl
		 << "There are 3 people, Alice, Bob and Charlie." << endl
		 << endl
		 << "All create a wallet account, and deposit 5 DC coins" << endl
		 << "Alice pays Bob 0.5 DC coins" << endl
		 << "Charlie pays Bob 1.5 DC coins" << endl
		 << "Bob pays Alice 0.1 DC coins" << endl
		 << endl
		 << "At the end..." << endl
		 << "Alice should have 4.6 DC coins" << endl
		 << "Bob should have 6.9 DC coins" << endl
		 << "Charlie should have 3.5 DC coins" << endl
		 << "=== END ===" << endl
		 << endl;
}

inline void
empty_line()
{
	cout << endl;
}
