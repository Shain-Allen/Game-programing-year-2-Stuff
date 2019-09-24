#include "WarBoats.h"
#include "Ocean.h"
#include <iostream> // cout, endl
#include <iomanip>  // setw

namespace CS175
{
    namespace WarBoats
    {
        const int BOAT_LENGTH = 4;  // Length of a boat
        const int HIT_OFFSET = 100; // Add this to the boat ID


        /*
        * ALL STUDENT IMPLEMENTATION GOES HERE
        */


		Ocean* CreateOcean(int num_boats, int x_quadrants, int y_quadrants)
		{
			//allocate Ocean struct
			Ocean* ocean = new Ocean;

			//allocate the set of rivers that point to the ocean
			ocean->grid = new int* [x_quadrants];

			//allocate the ocean itself
			for (int x = 0; x < x_quadrants; x++)
			{
				ocean->grid[x] = new int[y_quadrants];
			}

			for (int x = 0; x < x_quadrants; x++)
			{
				for (int y = 0; y < y_quadrants; y++)
				{
					ocean->grid[x][y] = 0;
				}
			}

			ocean->x_quadrants = x_quadrants;
			ocean->y_quadrants = y_quadrants;
			ocean->boats = new Boat[num_boats];
			ocean->stats.hits = 0;
			ocean->stats.misses = 0;
			ocean->stats.duplicates = 0;
			ocean->stats.sunk = 0;

			return ocean;
		}

		void DestroyOcean(Ocean* theOcean)
		{
			for (int x = 0; x < theOcean->x_quadrants; x++)
			{
				delete[] theOcean->grid[x];
				theOcean->grid[x] = nullptr;
			}

			delete[] theOcean->boats;
			delete[] theOcean->grid;
			delete theOcean;
			theOcean = nullptr;
		}

		//tell the player if their boat was placed properly
		BoatPlacement PlaceBoat(Ocean& ocean, const Boat& boat)
		{
			if ((boat.position.x >= 0 && boat.position.y >= 0) && (boat.position.x < ocean.x_quadrants && boat.position.y < ocean.y_quadrants))
			{
				if (boat.orientation == oHORIZONTAL)
				{
					if (boat.position.x + (BOAT_LENGTH - 1) < ocean.x_quadrants)
					{
						for (int i = 0; i < BOAT_LENGTH; i++)
						{
							if (ocean.grid[boat.position.x + i][boat.position.y] != 0)
							{
								return bpREJECTED;
							}
						}
						for (int b = 0; b < BOAT_LENGTH; b++)
						{
							ocean.grid[boat.position.x + b][boat.position.y] = boat.ID;
						}
						ocean.boats[boat.ID - 1].hits = 0;
						return bpACCEPTED;
					}
				}
				else
				{
					if (boat.position.y + (BOAT_LENGTH - 1) < ocean.y_quadrants)
					{
						for (int i = 0; i < BOAT_LENGTH; i++)
						{
							if (ocean.grid[boat.position.x][boat.position.y + i] != 0)
							{
								return bpREJECTED;
							}
						}
						for (int b = 0; b < BOAT_LENGTH; b++)
						{
							ocean.grid[boat.position.x][boat.position.y + b] = boat.ID;
						}
						ocean.boats[boat.ID - 1].hits = 0;
						return bpACCEPTED;
					}
				}
			}
			return bpREJECTED;
		}

		//tell the player if their shot has landed
		ShotResult TakeShot(Ocean& ocean, const Point& coordinate)
		{
			if ((coordinate.x >= 0 && coordinate.x <= ocean.x_quadrants) && (coordinate.y >= 0 && coordinate.y <= ocean.y_quadrants))
			{
				if (ocean.grid[coordinate.x][coordinate.y] == dtBLOWNUP || ocean.grid[coordinate.x][coordinate.y] > HIT_OFFSET)
				{
					ocean.stats.duplicates += 1;
					return srDUPLICATE;
				}
				else if (ocean.grid[coordinate.x][coordinate.y] == dtOK)
				{
					ocean.grid[coordinate.x][coordinate.y] = dtBLOWNUP;
					ocean.stats.misses += 1;
					return srMISS;
				}
				else 
				{
					int id = ocean.grid[coordinate.x][coordinate.y];
					ocean.boats[(ocean.grid[coordinate.x][coordinate.y]) - 1].hits += 1;
					ocean.grid[coordinate.x][coordinate.y] += HIT_OFFSET;
					ocean.stats.hits += 1;
					if (ocean.boats[id - 1].hits == 4)
					{
						ocean.stats.sunk += 1;
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

		//tells the player the current board state
		ShotStats GetShotStats(const Ocean& ocean)
		{
			return ocean.stats;
		}
        
        /*********************************************************************/
        /*!
        \brief
        Prints the grid (ocean) to the screen.

        \param ocean
        The Ocean to print

        \param field_width
        How much space each position takes when printed.

        \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.

        \param showboats
        If true, the boats are shown in the output. (Debugging feature)
        */
        /*********************************************************************/
        void DumpOcean(const CS175::WarBoats::Ocean& ocean,
            int field_width,
            bool extraline,
            bool showboats)
        {
            // For each row
            for (int y = 0; y < ocean.y_quadrants; y++)
            {
                // For each column
                for (int x = 0; x < ocean.x_quadrants; x++)
                {
                    int value = ocean.grid[x][y];

                    // Is it a boat?
                    if ((value > 0) && (value < HIT_OFFSET) && 
                        (showboats == false))
                    {
                        value = 0;
                    }

                    std::cout << std::setw(field_width) << value;
                }
                std::cout << std::endl;
                if (extraline)
                {
                    std::cout << std::endl;
                }
            }
        }

    } // namespace WarBoats
} // namespace CS175
