#pragma once

#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {
    }
};

class GildedRose
{
public:
    std::vector<Item> &items;
    GildedRose(std::vector<Item> &items);

    void updateQuality();

    void updateQualityItem(Item &) const;

    std::string const aged_brie{"Aged Brie"};
    std::string const backstage_pass{"Backstage passes to a TAFKAL80ETC concert"};
    std::string const sulfuras{"Sulfuras, Hand of Ragnaros"};
};
