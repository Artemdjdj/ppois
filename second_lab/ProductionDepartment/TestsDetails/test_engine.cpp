#include "../Engine/engine.h"
#include <gtest/gtest.h>

#include "../../Exceptions/exceptions.h"

class TestEngine : public ::testing::Test {
public:;
    Rim rim = Rim();
    Prong prong = Prong();
    IntakeManifold  intake_manifold = IntakeManifold();
    MetalChain metal_chain = MetalChain();
    Tube tube = Tube();
    WaterPump water_pump = WaterPump();
    Engine engine = Engine(false, 400000, rim, prong, intake_manifold, metal_chain,tube, water_pump);

};

TEST_F(TestEngine, TestGetInfoAboutPart) {
    EXPECT_EQ(engine.GetInfoAboutPart(), "This detail name is engine");
}

TEST_F(TestEngine, TestSetInfoRim) {
    engine.SetInfoAboutRim(11, 4, 4343);
}

TEST_F(TestEngine, TestSetInfoRimNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutRim(-11,4,4343),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, TestSetInfoProng) {
    engine.SetInfoAboutProng(1, 2, 3, 4, 4343);
}

TEST_F(TestEngine, TestSetInfoProngNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutProng(-11,2,3,4,4343),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, SetInfoAboutIntakeManifold) {
    engine.SetInfoAboutIntakeManifold(34, 45, 56, 7);
}

TEST_F(TestEngine, SetInfoAboutIntakeManifoldNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutIntakeManifold(34,45,-56,7),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, TestSetInfoAboutMetalChain) {
    engine.SetInfoAboutMetalChain(1, 2, 3, 4, 5, 8);
}

TEST_F(TestEngine, TestSetInfoAboutMetalChainNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutMetalChain(1,-2,3,4,5,8),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, TestSetInfoAboutPistons) {
    engine.SetInfoAboutPistons(1, 2, 3, 4, 5, 7);
}

TEST_F(TestEngine, TestSetInfoAboutPistonsNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutPistons(11,2,33,47,95,-8),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, TestSetInfoAboutPistonsNegativeCount) {
    engine.SetInfoAboutPistons(-11, 2, 33, 47, 95, 8);
}

TEST_F(TestEngine, TestSetInfoAboutValveSprings) {
    engine.SetInfoAboutValveSprings(1, 2, 3, 4);
}

TEST_F(TestEngine, TestSetInfoAboutValveSpringsNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutValveSprings(1,-2,33,47),
        ExceptionIncorrectSize
    );
}

TEST_F(TestEngine, TestSetInfoAboutValveSpringsNegativeCount) {
    engine.SetInfoAboutValveSprings(-11, 2, 33, 47);
}

TEST_F(TestEngine, TestSetInfoAboutTubeSprings) {
    engine.SetInfoAboutTube(1, 2);
}

TEST_F(TestEngine, TestSetInfoAboutTubeNegative) {
    ASSERT_THROW(
        engine.SetInfoAboutTube(1,-2),
        ExceptionIncorrectSize
    );
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
    ASSERT_THROW(
        engine.DriveTheWay(-10);,
        ExceptionWayError
    );
}

TEST_F(TestEngine, TestSetYearOfProducing) {
    engine.SetYearOfProducing(20);
    ASSERT_EQ(engine.GetYearOfProducing(), 20);
}

TEST_F(TestEngine, TestSetYearOfProducingIncorrect) {
    ASSERT_THROW(
        engine.SetYearOfProducing(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetMaxServiceLife) {
    engine.SetMaxServiceLife(2);
    ASSERT_EQ(engine.GetMaxServiceLife(), 2);
}

TEST_F(TestEngine, TestSetMaxServiceLifeIncorrect) {
    ASSERT_THROW(
        engine.SetMaxServiceLife(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetCountOfCylinders) {
    engine.SetCountOfCylinders(2);
    ASSERT_EQ(engine.GetCountOfCylinders(), 2);
}

TEST_F(TestEngine, TestSetCountOfCylindersIncorrect1) {
    ASSERT_THROW(
        engine.SetCountOfCylinders(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetCountOfCylindersIncorrect2) {
    ASSERT_THROW(
        engine.SetCountOfCylinders(20),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetGuarantee) {
    engine.SetGuarantee(2);
    ASSERT_EQ(engine.GetGuarantee(), 2);
}

TEST_F(TestEngine, TestSetGuaranteeIncorrect) {
    ASSERT_THROW(
        engine.SetGuarantee(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetMaxPower) {
    engine.SetMaxPower(2);
    ASSERT_EQ(engine.GetMaxPower(), 2);
}

TEST_F(TestEngine, TestSetMaxPowerIncorrect) {
    ASSERT_THROW(
        engine.SetMaxPower(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetTorque) {
    engine.SetTorque(2);
    ASSERT_EQ(engine.GetTorque(), 2);
}

TEST_F(TestEngine, TestSetTorqueIncorrect) {
    ASSERT_THROW(
        engine.SetTorque(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetWorkCycle) {
    engine.SetWorkCycle(2);
    ASSERT_EQ(engine.GetWorkCycle(), 2);
}

TEST_F(TestEngine, TestSetWorkCycle2) {
    engine.SetWorkCycle(4);
    ASSERT_EQ(engine.GetWorkCycle(), 4);
}

TEST_F(TestEngine, TestSetWorkCycleIncorrect) {
    ASSERT_THROW(
        engine.SetWorkCycle(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetWeightCycle) {
    engine.SetWeight(2);
    ASSERT_EQ(engine.GetWeight(), 2);
}

TEST_F(TestEngine, TestSetWeightIncorrect) {
    ASSERT_THROW(
        engine.SetWeight(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetFuelConsumption) {
    engine.SetFuelConsumption(2);
    ASSERT_EQ(engine.GetFuelConsumption(), 2);
}

TEST_F(TestEngine, TestSetFuelConsumptionIncorrect) {
    ASSERT_THROW(
        engine.SetFuelConsumption(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetRotationSpeed) {
    engine.SetRotationSpeed(2);
    ASSERT_EQ(engine.GetRotationSpeed(), 2);
}

TEST_F(TestEngine, TestSetRotationSpeedIncorrect) {
    ASSERT_THROW(
        engine.SetRotationSpeed(-1),
        ExceptionRuntimeError
    );
}

TEST_F(TestEngine, TestSetCountry) {
    engine.SetCountry("Belarus");
    ASSERT_EQ(engine.GetCountry(), "Belarus");
}

TEST_F(TestEngine, TestSetCity) {
    engine.SetCity("Borisov");
    ASSERT_EQ(engine.GetCity(), "Borisov");
}

TEST_F(TestEngine, TestSetInformation) {
    engine.SetInformation("Information");
    ASSERT_EQ(engine.GetInformation(), "Information");
}
