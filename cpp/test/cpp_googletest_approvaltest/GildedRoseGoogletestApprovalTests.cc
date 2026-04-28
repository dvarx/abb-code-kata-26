#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>
#include <limits>

#include "GildedRose.h"

std::string aged_brie{"Aged Brie"};
std::string backstage_pass{"Backstage passes to a TAFKAL80ETC concert"};
std::string sulfuras{"Sulfuras, Hand of Ragnaros"};

std::ostream &operator<<(std::ostream &os, const Item &obj)
{
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn
              << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyCombinationsRegular)
{
    std::vector<std::string> names{"Foo", aged_brie, backstage_pass, sulfuras};
    std::vector<int> sellIns{-15, -10, -5, -1, 0, 1, 4, 5, 6, 9, 10, 11, 15};
    std::vector<int> qualities{0, 1, 5, 50, 80, 150};

    auto f = [](std::string name, int sellIn, int quality)
    {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns,
                                                               qualities);
}