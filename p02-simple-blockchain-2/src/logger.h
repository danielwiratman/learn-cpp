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

	template<typename T>
	void
	DEBUG(const T &message)
	{
		log("DEBUG", message);
	}

	template<typename T>
	void
	INFO(const T &message)
	{
		log("INFO", message);
	}

	template<typename T>
	void
	WARNING(const T &message)
	{
		log("WARNING", message);
	}

	template<typename T>
	void
	ERROR(const T &message)
	{
		log("ERROR", message);
	}

	template<typename T>
	void
	FATAL(const T &message)
	{
		log("FATAL", message);
		exit(1);
	}

	Logger(const Logger &) = delete;
	Logger &operator=(const Logger &) = delete;

	template<typename T>
	static string
	to_hex(const T &bytes)
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

  private:
	ofstream logFile;

	Logger() {}

	~Logger() { logFile.close(); }

	template<typename T>
	void
	log(string level, const T &message)
	{
		time_t now = time(0);
		tm *timeinfo = localtime(&now);
		char timestamp[20];
		strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

		ostringstream logEntry;
		logEntry << "[" << timestamp << "] " << level << ": "
				 << my_to_string(message) << endl;

		cout << logEntry.str();

		if (logFile.is_open())
		{
			logFile << logEntry.str();
			logFile.flush();
		}
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
