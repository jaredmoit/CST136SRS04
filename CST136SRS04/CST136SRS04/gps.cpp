#include "stdafx.h"
#include "gps.h"

template <int min, int max>
GPS::Angle<min, max>::Angle(const degree_type degree, const minute_type minute, const second_type second)
	:degree_(degree), minute_(minute), second_(second)
{

}


GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude)
	:name_(name), latitude_(latitude), longitude_(longitude)
{

}

GPS::Latitude::Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second)
	: Angle(degree, minute, second), cardinal_(cardinal)
{

}

GPS::Longitude::Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second)
	: Angle(degree, minute, second), cardinal_(cardinal)
{

}
