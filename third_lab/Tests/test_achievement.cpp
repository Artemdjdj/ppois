#include <gtest/gtest.h>
#include "../SocialMedia/achievement.h"

class TestAchievement : public ::testing::Test {
public:
    void SetUp() override {
        achievement2.AddCondition("Have skill in football");
    }

    Achievement achievement1 = Achievement();
    Achievement achievement2 = Achievement("football", "some info", "gold medal", "Soligorsk");
};

TEST_F(TestAchievement, TestSetName) {
    achievement1.SetName("something");
    ASSERT_EQ("something", achievement1.GetName());
}

TEST_F(TestAchievement, TestSetNameIncorrect) {
    ASSERT_THROW(
        achievement1.SetName(""),
        std::invalid_argument
    );
}

TEST_F(TestAchievement, TestSetInfo) {
    achievement1.SetInfo("something interesting");
    ASSERT_EQ("something interesting", achievement1.GetInfo());
}

TEST_F(TestAchievement, TestSetInfoIncorrect) {
    ASSERT_THROW(
        achievement1.SetInfo(""),
        std::invalid_argument
    );
}

TEST_F(TestAchievement, TestAddCondition) {
    achievement2.AddCondition("Live in Soligorsk");
    ASSERT_EQ((std::vector<std::string>{"Have skill in football","Live in Soligorsk"}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestAddConditionIncorrect) {
    ASSERT_THROW(
        achievement2.AddCondition(""),
        std::invalid_argument
    );
    ASSERT_EQ((std::vector<std::string>{"Have skill in football"}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestDeleteCondition) {
    achievement2.DeleteCondition(0);
    ASSERT_EQ((std::vector<std::string>{}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestDeleteConditionIncorrect) {
    ASSERT_THROW(
        achievement2.DeleteCondition(-19),
        ExceptionIncorrectNumber
    );
    ASSERT_EQ((std::vector<std::string>{"Have skill in football"}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestRefactorCondition) {
    achievement2.RefactorCondition("Have skill in hockey", 0);
    ASSERT_EQ((std::vector<std::string>{"Have skill in hockey"}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestRefactorConditionIncorrect) {
    ASSERT_THROW(
        achievement2.RefactorCondition("Have skill in hockey", -11),
        ExceptionIncorrectNumber
    );
    ASSERT_EQ((std::vector<std::string>{"Have skill in football"}), achievement2.GetConditions());
}

TEST_F(TestAchievement, TestSetReward) {
    achievement1.SetReward("gold medal");
    ASSERT_EQ("gold medal", achievement1.GetReward());
}

TEST_F(TestAchievement, TestSetRewardIncorrect) {
    ASSERT_THROW(
        achievement1.SetReward(""),
        std::invalid_argument
    );
}

TEST_F(TestAchievement, TestSetCity) {
    achievement1.SetReward("Moscow");
    ASSERT_EQ("Moscow", achievement1.GetReward());
}

TEST_F(TestAchievement, TestSetCityIncorrect) {
    ASSERT_THROW(
        achievement1.SetCity(""),
        std::invalid_argument
    );
}
