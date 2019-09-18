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
				ocean->grid[x_quadrants] = new int[y_quadrants];
			}

			for (int x = 0; x < x_quadrants; x++)
			{
				for (int y = 0; y < y_quadrants; y++)
				{
					ocean->grid[x][y] = 0;
				}
			}
		}

		void DestroyOcean(Ocean* theOcean)
		{
			theOcean->
		}

		ShotResult TakeShot(Ocean& ocean, const Point& coordinate)
		{

		}

		BoatPlacement PlaceBoat(Ocean& ocean, const Boat& boat)
		{

		}

		ShotStats GetShotStats(const Ocean& ocean)
		{

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
        void DumpOcean(const CS175::WarBoats::Ocean ocean,
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
