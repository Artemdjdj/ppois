#include <gtest/gtest.h>
#include "settings.h"
#include <fstream>

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::ofstream file(PATH_TO_FILE, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " <<  PATH_TO_FILE<< std::endl;
        return 1;
    }
    file.close();
    return RUN_ALL_TESTS();
}
