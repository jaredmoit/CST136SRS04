#pragma once

namespace GPS {
	class Location;
}

double deg2rad(double deg);
double haversine(const GPS::Location & loc1, const GPS::Location & loc2);
