#pragma once
#include "forwardListCalc.h"
#include <array>
#include <numeric>
#include <vector>
#include "haversine.h"
#include "gps.h"
#include <forward_list>

template <typename Func>
static constexpr auto forwardListCalc(std::array<GPS::Location, 12> & islands, Func compareBy)
{
	//forward lists
	std::forward_list<GPS::Location> islandList(islands.begin(), islands.end());
	std::vector <double> distances(islands.size() - 1);

	//order islands
	islandList.sort(compareBy);

	//calculate distance between each island, store each distance in list
	auto position = 0;
	for (auto iterator = islandList.begin(); iterator != islandList.end(); ++iterator, ++position) {
		auto nextIterator = iterator;
		std::advance(nextIterator, 1);
		if (nextIterator == islandList.end()) break;

		distances[position] = haversine(*iterator, *nextIterator);
	}

	//get sum of distances without looping
	return std::accumulate(distances.begin(), distances.end(), 0.0);
}