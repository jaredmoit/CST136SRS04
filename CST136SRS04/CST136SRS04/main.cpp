#include "stdafx.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include "compareByLatitude.h"
#include "haversine.h"
#include "gps.h"
#include "compareByLongitude.h"
#include <forward_list>

template <typename Func>
auto vectorCalc(std::array<GPS::Location, 12> islands, Func compareBy)
{
	//vectors
	std::vector<std::reference_wrapper<GPS::Location>> islandVector(islands.begin(), islands.end());
	std::vector <double> distances(islands.size() - 1);

	//order islands
	std::sort(islandVector.begin(), islandVector.end(), compareBy);

	//calculate distance between each island, store each distance in vector
	for (auto i = 0; i < islandVector.size(); i++)
	{
		if (i != islandVector.size() - 1)
		{
			distances[i] += haversine(islandVector[i], islandVector[i + 1]);
		}
	}

	//get sum of distances without looping
	//std::accumulate(first, last, value);
	return std::accumulate(distances.begin(), distances.end(), 0);
}

template <typename Func>
auto forwardListCalc(std::array<GPS::Location, 12> islands, Func compareBy)
{
	//forward lists
	std::forward_list<GPS::Location> islandList(islands.begin(), islands.end());
	std::forward_list <double> distances(islands.size() - 1);

	//order islands
	islandList.sort(compareBy);

	//calculate distance between each island, store each distance in vector
	/*for (auto island : islandList)
	{
		if (i != islandList.max_size() - 1)
		{
			island++ += haversine(islandVector[i], islandVector[i + 1]);
		}
	}*/

	//get sum of distances without looping
	//std::accumulate(first, last, value);
	return std::accumulate(distances.begin(), distances.end(), 0);
}

int main()
{
	std::array<GPS::Location, 12> islands
	{
		GPS::Location{ "Faichuk Islands",  GPS::Latitude{ GPS::Latitude::Cardinal::N, 7, 21, 8 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 } },
		GPS::Location{ "Hawaii",           GPS::Latitude{ GPS::Latitude::Cardinal::N, 21, 18,41 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 157, 47, 47} },
		GPS::Location{ "Mariana Islands",  GPS::Latitude{ GPS::Latitude::Cardinal::N, 17,  0, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 146,  0,  0} },
		GPS::Location{ "Johnston Atoll",   GPS::Latitude{ GPS::Latitude::Cardinal::N, 16, 44,13 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 169, 31, 26} },
		GPS::Location{ "Kosrae",           GPS::Latitude{ GPS::Latitude::Cardinal::N,  5, 19, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 162, 59,  0} },
		GPS::Location{ "Falalop",          GPS::Latitude{ GPS::Latitude::Cardinal::N, 10,  1,14 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 139, 47, 23} },
		GPS::Location{ "Guam",             GPS::Latitude{ GPS::Latitude::Cardinal::N, 13, 30, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 144, 48,  0} },
		GPS::Location{ "Pohnpei",          GPS::Latitude{ GPS::Latitude::Cardinal::N,  6, 51, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 158, 13,  0} },
		GPS::Location{ "Marshall Islands", GPS::Latitude{ GPS::Latitude::Cardinal::N,  7,  7, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 171,  4,  0} },
		GPS::Location{ "Yap",              GPS::Latitude{ GPS::Latitude::Cardinal::N,  9, 32, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 138,  7,  0} },
		GPS::Location{ "Wake Island",      GPS::Latitude{ GPS::Latitude::Cardinal::N, 19, 17,43 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 166, 37, 52} },
		GPS::Location{ "New Zealand",      GPS::Latitude{ GPS::Latitude::Cardinal::S, 41, 17, 0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 174, 27,  0} }
	};

	auto dist1 = vectorCalc(islands, compareByLatitude());
	auto dist2 = vectorCalc(islands, compareByLongitude());
	auto dist3 = forwardListCalc(islands, compareByLatitude());
	auto dist4 = forwardListCalc(islands, compareByLongitude());


	//std::forward_list
	//std::map

	return 0;
}

