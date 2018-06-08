#pragma once
#include "compareByLatitude.h"
#include "gps.h"

struct compareByLatitude //comparison function object
{
	bool operator ()(const GPS::Location & loc1, const GPS::Location & loc2) const
	{
		if (loc1.latitude_.cardinal_ == loc2.latitude_.cardinal_) {
			if (loc1.latitude_.degree_.value_ == loc2.latitude_.degree_.value_) {
				if (loc1.latitude_.minute_.value_ == loc2.latitude_.minute_.value_) {
					if (loc1.latitude_.second_.value_ == loc2.latitude_.second_.value_) {
						return true;
					}
					else { return loc1.latitude_.second_.value_ < loc2.latitude_.second_.value_; }
				}
				else { return loc1.latitude_.minute_.value_ < loc2.latitude_.minute_.value_; }
			}
			else { return loc1.latitude_.degree_.value_ < loc2.latitude_.degree_.value_; }
		}
		else { return loc1.latitude_.cardinal_ < loc2.latitude_.cardinal_; }
	}
};
