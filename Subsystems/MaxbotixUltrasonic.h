#pragma once

#include <WPILib.h>
#include "../Commands/RangeReadout.h"
#include "SubsystemWithCommand.hpp"

/**
 * @brief This class controls the Ultrasonic
 * Range Finding Sensor on the robot. All methods
 * for interacting with that sensor will go here.
 *
 * @author Arthur Lockman
 */
class MaxbotixUltrasonic : public SubsystemWithCommand<RangeReadout>
{
public:
	//! Constructor
	MaxbotixUltrasonic (int analogChannel, int serialChannel, int onChannel);

	//! Constructor
	MaxbotixUltrasonic (int analogChannel, int serialChannel, int onChannel,
		float minVoltage, float maxVoltage, float minDistance, float maxDistance);

	//! Just gets the voltage.
	inline float GetVoltage() const
	{
		return m_distanceChannel.GetVoltage();
	}

	//! Returns the range in inches
	double GetRangeInInches() const;

	//! Returns the range in centimeters
	unsigned GetRangeInCM() const;

    //! Returns the range in meters
    float GetRange() const;
	
private:
	//! Minimum voltage the ultrasonic sensor can return
    const float m_minVoltage;

	//! The range of the voltages returned by the sensor (maximum - minimum)
	const float m_voltageRange;
	
	//! Minimum distance the ultrasonic sensor can return in inches
	const float m_minDistance;
	
	//! The range of the distances returned by this class in inches (maximum - minimum)
	const float m_distanceRange;
	
	//!
	mutable AnalogChannel m_distanceChannel;
	
	DigitalOutput m_serialMode;
	
	DigitalOutput m_sensorOn;
};

