#include <gtest/gtest.h>
#include "GildedRose.h"

std::string aged_brie{"Aged Brie"};
std::string backstage_pass{"Backstage passes to a TAFKAL80ETC concert"};
std::string sulfuras{"Sulfuras, Hand of Ragnaros"};

TEST(GildedRoseTest, MultipleItems)
{
    std::vector<Item> items;
    items.push_back(Item("A", 1, 10));
    items.push_back(Item("B", -1, 10));
    items.push_back(Item("C", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].sellIn);
    EXPECT_EQ(9, app.items[0].quality);
    EXPECT_EQ(-2, app.items[1].sellIn);
    EXPECT_EQ(8, app.items[1].quality);
    EXPECT_EQ(-1, app.items[2].sellIn);
    EXPECT_EQ(8, app.items[2].quality);
}

TEST(GildedRoseTest, TwoUpdates)
{
    std::vector<Item> items;
    items.push_back(Item("Foo", 5, 10));

    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(4,app.items[0].sellIn);
    EXPECT_EQ(9,app.items[0].quality);
    
    app.updateQuality();
    EXPECT_EQ(3,app.items[0].sellIn);
    EXPECT_EQ(8,app.items[0].quality);
}