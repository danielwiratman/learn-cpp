#include "sign.h"
#include "utils.h"
#include "verify.h"
#include "gen.h"
#include "logger.h"

#include <string>

using namespace std;

int
main(int args, char **argv)
{
	Logger &l = Logger::get();

	string mode;

	if (args > 1)
		mode = argv[1];

	if (mode == "gen")
	{
		l.INFO("generate key mode, should produce 2 files (key.pub and key)");

		run_generate_key("ec");
		// run_generate_key("rsa");
	}
	else if (mode == "sign")
	{
		l.INFO("signing mode, requires 2 files (data.csv, key)");

		if (!check_files("data.csv", "key"))
		{
			l.FATAL("check_files");
		}

		run_sign();
	}
	else if (mode == "verify")
	{
		l.INFO("verify mode, requires 3 files (data.csv, key.pub, signature)");

		if (!check_files("data.csv", "key.pub", "signature"))
		{
			l.FATAL("check_files");
		}

		run_verify();
	}
	else if (mode == "clean")
	{
		l.INFO("clean mode, should remove all files");
		clean_files("key.pub", "key", "signature");
	}
	else
	{
		printf("Usage: %s [gen|sign|verify|clean]\n"
			   "\n"
			   "gen: generate key (key and key.pub)\n"
			   "sign: sign data (using key to sign data.csv producing "
			   "signature)\n"
			   "verify: verify signature (using key.pub and signature to "
			   "verify data.csv\n"
			   "clean: clean all generated files (key.pub, key, signature)\n",
			   argv[0]);
	}
}
