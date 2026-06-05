// File: PacketTelemetryData.h
#ifndef PACKETTELEMETRYDATA_H
#define PACKETTELEMETRYDATA_H
#define TYRE_NAME_LENGTH_MAX 40

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct TelemetryData {
   int8_t sViewedParticipantIndex; // Index of currently viewed car 
   uint8_t sUnfilteredThrottle; // Unfiltered throttle input (RANGE: 0 -> 255)
   uint8_t sUnfilteredBrake; // Unfiltered brake input (RANGE: 0 -> 255)
   int8_t sUnfilteredSteering; // Unfiltered steering input (RANGE: -127 -> 127)
   uint8_t sUnfilteredClutch; // Unfiltered clutch input (RANGE: 0 -> 255)
   uint8_t sCarFlags; // Flags for different car states
   int16_t sOilTempCelsius; // Oil temp in degrees Celsius
   uint16_t sOilPressurekPa; // Oil pressure in kPa
   int16_t sWaterTempCelsius; // Water temp in degrees Celsius
   int16_t WaterPressurekPa; // Water pressure in kPa
   uint16_t sFuelPressurekPa; // Fuel pressure in kPa
   uint8_t sFuelCapacity; // Fuel capacity
   uint8_t sBrake; // Filtered brake input (RANGE: 0 -> 255) 
   uint8_t sThrottle; // Filtered throttle input (RANGE: 0 -> 255)
   uint8_t sClutch; // Filtered clutch input (RANGE: 0 -> 255) 
   float sFuelLevel; // Current fuel level as a fraction of 1 (RANGE: 0.0f -> 1.0f)
   float sSpeed; // Speed in m/s
   uint16_t sRpm; // RPM of drivetrain
   uint16_t sMaxRpm; // Maximum RPM
   int8_t sSteering; // Filtered steering input (- = left, + = right) (RANGE: -127 -> 127)
   uint8_t sGearNumGears; // Data for number of gears in the car and currently selected gear
   uint8_t sBoostAmount; // Current amount of boost as a percentage
   uint8_t sCrashState; // Crash damage state of car
   float sOdometerKM; // Odomoter of the car in km
   float sOrientation[3]; // Orientation of car in Euler Angles
   float sLocalVelocity[3]; // Local velocity of car in m/s
   float sWorldVelocity[3]; // Velocity of the car relative to the world in m/s
   float sAngularVelocity[3]; // Angular Velocity of the car in rads^-1
   float sLocalAcceleration[3]; // Local acceleration of the car in m/s
   float sWorldAcceleration[3]; // Acceleration of the car relative to the world in m/s
   float sExtentsCentre[3]; // Centre position of the world
   uint8_t sTyreFlags[4]; // Flags related to each tyre
   uint8_t sTerrains[4]; // Current terrain type in contact with each tyre
   float sTyreY[4]; // Local tyre Y position
   float sTyreRPS[4]; // Anglular velocity of each wheel in rps
   uint8_t sTyreTemp[4]; // Temperature of each tyre in degrees Celsius
   float sTyreHeightAboveGround[4]; // Height of each tyre above the ground in meters
   uint8_t sTyreWear[4]; // Wear of each tyre as a fraction of 255
   uint8_t sBrakeDamage[4]; // Brake damage for each wheel as a fraction of 255
   uint8_t sSuspensionDamage[4]; // Suspension damage at wheel as a fraction of 255
   int16_t sBrakeTempCelsius[4]; // Temperature of each wheels brake in degrees Celsius
   uint16_t sTyreTreadTemp[4]; // Temperature of the tread for each tyre in Kelvins
   uint16_t sTyreLayerTemp[4]; // Temperature of the layer for each tyre in Kelvins
   uint16_t sTyreCarcassTemp[4]; // Temperature of the carcass for each tyre in Kelvins
   uint16_t sTyreRimTemp[4]; // Temperature of the rim for each tyre in Kelvins
   uint16_t sTyreInternalAirTemp[4]; // Temperature of the air in each tyre in Kelvins
   uint16_t sTyreTempLeft[4]; // Temperature on the left side for each tyre in Kelvins
   uint16_t sTyreTempCenter[4]; // Temperature in the centre for each tyre in Kelvins
   uint16_t sTyreTempRight[4]; // Temperature on the right side for each tyre in Kelvins
   float sWheelLocalPositionY[4]; // Position of wheel relative to car
   float sRideHeight[4]; // Ride height of the car at each wheel in meters
   float sSuspensionTravel[4]; // Travel of the suspension of each wheel in meters
   float sSuspensionVelocity[4]; // Velocity of pushrod deflection at each wheel in m/s
   uint16_t sSuspensionRideHeight[4]; // Ride height of the suspension at each wheel in cm
   uint16_t sAirPressure[4]; // Air pressure of each tyre in centibar
   float sEngineSpeed; // Speed of the enging in rads^-1
   float sEngineTorque; // Torque of the engine in Nm
   uint8_t sWings[2]; // How much wing is being used on the car (RANGE: 0 -> 255)
   uint8_t sHandBrake; // Amount of handbrake applied as a fraction of 255
   uint8_t sAeroDamage; // Damage to the aero as a fraction of 255
   uint8_t sEngineDamage; // Damage to the engine of the car as a fraction of 255
   uint32_t sJoyPad; // WORK IN PROGRESS
   uint8_t sDPad; // DPad input (FORMAT AND RANGE COMING WORK IN PROGRESS)
   char sTyreCompound[4][TYRE_NAME_LENGTH_MAX]; // Tyre compound name of each tyre
   float sTurboBoostPressure; // Turbo boost pressure
   float sFullPosition[3]; // Position of the viewed participant
   uint8_t sBrakeBias; // Brake bias being used on the car as a fraction of 255
   uint32_t TickCount; // Game tick count
};

class PacketTelemetryData: public PBase {
public:
   PacketTelemetryData();
   virtual ~PacketTelemetryData();
   TelemetryData sTelemetryData(void);
   void push(char*receiveBuffer);
private:
   TelemetryData sTelemetryData_;
};

#pragma pack(pop)

#endif 