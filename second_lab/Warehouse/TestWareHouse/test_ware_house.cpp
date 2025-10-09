#include <gtest/gtest.h>
#include "../ware_house.h"
#include <iostream>
#include <string>
#include <cmath>
#include "../../ProductionDepartment/CarBody/gas_tank.h"
#include "src/gtest-internal-inl.h"

class TestWareHouse : public ::testing::Test {
public:
	void SetUp() override {
		ware_house = WareHouse();
	}

	WareHouse ware_house;
};


TEST_F(TestWareHouse, TestDeleteById) {
	CarPart *detail = new GasTank();
	std::string my_id;
	ware_house.AddNewDetail(detail, my_id);
	ASSERT_TRUE(ware_house.DeleteDetailById(my_id));
	delete detail;
}

TEST_F(TestWareHouse, TestDeleteByIdFalse) {
	CarPart *detail = new GasTank();
	std::string my_id;
	ware_house.AddNewDetail(detail, my_id);
	ASSERT_FALSE(ware_house.DeleteDetailById("something incorrect"));
	delete detail;
}

TEST_F(TestWareHouse, TestFindByIdFalse) {
	CarPart *detail2 = new GasTank();
	ASSERT_FALSE(ware_house.FindDetailById("something incorrect", detail2));
	delete detail2;
}


TEST_F(TestWareHouse, TestFindById) {
	CarPart *detail2 = new GasTank();
	std::string my_id;
	ware_house.AddNewDetail(detail2, my_id);
	ASSERT_TRUE(ware_house.FindDetailById(my_id, detail2));
	delete detail2;
}

TEST_F(TestWareHouse, TestCheckTypeCarPart) {
	CarPart *detail = new GasTank();
	CarPart *detail2;
	std::string my_id;
	ware_house.AddNewDetail(detail, my_id);
	ware_house.FindDetailById(my_id, detail2);
	ASSERT_EQ(detail2->GetInfoAboutPart(), "This detail name is gas tank");
	delete detail;
}
