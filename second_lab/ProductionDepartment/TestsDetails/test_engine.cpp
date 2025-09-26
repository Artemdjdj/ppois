#include "../Engine/engine.h"
#include <gtest/gtest.h>

class TestEngine : public ::testing::Test {
public:
	Engine engine = Engine(false, 400000);
};

TEST_F(TestEngine, TestGetInfoAboutPart) {
	EXPECT_EQ(engine.GetInfoAboutPart(), "This detail name is engine");
}

TEST_F(TestEngine, TestSetInfoRim) {
	ASSERT_TRUE(engine.SetInfoAboutRim(11,4,4343));
}

TEST_F(TestEngine, TestSetInfoRimNegative) {
	ASSERT_FALSE(engine.SetInfoAboutRim(-11,4,4343));
}

TEST_F(TestEngine, TestSetInfoProng) {
	ASSERT_TRUE(engine.SetInfoAboutProng(1,2,3,4,4343));
}

TEST_F(TestEngine, TestSetInfoProngNegative) {
	ASSERT_FALSE(engine.SetInfoAboutProng(-11,2,3,4,4343));
}

TEST_F(TestEngine, SetInfoAboutIntakeManifold) {
	ASSERT_TRUE(engine.SetInfoAboutIntakeManifold(34,45,56,7));
}

TEST_F(TestEngine, SetInfoAboutIntakeManifoldNegative) {
	ASSERT_FALSE(engine.SetInfoAboutIntakeManifold(34,45,-56,7));
}

TEST_F(TestEngine, TestSetInfoAboutMetalChain) {
	ASSERT_TRUE(engine.SetInfoAboutMetalChain(1,2,3,4,5,8));
}

TEST_F(TestEngine, TestSetInfoAboutMetalChainNegative) {
	ASSERT_FALSE(engine.SetInfoAboutMetalChain(1,-2,3,4,5,8));
}

TEST_F(TestEngine, TestSetInfoAboutPistons) {
	ASSERT_TRUE(engine.SetInfoAboutPistons(1,2,3,4,5,7));
}

TEST_F(TestEngine, TestSetInfoAboutPistonsNegative) {
	ASSERT_FALSE(engine.SetInfoAboutPistons(11,2,33,47,95,-8));
}

TEST_F(TestEngine, TestSetInfoAboutPistonsNegativeCount) {
	ASSERT_FALSE(engine.SetInfoAboutPistons(-11,2,33,47,95,8));
}

TEST_F(TestEngine, TestSetInfoAboutValveSprings) {
	ASSERT_TRUE(engine.SetInfoAboutValveSprings(1,2,3,4));
}

TEST_F(TestEngine, TestSetInfoAboutValveSpringsNegative) {
	ASSERT_FALSE(engine.SetInfoAboutValveSprings(1,-2,33,47));
}

TEST_F(TestEngine, TestSetInfoAboutValveSpringsNegativeCount) {
	ASSERT_FALSE(engine.SetInfoAboutValveSprings(-11,2,33,47));
}

TEST_F(TestEngine, TestSetInfoAboutTubeSprings) {
	ASSERT_TRUE(engine.SetInfoAboutTube(1,2));
}

TEST_F(TestEngine, TestSetInfoAboutTubeNegative) {
	ASSERT_FALSE(engine.SetInfoAboutTube(1,-2));
}

TEST_F(TestEngine, TestStartEngine) {
	engine.StartEngine();
	ASSERT_TRUE(engine.CheckIsEngineWorking());
}

TEST_F(TestEngine, TestStopEngine) {
	engine.StopEngine();
	ASSERT_FALSE(engine.CheckIsEngineWorking());
}

TEST_F(TestEngine, TestGetInfoAboutRim) {
	ASSERT_EQ(engine.GetInfoAboutRim(), "This detail name is rim");
}

TEST_F(TestEngine, TestGetInfoAboutProng) {
	ASSERT_EQ(engine.GetInfoAboutProng(), "This detail name is prong");
}

TEST_F(TestEngine, TestGetInfoAboutIntakeManifold) {
	ASSERT_EQ(engine.GetInfoAboutIntakeManifold(), "This detail name is intake manifold");
}

TEST_F(TestEngine, TestGetInfoAboutMetalChain) {
	ASSERT_EQ(engine.GetInfoAboutMetalChain(), "This detail name is metal chain and the length is 0");
}

TEST_F(TestEngine, TestGetInfoAboutPistons) {
	engine.SetInfoAboutPistons(11, 2, 33, 47, 95, 8);
	ASSERT_EQ(engine.GetInfoAboutPistons(), "This detail name is piston The count of pistons - 11");
}

TEST_F(TestEngine, TestGetInfoAboutPistonsEmpty) {
	ASSERT_EQ(engine.GetInfoAboutPistons(), "No any pistons in engine!");
}

TEST_F(TestEngine, TestGetInfoAboutValveSprings) {
	engine.SetInfoAboutValveSprings(1, 2, 33, 47);
	ASSERT_EQ(engine.GetInfoAboutValveSprings(), "This detail name is valve spring The count of valve springs - 1");
}

TEST_F(TestEngine, TestGetInfoAboutValveSpringsEmpty) {
	ASSERT_EQ(engine.GetInfoAboutValveSprings(), "No any valve springs!");
}

TEST_F(TestEngine, TestGetInfoAboutTube) {
	ASSERT_EQ(engine.GetInfoAboutTube(), "This detail name is tube");
}

TEST_F(TestEngine, TestGetInfoAboutWaterPump) {
	ASSERT_EQ(engine.GetInfoAboutWaterPump(), "This detail name is water pump");
}

TEST_F(TestEngine, TestCheckIsEngineShouldBeServed) {
	ASSERT_EQ(engine.CheckIsEngineShouldBeServed(), "You shouldn't undergo maintenance!");
}

TEST_F(TestEngine, TestGetInfoAboutEngineLife) {
	ASSERT_EQ(engine.GetInfoAboutEngineLife(), 400000);
}

TEST_F(TestEngine, TestDriveTheWay) {
	engine.DriveTheWay(500);
	ASSERT_EQ(engine.GetInfoAboutCurrentMileage(), 500);
	engine.DriveTheWay(600);
	ASSERT_EQ(engine.GetInfoAboutCurrentMileage(), 1100);
}

TEST_F(TestEngine, TestDriveTheWayNegative) {
	engine.DriveTheWay(-10);
	ASSERT_EQ(engine.GetInfoAboutCurrentMileage(), 0);
}
