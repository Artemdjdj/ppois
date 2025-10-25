#include <gtest/gtest.h>
#include "../Utils/project_utils.h"
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	DefaultLogger::ClearFile(kMainLogFile);
	return RUN_ALL_TESTS();
}
