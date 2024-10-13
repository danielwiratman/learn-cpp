#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

inline bool
check_files()
{
	return true;
}

template<typename T, typename... Args>
bool
check_files(T filename, Args... filenames)
{
	ifstream file = ifstream(filename);
	if (!file.good())
	{
		return false;
	}
	return check_files(filenames...);
}

inline void
clean_files()
{
}

template<typename T, typename... Args>
void
clean_files(T filename, Args... filenames)
{
	remove(filename);
	clean_files(filenames...);
}

inline vector<byte>
read_file(string filename)
{
	ifstream file(filename, ios::binary);
	if (!file.is_open())
		throw runtime_error("cannot open file");

	file.seekg(0, ios::end);
	size_t size = file.tellg();
	file.seekg(0, ios::beg);

	vector<byte> data(size);
	file.read((char *) data.data(), size);

	return data;
}
