/*******************************************************************************
FILE : Inventory.cpp
DESCRIPTION :
This file Inventory class implementation. This class is responsible 
for inventory processing (bill dispensing and restocking)
==============================================================================*/

#include "../Include/Inventory.h"

#include <iostream>

Inventory::Inventory()
{
    Restock();
}

void Inventory::Restock()
{
    inventory_map = default_inventory_map;

    total = 0;
    for(auto denomination = inventory_map.begin(); denomination != inventory_map.end(); ++denomination)
    {
        total += denomination->first * denomination->second;
    }
}

bool Inventory::Dispense(unsigned payout)
{
    if (total >= payout)
    {
        std::map<unsigned, unsigned> dispense_map = default_dispense_map;

        unsigned remainder = payout;
        for(auto denomination = inventory_map.rbegin(); denomination != inventory_map.rend(); ++denomination)
        {
            if (remainder >= denomination->first)
            {
                unsigned bill_number = remainder / denomination->first;
                denomination->second -= bill_number;

                dispense_map[denomination->first] = bill_number;

                remainder %= denomination->first;
            }
        }

        total -= payout;

        for (auto dispense = dispense_map.begin(); dispense != dispense_map.end(); ++dispense)
        {
            std::cout << "$" << dispense->first << "," << dispense->second << std::endl;
        }

        return true;
    }

    std::cout << "Insufficient Funds: " << payout << std::endl;

    return false;
}

void Inventory::Display()
{
    for(auto denomination = inventory_map.begin(); denomination != inventory_map.end(); ++denomination)
    {
        std::cout << "$" << denomination->first << "," << denomination->second << std::endl;
    }
}
