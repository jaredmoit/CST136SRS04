#include "stdafx.h"
#include <cmath>
#include "haversine.h"
#include "gps.h"

#define earthRadiusKm 6378
#define PI 3.14159

double deg2rad(double deg) {
	return (deg * PI / 180);
}

double haversine(const GPS::Location & loc1, const GPS::Location & loc2)
{
	//Get lat / lng of locations
	//Decimal Degrees = degrees + (minutes/60) + (seconds/3600)
	const auto lat1d = loc1.latitude_.degree_.value_
		+ (loc1.latitude_.minute_.value_ / 60.0)
		+ (loc1.latitude_.minute_.value_ / 3600.0);
	const auto lat2d = loc2.latitude_.degree_.value_
		+ (loc2.latitude_.minute_.value_ / 60.0)
		+ (loc2.latitude_.minute_.value_ / 3600.0);
	const auto lng1d = loc1.longitude_.degree_.value_
		+ (loc1.longitude_.minute_.value_ / 60.0)
		+ (loc1.longitude_.minute_.value_ / 3600.0);
	const auto lng2d = loc2.longitude_.degree_.value_
		+ (loc2.longitude_.minute_.value_ / 60.0)
		+ (loc2.longitude_.minute_.value_ / 3600.0);

	//From https://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lng1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lng2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}