#include <gtest/gtest.h>
#include <fstream>
#include "../../GeneratorId/generator_id.h"
#include "project_settings.h"

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	const int result = CheckFileLog(NAME_OF_FILE_LOGS_GENERATE_ID);
	return (result == 0) ? RUN_ALL_TESTS() : result;
}
