#pragma once
template<typename T, T min, T max>
class Range // You should re-code and simplify your SRS01 RangeInt
{
private:
	using value_type = T;

	static constexpr auto kUnboundLower{ std::numeric_limits<value_type>::min() };
	static constexpr auto kUnboundUpper{ std::numeric_limits<value_type>::max() };
	value_type upperBound{ kUnboundUpper };
	value_type lowerBound{ kUnboundLower };
	value_type value_;

	bool isValid(value_type v)
	{
		const auto result{ v >= lowerBound && v < upperBound };
		return result;
	}

public:
	Range(const value_type value)
		:lowerBound(min), upperBound(max), value_(isValid(value) ? value : kUnboundLower)
	{

	}
};