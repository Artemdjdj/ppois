#include "../Engine/metal_links.h"
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
    plata.SetPlataSize(10, 11);
    ASSERT_EQ(plata.GetHeightOfPlata(), 10);
    ASSERT_EQ(plata.GetWidthOfPlata(), 11);
}

TEST_F(TestAllInMetalChain, TestGetStringPlata) {
    ASSERT_EQ(plata.GetMaterial(), "steel");
}

TEST_F(TestAllInMetalChain, TestSetWeightMetalCylinder) {
    ASSERT_EQ(cylinder.GetWeight(), 0);
    cylinder.SetWeight(10);
    ASSERT_EQ(cylinder.GetWeight(), 10);
}

TEST_F(TestAllInMetalChain, TestSetDataForTwoPlats) {
    metal_link.SetDataForTwoPlats(45, 77);
    ASSERT_EQ(metal_link.GetHeightOfPlataForUser(), 45);
    ASSERT_EQ(metal_link.GetWidthOfPlataForUser(), 77);
}

TEST_F(TestAllInMetalChain, TestSetDataForTwoPlatsNegative) {
    metal_link.SetDataForTwoPlats(-45, 77);
    ASSERT_EQ(metal_link.GetHeightOfPlataForUser(), 0);
    ASSERT_EQ(metal_link.GetWidthOfPlataForUser(), 0);
}

TEST_F(TestAllInMetalChain, TestMetalChain) {
    metal_link.SetDataForTwoPlats(45, 77);
    ASSERT_EQ(metal_chain.GetLensOfMetalChain(), 0);
    metal_chain.AddNewMetalLink(metal_link);
    ASSERT_EQ(metal_chain.GetLensOfMetalChain(), 1);
    metal_chain.DeleteMetalLink();
    metal_chain.DeleteMetalLink();
    ASSERT_EQ(metal_chain.GetLensOfMetalChain(), 0);
}



