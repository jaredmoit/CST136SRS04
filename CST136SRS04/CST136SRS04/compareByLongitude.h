#pragma once
#include "compareByLongitude.h"
#include "gps.h"

struct compareByLongitude //comparison function object
{
	bool operator ()(const GPS::Location & loc1, const GPS::Location & loc2) const
	{
		if (loc1.longitude_.cardinal_ == loc2.longitude_.cardinal_) {
			if (loc1.longitude_.degree_.value_ == loc2.longitude_.degree_.value_) {
				if (loc1.longitude_.minute_.value_ == loc2.longitude_.minute_.value_) {
					if (loc1.longitude_.second_.value_ == loc2.longitude_.second_.value_) {
						return true;
					}
					else { return loc1.longitude_.second_.value_ < loc2.longitude_.second_.value_; }
				}
				else { return loc1.longitude_.minute_.value_ < loc2.longitude_.minute_.value_; }
			}
			else { return loc1.longitude_.degree_.value_ < loc2.longitude_.degree_.value_; }
		}
		else { return loc1.longitude_.cardinal_ < loc2.longitude_.cardinal_; }
	}
};