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
			

			grid = new int[x_quadrants * y_quadrants];

			
		}

		//destructor
		Ocean::~Ocean(void)
		{
			delete grid;
		}

		//Places Boats
		BoatPlacement Ocean::PlaceBoat(const Boat& boat_)
		{
			return BoatPlacement();
		}

		//take the Shot
		ShotResult Ocean::TakeShot(const Point& coordinate_)
		{
			return ShotResult();
		}

		//find out what hit
		ShotStats& Ocean::GetShotStats(void)
		{
			// TODO: insert return statement here
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

