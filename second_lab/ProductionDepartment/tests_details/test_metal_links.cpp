#include "include_metal_links.h"
#include <gtest/gtest.h>

class TestAllInMetalChain: public ::testing::Test {
public:
    // TestAllInMetalChain() : plata() {}
    void SetUp() override {
        plata = Plata();
        cylinder = MetalCylinder();
        metal_link = MetalLink();
        metal_chain = MetalChain();
    }
    Plata plata;
    MetalCylinder cylinder;
    MetalLink metal_link;
    MetalChain metal_chain;
};

TEST_F(TestAllInMetalChain, TestSetSizePlata) {
    plata.set_plata_size(10, 11);
    ASSERT_EQ(plata.get_height_of_plata(), 10);
    ASSERT_EQ(plata.get_width_of_plata(), 11);
}

TEST_F(TestAllInMetalChain, TestGetStringPlata) {
    ASSERT_EQ(plata.get_material(), "steel");
}

TEST_F(TestAllInMetalChain, TestSetWeightMetalCylinder) {
    ASSERT_EQ(cylinder.get_weight(), 0);
    cylinder.set_weight(10);
    ASSERT_EQ(cylinder.get_weight(), 10);
}

TEST_F(TestAllInMetalChain, TestSetDataForTwoPlats) {
    metal_link.set_data_for_two_plats(45, 77);
    ASSERT_EQ(metal_link.get_height_of_plata_for_user(), 45);
    ASSERT_EQ(metal_link.get_width_of_plata_for_user(), 77);
}

TEST_F(TestAllInMetalChain, TestSetDataForTwoPlatsNegative) {
    metal_link.set_data_for_two_plats(-45, 77);
    ASSERT_EQ(metal_link.get_height_of_plata_for_user(), 0);
    ASSERT_EQ(metal_link.get_width_of_plata_for_user(), 0);
}

TEST_F(TestAllInMetalChain, TestMetalChain) {
    metal_link.set_data_for_two_plats(45, 77);
    ASSERT_EQ(metal_chain.get_lens_of_metal_chain(), 0);
    metal_chain.add_new_metal_link(metal_link);
    ASSERT_EQ(metal_chain.get_lens_of_metal_chain(), 1);
    metal_chain.delete_metal_link();
    metal_chain.delete_metal_link();
    ASSERT_EQ(metal_chain.get_lens_of_metal_chain(), 0);
}



