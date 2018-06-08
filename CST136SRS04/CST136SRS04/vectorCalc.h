#pragma once
#include "vectorCalc.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include "gps.h"
#include "haversine.h"

template <typename Func>
static constexpr auto vectorCalc(std::array<GPS::Location, 12> & islands, Func compareBy)
{
	//vectors
	std::vector<std::reference_wrapper<GPS::Location>> islandVector(islands.begin(), islands.end());
	std::vector <double> distances(islands.size() - 1);

	//order islands
	std::sort(islandVector.begin(), islandVector.end(), compareBy);

	//calculate distance between each island, store each distance in vector
	for (size_t i = 0; i < islandVector.size(); i++)
	{
		if (i != islandVector.size() - 1)
		{
			distances[i] = haversine(islandVector[i], islandVector[i + 1]);
		}
	}

	//get sum of distances without looping
	return std::accumulate(distances.begin(), distances.end(), 0.0);
}
