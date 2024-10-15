#include "logger.h"

Logger &l = Logger::get();

int
main()
{
	vector<unsigned char> byteVec;

	for (int i = 0; i < 10; i++)
		byteVec.push_back('A');

	l.INFO("Hello World!", byteVec);
}
