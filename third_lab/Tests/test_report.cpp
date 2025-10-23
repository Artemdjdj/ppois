#include <gtest/gtest.h>
#include "exceptions.h"
#include "../SocialMedia/report.h"

class TestReport : public ::testing::Test {
public:
    std::shared_ptr<User>author1 = std::make_shared<User>("@Artemdjdj", "gsgg5093495");
    std::shared_ptr<User>author2 = std::make_shared<User>("@Artemdjdj35", "5093445hdskfhsk");
    std::string user1 = author1->GetUsername();
    std::string user2 = author2->GetUsername();
    Report report  = Report(user1, user2);
};

TEST_F(TestReport, TestSetCause) {
    report.SetCause("Bad words", user1);
    ASSERT_EQ("Bad words", report.GetCause());
}

TEST_F(TestReport, TestSetCauseIncorrectAuthor) {
    ASSERT_THROW(
        report.SetCause("Bad words", user2),
        ExceptionAccess
    );
}

TEST_F(TestReport, TestSetCauseIncorrectArgument) {
    ASSERT_THROW(
        report.SetCause("", user1),
        std::invalid_argument
    );
}

TEST_F(TestReport, TestSetProof) {
    report.SetProof("some info", user1);
    ASSERT_EQ("some info", report.GetProof());
}

TEST_F(TestReport, TestSetProofIncorrectAuthor) {
    ASSERT_THROW(
        report.SetProof("Bad words", user2),
        ExceptionAccess
    );
}

TEST_F(TestReport, TestSetProofIncorrectArgument) {
    ASSERT_THROW(
        report.SetProof("", user1),
        std::invalid_argument
    );
}

TEST_F(TestReport, TestApprove) {
    report.Approve();
    ASSERT_TRUE(report.IsApproved());
}

TEST_F(TestReport, TestDisapprove) {
    report.Disapprove();
    ASSERT_FALSE(report.IsApproved());
}

TEST_F(TestReport, TestGetSender) {
    ASSERT_EQ(user1,report.GetSender());
}

TEST_F(TestReport, TestGetBadUser) {
    ASSERT_EQ(user2,report.GetBadUser());
}
