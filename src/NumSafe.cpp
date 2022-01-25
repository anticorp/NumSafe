/*
 Name:		NumSafe.cpp
 Created:	6/1/2021 9:00:18 PM
 Author:	Robert
 Editor:	http://www.visualmicro.com
*/
#include <float.h>
#include "NumSafe.h"
#include <ADM.h>

namespace numsafe
{
	using namespace adm::SHORTSTREAMKEYWORDS;
	namespace percentify
	{
		uint8_t Uint8bit(const int32_t& _in)
		{
			float floatPercent = float(Percent(_in)) / 100.00f;
			return uint8_t(255 * floatPercent);
		}
	}
	uint8_t Percent(const int32_t& _in)
	{
		return UintAndTrimTop(_in, 100);
	}
	uint8_t Uint8bit(const int32_t& _in)
	{
		return TrimToThresholds(_in, 0, 255);
	}
	uint32_t UintAndTrimTop(const int32_t& _target, const uint32_t& _top)
	{
		return TrimToThresholds(_target, 0, _top);
	}
	int32_t TrimToThresholds(const int32_t& inputNumber, const int32_t& bottomThreshold, const int32_t& topThreshold)
	{
		bug << trace << "\n [_" << __FUNCTION__ << "()_]\n";
		int32_t bottomed = (inputNumber < bottomThreshold ? bottomThreshold : inputNumber);
		int32_t topped = (bottomed > topThreshold ? topThreshold : bottomed);
		bug << vars << bugVar(bottomed) << bugVar(topped);
		bug << trace << "\n [_END_]=[_" << __FUNCTION__ << "()_]";
		return topped;
	}
	uint8_t GetTimeFactoredPinValue(const uint8_t& originalStartingIntensity, const uint8_t& targeEndingtIntensity, const uint32_t& timeSinceStart, const uint32_t& totalTimeRange)
	{
		bug << trace << "\n [_" << __FUNCTION__ <<"()_]\n";
		uint8_t deltaAddedPinValue = IntensityDeltaFactorAdder(originalStartingIntensity, targeEndingtIntensity, SignedIntensityDelta((targeEndingtIntensity - originalStartingIntensity), timeSinceStart, totalTimeRange));
		xbugVar(deltaAddedPinValue);
		bug << trace << "\n [_END_]=[_" << __FUNCTION__ << "()_]";
		return deltaAddedPinValue;
	}
	int SignedIntensityDelta(const int& channelIntensityRange, const uint32_t& timeSinceStart, const uint32_t& totalTimeRange)
	{
		bug << trace << "\n [_START_]=[_" << __FUNCTION__ << "()_]\n";
		bug << vars << bugVar(channelIntensityRange) << bugVar(timeSinceStart) << bugVar(totalTimeRange);
		double timeDeltaFactor = double(timeSinceStart) / double(totalTimeRange);
		xbugDbl(timeDeltaFactor);
		double newTargetIntensity = timeDeltaFactor * double(channelIntensityRange);
		xbugDbl(newTargetIntensity);
		bug << trace << "\n [_END_]=[ " << __FUNCTION__ << "()_] ";
		//Serial.print(timeDeltaFactor);
		return newTargetIntensity;
	}
	uint8_t IntensityDeltaFactorAdder(const uint8_t& channelIntensityBase, const uint8_t& channelIntensityTarget, const int& signedChangeFactor)
	{
		bug << trace << "\n [_START_]=[_" << __FUNCTION__ << "()_] ";
		int newValue = channelIntensityBase + signedChangeFactor;
		xbugVar(newValue);
		uint8_t deltaPlus = TrimToThresholds(newValue, 0, channelIntensityTarget);
		xbugVar(deltaPlus);
		bug << trace << "\n [_END_]=[_" << __FUNCTION__ << "()_] ";
		return deltaPlus;
	}
}

