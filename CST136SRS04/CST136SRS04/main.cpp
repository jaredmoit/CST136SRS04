#include "stdafx.h"
#include <array>
#include <algorithm>
#include "gps.h"


int main()
{
	std::array<GPS::Location, 12> islands
	{
		GPS::Location{ "Faichuk Islands", GPS::Latitude{ GPS::Latitude::Cardinal::N, 7, 21, 8 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 } },
		GPS::Location{ "Hawaii          ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 21, 18,41 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 157, 47, 47} },
		GPS::Location{ "Mariana Islands ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 17,  0, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 146,  0,  0} },
		GPS::Location{ "Johnston Atoll  ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 16, 44,13 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 169, 31, 26} },
		GPS::Location{ "Kosrae          ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  5, 19, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 162, 59,  0} },
		GPS::Location{ "Falalop         ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 10,  1,14 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 139, 47, 23} },
		GPS::Location{ "Guam            ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 13, 30, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 144, 48,  0} },
		GPS::Location{ "Pohnpei         ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  6, 51, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 158, 13,  0} },
		GPS::Location{ "Marshall Islands", GPS::Latitude{ GPS::Latitude::Cardinal::N,  7,  7, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 171,  4,  0} },
		GPS::Location{ "Yap             ", GPS::Latitude{ GPS::Latitude::Cardinal::N,  9, 32, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 138,  7,  0} },
		GPS::Location{ "Wake Island     ", GPS::Latitude{ GPS::Latitude::Cardinal::N, 19, 17,43 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 166, 37, 52} },
		GPS::Location{ "New Zealand     ", GPS::Latitude{ GPS::Latitude::Cardinal::S, 41, 17, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 174, 27,  0} }
	};

	//Your task is to navigate a route to Hawaii, making stops at every location along the way.

	/*Calculate the distance travelled as you hop from island to island.

	For each hop, follow a Great Circle. Approximated using the Haversine Formula to calculate the Kilometers between the islands. Assume the Earth's radius is: 6378_km.

	You must take 2 routes. The first is to travel from South to North, in order. The second is to travel from West to East in order.

	Record the distance travelled between each pair of locations in their order. South to North and West to East.

	Use 3 different data structures for the data to solve the distances. std::forward_list, std::vector, and std::map.

	This is a total of 6 combinations of calculations but you can only enter the data once into your program as a std::array.

	Record the distances in order of the destination Island Name distance and sum the total distance travelled for that route. Do NOT sum the distances by looping, you must use an algorithm.*/




	//order islands by order South to North
	std::sort(islands.begin(), islands.end());

	//calculate distance between each island, store each distance

	//sum the total distance travelled

	return 0;
}

