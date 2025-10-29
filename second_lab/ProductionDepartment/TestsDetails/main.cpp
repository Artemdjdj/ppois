#include <gtest/gtest.h>
#include "settings.h"
#include "../Include/basic_params.h"
#include <fstream>

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	const int result = CarLogger::CheckFileLog(PATH_TO_FILE);
	return (result == 0) ? RUN_ALL_TESTS() : result;
}
