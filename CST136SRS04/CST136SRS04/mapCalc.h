#pragma once
#include "mapCalc.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include "haversine.h"
#include "gps.h"
#include <map>

template <typename Func>
static constexpr auto mapCalc(std::array<GPS::Location, 12> & islands, Func compareBy)
{
	//Can't sort map by value so just sort using a vector
	std::vector<std::reference_wrapper<GPS::Location>> islandVector(islands.begin(), islands.end());
	std::sort(islandVector.begin(), islandVector.end(), compareBy);

	//populate map
	std::map<int, GPS::Location> islandMap{};
	auto it = islandMap.begin();
	for (size_t i = 0; i < islands.size(); i++)
	{
		islandMap.insert(it, std::make_pair(i, islandVector[i]));
	}
	std::vector <double> distances(islands.size() - 1);

	//calculate distance between each island, store each distance in vector
	for (auto i = 0; i < islandMap.size(); i++)
	{
		if (i != islandMap.size() - 1)
		{
			//at() throws exception if object at key doesn't exist
			distances[i] = haversine(islandMap.at(i), islandMap.at(i + 1));
		}
	}

	//get sum of distances without looping
	return std::accumulate(distances.begin(), distances.end(), 0.0);
}