/*
 Name:		NumSafe.h
 Created:	6/1/2021 9:00:18 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/
#include <cstdint>
#ifndef _NumSafe_h
#define _NumSafe_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	//#include "WProgram.h"
#endif

namespace numsafe
{
	namespace percentify
	{
		/// <summary> Get Safe converted percentage of 255 </summary>
		uint8_t Uint8bit(const int32_t&);

	}
	uint8_t Percent(const int32_t&);
	uint8_t Uint8bit(const int32_t&);
	uint32_t UintAndTrimTop(const int32_t&, const uint32_t&);
	int32_t TrimToThresholds(const int32_t&, const int32_t&, const int32_t&);
	uint8_t GetTimeFactoredPinValue(const uint8_t& baseIntensity, const uint8_t& targetIntensity, const uint32_t& currentTime, const uint32_t& timeRange);
	int SignedIntensityDelta(const int& channelIntensityRange, const uint32_t& currentTime, const uint32_t& timeRange);
	uint8_t IntensityDeltaFactorAdder(const uint8_t& baseIntensity, const uint8_t& targetIntensity, const int& signedChangeFactor);
}

#endif

