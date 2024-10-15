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
		return l;
	}

	template<typename T, typename... Args>
	void
	logBase(const string &level, const T &first, const Args &...args)
	{
		logBase(level, my_to_string(first) + " " + my_to_string(args...));
	}

	template<typename... Args>
	void
	INFO(const Args &...args)
	{
		logBase("INFO", args...);
	}

	template<typename... Args>
	void
	DEBUG(const Args &...args)
	{
		logBase("DEBUG", args...);
	}

	template<typename... Args>
	void
	WARNING(const Args &...args)
	{
		logBase("WARNING", args...);
	}

	template<typename... Args>
	void
	ERROR(const Args &...args)
	{
		logBase("ERROR", args...);
	}

	template<typename... Args>
	void
	FATAL(const Args &...args)
	{
		logBase("FATAL", args...);
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
	static Logger l;

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

	void
	logBase(const string &level, const string &message)
	{
		log(level, message);
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
		string result;
		result.reserve(value.size());
		for (const auto &b : value)
		{
			result.push_back(static_cast<char>(b));
		}
		return result;
	}
};
