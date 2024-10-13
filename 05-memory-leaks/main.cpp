#define forever for (;;)

class Hello
{
	int x;
};

int
main()
{
	forever
	{
		Hello *h = new Hello;
		delete h;
	}
}
