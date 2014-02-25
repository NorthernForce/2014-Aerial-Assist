#include "MaxbotixUltrasonic.h"
#include "../Robotmap.h"

/** @brief Constructs an instance of the Max Botix Ultrasonic range finder
 *
 * @author Stephen Nutt
 */
MaxbotixUltrasonic::MaxbotixUltrasonic (
	int analogChannel,
	int serialChannel,
	int onChannel) :
	SubsystemWithCommand<void>("MaxbotixUltrasonic"),
	m_minVoltage (0.5),
	m_voltageRange (5.0 - m_minVoltage),
	m_minDistance (3.0),
	m_distanceRange (60 - m_minDistance),
	m_distanceChannel (analogChannel),
	m_serialMode (serialChannel),
	m_sensorOn (onChannel)
{
	m_serialMode.Set(1);
	m_sensorOn.Set(1);
}

/** @brief Constructs an instance of the Max Botix Ultrasonic range finder
 *
 * @author Stephen Nutt
 */
MaxbotixUltrasonic::MaxbotixUltrasonic (
	int analogChannel,
	int serialChannel,
	int onChannel,
	float minVoltage,
	float maxVoltage,
	float minDistance,
	float maxDistance) :
	SubsystemWithCommand<void>("MaxbotixUltrasonic"),
	m_minVoltage (minVoltage),
	m_voltageRange (maxVoltage - m_minVoltage),
	m_minDistance (minDistance),
	m_distanceRange (maxDistance - m_minDistance),
	m_distanceChannel (analogChannel),
	m_serialMode (serialChannel),
	m_sensorOn (onChannel)
{
	m_serialMode.Set(1);
	m_sensorOn.Set(1);
}

/** @brief Returns the range in inches
 *
 * @author Stephen Nutt
 */
double MaxbotixUltrasonic::GetRangeInInches() const
{
	//const float range = (m_distanceChannel.GetVoltage() - m_minVoltage) / m_voltageRange;
	//return static_cast<unsigned> ((range * m_distanceRange) + m_minDistance);
	return m_distanceChannel.GetVoltage()/.0098; //9.8mV/Inch
}

/** @brief Returns the range in cm
 *
 * @author Stephen Nutt
 */
unsigned MaxbotixUltrasonic::GetRangeInCM() const
{
	const float range = (m_distanceChannel.GetVoltage() - m_minVoltage) / m_voltageRange;
	return static_cast<unsigned> (((range * m_distanceRange) + m_minDistance) * 2.54f);
}

float MaxbotixUltrasonic::GetRange() const
{
	return 0.01f * GetRangeInCM();
}
