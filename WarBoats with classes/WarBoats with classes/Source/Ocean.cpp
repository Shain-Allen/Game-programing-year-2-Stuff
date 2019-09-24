#include "WarBoats.h"
#include "Ocean.h"

namespace CS175
{
    namespace WarBoats
    {  
        /*
        * ALL STUDENT IMPLEMENTATION GOES HERE
        */

		//Constructor
		Ocean::Ocean(int num_boats_, int x_quadrants_, int y_quadrants_)
		{
			x_quadrants = x_quadrants_;
			y_quadrants = y_quadrants_;
			num_boats = num_boats_;
			stats.duplicates = 0;
			stats.hits = 0;
			stats.misses = 0;
			stats.sunk = 0;

			grid = new int[x_quadrants * y_quadrants];

			for (int x = 0; x < x_quadrants; x++)
			{
				for (int y = 0; y < y_quadrants; y++)
				{
					grid[ArrayNavigator(x,y)] = 0;
				}
			}

			hits = new int[num_boats];
		}

		//destructor
		Ocean::~Ocean(void)
		{
			delete hits;
			delete grid;
		}

		//Places Boats
		BoatPlacement Ocean::PlaceBoat(const Boat& boat_)
		{
			if ((boat_.position.x >= 0 && boat_.position.y >= 0) && (boat_.position.x < x_quadrants && boat_.position.y < y_quadrants))
			{
				if (boat_.orientation == oHORIZONTAL)
				{
					if (boat_.position.x + (BOAT_LENGTH - 1) < x_quadrants)
					{
						for (int i = 0; i < BOAT_LENGTH; i++)
						{
							if (grid[ArrayNavigator(boat_.position.x + i,boat_.position.y)] != 0)
							{
								return bpREJECTED;
							}
						}
						for (int b = 0; b < BOAT_LENGTH; b++)
						{
							grid[ArrayNavigator(boat_.position.x + b,boat_.position.y)] = boat_.ID;
						}
						hits[boat_.ID - 1] = 0;
						return bpACCEPTED;
					}
				}
				else
				{
					if (boat_.position.y + (BOAT_LENGTH - 1) < y_quadrants)
					{
						for (int i = 0; i < BOAT_LENGTH; i++)
						{
							if (grid[ArrayNavigator(boat_.position.x,boat_.position.y + i)] != 0)
							{
								return bpREJECTED;
							}
						}
						for (int b = 0; b < BOAT_LENGTH; b++)
						{
							grid[ArrayNavigator(boat_.position.x,boat_.position.y + b)] = boat_.ID;
						}
						hits[boat_.ID - 1] = 0;
						return bpACCEPTED;
					}
				}
			}
			return bpREJECTED;
		}

		//take the Shot
		ShotResult Ocean::TakeShot(const Point& coordinate_)
		{
			if ((coordinate_.x >= 0 && coordinate_.x <= x_quadrants) && (coordinate_.y >= 0 && coordinate_.y <= y_quadrants))
			{
				if (grid[ArrayNavigator(coordinate_.x,coordinate_.y)] == dtBLOWNUP || grid[ArrayNavigator(coordinate_.x, coordinate_.y)] > HIT_OFFSET)
				{
					stats.duplicates += 1;
					return srDUPLICATE;
				}
				else if (grid[ArrayNavigator(coordinate_.x, coordinate_.y)] == dtOK)
				{
					grid[ArrayNavigator(coordinate_.x, coordinate_.y)] = dtBLOWNUP;
					stats.misses += 1;
					return srMISS;
				}
				else
				{
					int id = grid[ArrayNavigator(coordinate_.x, coordinate_.y)];
					hits[(grid[ArrayNavigator(coordinate_.x, coordinate_.y)]) - 1] += 1;
					grid[ArrayNavigator(coordinate_.x, coordinate_.y)] += HIT_OFFSET;
					stats.hits += 1;
					if (hits[id - 1] == 4)
					{
						stats.sunk += 1;
						return srSUNK;
					}
					return srHIT;
				}
			}
			else
			{
				return srILLEGAL;
			}
		}

		//find out what hit
		const ShotStats& Ocean::GetShotStats(void) const
		{
			return stats;
		}

		int Ocean::ArrayNavigator(int y_, int x_)
		{
			int Destination;

			Destination = y_ * x_quadrants + x_;

			return Destination;
		}

		const int *Ocean::GetGrid(void) const
        {
            return grid;
        }
  
        Point Ocean::GetDimensions(void) const
        {
            Point pt = {x_quadrants, y_quadrants};
            return pt;
        }

    } // namespace WarBoats

} // namespace CS175

