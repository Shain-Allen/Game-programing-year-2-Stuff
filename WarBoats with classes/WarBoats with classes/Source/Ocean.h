#pragma once

#include "WarBoats.h"

namespace CS175
{
  namespace WarBoats
  {
    const int BOAT_LENGTH = 4;  // Length of a boat
    const int HIT_OFFSET = 100; // Add this to the boat ID

    class Ocean
    {
      public:
        
          /*
           * Other public methods
          */

		  //constructor
		  Ocean(int num_boats_, int x_quadrants_, int y_quadrants_);

		  //destructor
		  ~Ocean(void);

		  //BoatPlacement
		  BoatPlacement PlaceBoat(const Boat& boat_);

		  //Allow the player to shoot things
		  ShotResult TakeShot(const Point& coordinate_);

		  //get the Stats of shots
		  const ShotStats& GetShotStats(void) const;

		  //1D array navigator (y * width + x)
		  int ArrayNavigator(int y_, int x_);
     
           // Provided
        const int *GetGrid(void) const;
        Point GetDimensions(void) const;

      private:
        int *grid;        // The 2D ocean
        int x_quadrants;  // Ocean size along x-axis
        int y_quadrants;  // Ocean size along y-axis
        
        /*
         * Other private data
        */
		ShotStats stats; //Status of the attack
		int *hits;
		int num_boats;
        
    }; // class Ocean

  } // namespace WarBoats

} // namespace CS175
