#include "WarBoats.h"
#include "Ocean.h"

namespace CS175
{
    namespace WarBoats
    {  
        /*
        * ALL STUDENT IMPLEMENTATION GOES HERE
        */

		Ocean::Ocean(int num_boats_, int x_quadrants_, int y_quadrants_)
		{
		}

		Ocean::~Ocean(void)
		{
		}

		BoatPlacement Ocean::PlaceBoat(const Boat& boat_)
		{
			return BoatPlacement();
		}

		ShotResult Ocean::TakeShot(const Point& coordinate_)
		{
			return ShotResult();
		}

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

