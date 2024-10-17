/*
 * Logger Utils by Daniel Wiratman (2024)
 *
 * Usage:
 *
 * As a global variable, do this
 *
 * #include "logger.h"
 *
 * Logger &l = Logger::get():
 *
 * Done.. if you put this file in /usr/local/include/logger.h it can even be
 * included as #include <logger.h>
 *
 * I also create useful functions such as
 * - to_string_multi --> converts vector of things into string
 * - to_hex_multi --> converts vector of things into hex string
 *
 * */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Logger
{
  public:
	static Logger &
	get()
	{
		static Logger l;
		return l;
	}

	template<typename... Args>
	void
	INFO(const Args &...args)
	{
		log("INFO", concatenate_args(args...));
	}

	template<typename... Args>
	void
	DEBUG(const Args &...args)
	{
		log("DEBUG", concatenate_args(args...));
	}

	template<typename... Args>
	void
	WARNING(const Args &...args)
	{
		log("WARNING", concatenate_args(args...));
	}

	template<typename... Args>
	void
	ERROR(const Args &...args)
	{
		log("ERROR", concatenate_args(args...));
	}

	template<typename... Args>
	void
	FATAL(const Args &...args)
	{
		log("FATAL", concatenate_args(args...));
	}

	bool
	set_file(const string &filename)
	{
		logFile.open(filename, ios::app);
		if (!logFile.is_open())
		{
			cerr << "Error opening log file." << endl;
			return false;
		}
		return true;
	}

	// disabling copy constructor and copy assignment operator
	Logger(const Logger &) = delete;
	Logger &operator=(const Logger &) = delete;

  private:
	ofstream logFile;

	// setting constructor and destructor  as private so that it can't be called
	Logger() {}
	~Logger() { logFile.close(); }

	void
	log(string level, const string &message)
	{
		time_t now = time(0);
		tm *timeinfo = localtime(&now);
		char timestamp[20];
		strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

		ostringstream logEntry;
		logEntry << "[" << timestamp << "] " << level << ": " << message
				 << endl;

		cout << logEntry.str();

		if (logFile.is_open())
		{
			logFile << logEntry.str();
			logFile.flush();
		}
	}

	template<typename T>
	string
	concatenate_args(const T &value)
	{
		return my_to_string(value);
	}

	template<typename T, typename... Args>
	string
	concatenate_args(const T &first, const Args &...args)
	{
		return my_to_string(first) + " " + concatenate_args(args...);
	}

	template<typename T>
	string
	my_to_string(const T &value)
	{
		ostringstream s;
		s << value;
		return s.str();
	}

	template<typename T>
	string
	my_to_string(const vector<T> &value)
	{
		if (value.empty())
			return "[]";

		string result = "[";
		for (size_t i = 0; i < value.size(); ++i)
		{
			result += my_to_string(value[i]);
			if (i < value.size() - 1)
			{
				result += " ";
			}
		}
		result += "]";
		return result;
	}
};

template<typename T>
inline string
to_hex_multi(const vector<T> &bytes)
{
	const char hex_chars[] = "0123456789abcdef";
	string result;
	result.reserve(bytes.size() * 2);

	for (auto &b : bytes)
	{
		result.push_back(hex_chars[(b >> 4) & 0x0F]);
		result.push_back(hex_chars[b & 0x0F]);
	}
	return result;
}

template<typename T>
inline string
to_string_multi(const vector<T> &bytes)
{
	string result;
	for (auto &b : bytes)
	{
		result += to_string(b);
	}
	return result;
}
