#include "GildedRose.h"

using namespace std;

GildedRose::GildedRose(vector<Item> &items) : items(items)
{
}

void GildedRose::updateQualityItem(Item &item) const
{
    if (item.name == sulfuras)
    {
        return;
    }

    // update the quality of the item
    if (item.name == aged_brie)
    {
        item.increment_quality();
    }
    else if (item.name == backstage_pass)
    {
        item.increment_quality();
        if (item.sellIn < 11)
        {
            item.increment_quality();
        }

        if (item.sellIn < 6)
        {
            item.increment_quality();
        }
    }
    else
    {
        item.decrement_quality();
    }

    // update the sellIn of the item
    item.sellIn = item.sellIn - 1;

    if (item.sellIn < 0)
    {
        if (item.name == aged_brie)
        {
            item.increment_quality();
        }
        else if (item.name == backstage_pass)
        {
            item.quality = 0;
        }
        else
        {
            item.decrement_quality();
        }
    }
}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        updateQualityItem(item);
    }
}
