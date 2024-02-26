// File: PacketTelemetryData.h
#ifndef PACKETTELEMETRYDATA_H
#define PACKETTELEMETRYDATA_H
#define TYRE_NAME_LENGTH_MAX 40

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct TelemetryData {
   int8_t sViewedParticipantIndex;
   uint8_t sUnfilteredThrottle; 
   uint8_t sUnfilteredBrake;
   int8_t sUnfilteredSteering;
   uint8_t sUnfilteredClutch;
   uint8_t sCarFlags;
   int16_t sOilTempCelsius;
   uint16_t sOilPressureKpa;
   int16_t sWaterTempCelsius;
   int16_t WaterPressureKPa;
   uint16_t sFuelPressureKpa;
   uint8_t sFuelCapacity;
   uint8_t sBrake;
   uint8_t sThrottle;
   uint8_t sClutch;
   float sFuelLevel;
   float sSpeed;
   uint16_t sRpm;
   uint16_t sMaxRpm;
   int8_t sSteering;
   uint8_t sGearNumGears;
   uint8_t sBoostAmount;
   uint8_t sCrashState;
   float sOdometerKM;
   float sOrientation[3];
   float sLocalVelocity[3];
   float sWorldVelocity[3];
   float sAngularVelocity[3];
   float sLocalAcceleration[3];
   float sWorldAcceleration[3];
   float sExtentsCentre[3];
   uint8_t sTyreFlags[4];
   uint8_t sTerrains[4];
   float sTyreY[4];
   float sTyreRPS[4];
   uint8_t sTyreTemp[4];
   float sTyreHeightAboveGround[4];
   uint8_t sTyreWear[4];
   uint8_t sBrakeDamage[4];
   uint8_t sSuspensionDamage[4];
   int16_t sBrakeTempCelsius[4];
   uint16_t sTyreThreadTemp[4];
   uint16_t sTyreLayerTemp[4];
   uint16_t sTyreCarcassTemp[4];
   uint16_t sTyreRimTemp[4];
   uint16_t sTyreInternalAirTemp[4];
   uint16_t sTyreTempLeft[4];
   uint16_t sTyreTempCenter[4];
   uint16_t sTyreTempRight[4];
   float sWheelLocalPositionY[4];
   float sRideHeight[4];
   float sSuspensionTravel[4];
   float sSuspensionVelocity[4];
   uint16_t sSuspensionRideHeight[4];
   uint16_t sAirPressure[4];
   float sEngineSpeed;
   float sEngineTorque;
   uint8_t sWings[2];
   uint8_t sHandBrake;
   uint8_t sAeroDamage;
   uint8_t sEngineDamage;
   uint32_t sJoyPad;
   uint8_t sDPad;
   char sTyreCompound[4][TYRE_NAME_LENGTH_MAX];
   float sTurboBoostPressure;
   float sFullPosition[3];
   uint8_t sBrakeBias;
   uint32_t TickCount;
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