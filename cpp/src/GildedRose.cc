#include "GildedRose.h"

using namespace std;

GildedRose::GildedRose(vector<Item> &items) : items(items)
{
}

void GildedRose::updateQualityItem(Item &item) const
{
    if (item.name != aged_brie && item.name != backstage_pass)
    {
        if (item.quality > 0)
        {
            if (item.name != sulfuras)
            {
                item.quality = item.quality - 1;
            }
        }
    }
    else
    {
        if (item.quality < 50)
        {
            item.quality = item.quality + 1;

            if (item.name == backstage_pass)
            {
                if (item.sellIn < 11)
                {
                    if (item.quality < 50)
                    {
                        item.quality = item.quality + 1;
                    }
                }

                if (item.sellIn < 6)
                {
                    if (item.quality < 50)
                    {
                        item.quality = item.quality + 1;
                    }
                }
            }
        }
    }

    if (item.name != sulfuras)
    {
        item.sellIn = item.sellIn - 1;
    }

    if (item.sellIn < 0)
    {
        if (item.name != aged_brie)
        {
            if (item.name != backstage_pass)
            {
                if (item.quality > 0)
                {
                    if (item.name != sulfuras)
                    {
                        item.quality = item.quality - 1;
                    }
                }
            }
            else
            {
                item.quality = item.quality - item.quality;
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;
            }
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
