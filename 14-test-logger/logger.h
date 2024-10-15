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
		string result;
		result.reserve(value.size());
		for (const auto &b : value)
		{
			result.push_back(static_cast<char>(b));
		}
		return result;
	}
};
