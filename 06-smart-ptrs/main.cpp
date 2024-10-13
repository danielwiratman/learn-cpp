#include <iostream>
#include <memory>

using namespace std;

class Rect
{
	int length;
	int width;

  public:
	Rect(int l, int w)
	{
		length = l;
		width = w;
	}

	int
	get_area()
	{
		return length * width;
	}
};

int
main()
{
	while (1)
	{
		// without smart pointers
		Rect *r = new Rect(10, 20);
		cout << (*r).get_area() << endl;
		delete r;

		// unique_ptr
		unique_ptr<Rect> r1 = make_unique<Rect>(10, 25);
		// (*r1).get_area and r1->get_area() are the same
		cout << r1->get_area() << endl;

		// errors
		// unique_ptr<Rect> r2 = r1;

		// shared_ptr
		shared_ptr<Rect> r3 = make_shared<Rect>(15, 25);
		cout << r3->get_area() << endl;
		shared_ptr<Rect> r4 = r3;
		cout << r4->get_area() << endl;
		shared_ptr<Rect> r5 = r4;
		cout << r5->get_area() << endl;
		cout << r5.use_count() << endl;
	}

	return 0;
}
