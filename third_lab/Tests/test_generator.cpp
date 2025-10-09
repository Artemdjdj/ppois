#include <cmath>
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "../Generator/generator.h"

class TestGeneratorId : public ::testing::Test {
public:
	void SetUp() override {
		generated_id = GeneratorId();
	}

	GeneratorId generated_id;
};

TEST_F(TestGeneratorId, TestGeneratorId) {
	std::string id;
	ASSERT_TRUE(generated_id.GenerateNewId(id));
}

TEST_F(TestGeneratorId, TestGeneratorCheckIdTrue) {
	std::string id;
	generated_id.GenerateNewId(id);
	ASSERT_TRUE(generated_id.CheckIdIsTaken(id));
}

TEST_F(TestGeneratorId, TestGeneratorCheckIdFalse) {
	std::string id;
	generated_id.GenerateNewId(id);
	ASSERT_FALSE(generated_id.CheckIdIsTaken("something"));
}

TEST_F(TestGeneratorId, TestGeneratorDeleteIdTrue) {
	std::string id;
	generated_id.GenerateNewId(id);
	ASSERT_TRUE(generated_id.DeleteId(id));
}

TEST_F(TestGeneratorId, TestGeneratorDeleteIdFalse) {
	std::string id;
	generated_id.GenerateNewId(id);
	ASSERT_FALSE(generated_id.DeleteId("something"));
}