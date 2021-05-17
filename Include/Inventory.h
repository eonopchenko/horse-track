/*******************************************************************************
FILE : Inventory.h
DESCRIPTION :
This file is Inventory class declaration. This class is responsible 
for inventory processing (bill dispensing and restocking)
==============================================================================*/

#include <map>

class Inventory {
public:
    void Restock();
    bool Dispense(unsigned payout);
    void Display();

    Inventory();

private:
    std::map<unsigned, unsigned> inventory_map;
    unsigned total = 0;

    const std::map<unsigned, unsigned> default_inventory_map = 
    {
        {1, 10},
        {5, 10},
        {10, 10},
        {20, 10},
        {100, 10}
    };

    const std::map<unsigned, unsigned> default_dispense_map = 
    {
        {1, 0},
        {5, 0},
        {10, 0},
        {20, 0},
        {100, 0}
    };
};
