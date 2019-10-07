//------------------------------------------------------------------------------
//
// File Name:	Ocean.h
// Author(s):	Shain Allen
// Project:		WarBoats
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once
#include "WarBoats.h" // ShotStats

namespace CS175
{
    namespace WarBoats
    {
        // The attributes of the ocean
        struct Ocean
        {
            int **grid;        // The 2D ocean 
            Boat *boats;      // The dynamic array of boats
            int num_boats;    // Number of boats in the ocean
            int x_quadrants;  // Ocean size along x-axis
            int y_quadrants;  // Ocean size along y-axis
            ShotStats stats;  // Status of the attack
        };
    } // namespace WarBoats
} // namespace CS175

