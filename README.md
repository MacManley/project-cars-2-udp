# Project Cars 2 UDP | Library for use on ESP 32 / ESP8266 devices
**Data Output from Project Cars 2 Game**

This program captures and parses data packets that are sent by the Project Cars 2 game. This library is written specifically for usage on the ESP32 and ESP8266.

# Usage:
```C
#include "PCars2_UDP.h"
PCars2_Parser* parser;

void loop()
{
    parser = new PCars2_Parser();
    parser->push(*buffer)
}

```
### Packet Types

The following data types are used in the structures:

| Type   | Description             |
| ------ | ----------------------- |
| uint8  | Unsigned 8-bit integer  |
| int8   | Signed 8-bit integer    |
| uint16 | Unsigned 16-bit integer |
| int16  | Signed 16-bit integer   |
| uint32 | Unsigned 32-bit integer |
| float  | Floating point (32-bit) |
| uint64 | Unsigned 64-bit integer |

Each packet has the following header:

Size: 29 bytes

```c#
struct PacketBase
{
uint32 mPacketNumber;
uint32 mCategoryPacketNumber;
uint8 mPartialPacketIndex;
uint8 mPartialPacketNumber;
uint8 mPacketType;
uint8 mPacketVersion;
};
```

|**Packet Name**|**Value**|**Description**|
| - | - | - |
|Telemetry|0|Telemetry data for the viewed participant|
|Race Data|1|Race stats data|
|Participants Data|2|Participant names data|
|Timings Data|3|Participant timings data|
|Game State|4|Game State - Weather State also sent in this packet|
|Weather State|5|Not currently sent - Found in Game State Packet|
|Vehicle Names|6|Vehicle Class Names - Not sure if it is currently sent|
|Time Stats|7|Participant Stats and records|
|Participant Vehicle Names|8|Participant Vehicle Names|

## **Telemetry Packet**

The telemetry packet various telemetry points from the car currently viewed.

Frequency: Each tick of the UDP streamer as it is set in the options

Sent: During Race

Size: 559 bytes

```c#
struct TelemetryData
{
int8 sViewedParticipantIndex;
uint8 sUnfilteredThrottle; 
uint8 sUnfilteredBrake;
int8 sUnfilteredSteering;
uint8 sUnfilteredClutch;
uint8 sCarFlags;
int16 sOilTempCelsius;
uint16 sOilPressureKpa;
int16 sWaterTempCelsius;
int16 WaterPressureKPa;
uint16 sFuelPressureKpa;
uint8 sFuelCapacity;
uint8 sBrake;
uint8 sThrottle;
uint8 sClutch;
float sFuelLevel;
float sSpeed;
uint16 sRpm;
uint16 sMaxRpm;
int8 sSteering;
uint8 sGearNumGears;
uint8 sBoostAmount;
uint8 sCrashState;
float sOdometerKM;
float sOrientation[3];
float sLocalVelocity[3];
float sWorldVelocity[3];
float sAngularVelocity[3];
float sLocalAcceleration[3];
float sWorldAcceleration[3];
float sExtentsCentre[3];
uint8 sTyreFlags[4];
uint8 sTerrains[4];
float sTyreY[4];
float sTyreRPS[4];
uint8 sTyreTemp[4];
float sTyreHeightAboveGround[4];
uint8 sTyreWear[4];
uint8 sBrakeDamage[4];
uint8 sSuspensionDamage[4];
int16 sBrakeTempCelsius[4];
uint16 sTyreThreadTemp[4];
uint16 sTyreLayerTemp[4];
uint16 sTyreCarcassTemp[4];
uint16 sTyreRimTemp[4];
uint16 sTyreInternalAirTemp[4];
uint16 sTyreTempLeft[4];
uint16 sTyreTempCenter[4];
uint16 sTyreTempRight[4];
float sWheelLocalPositionY[4];
float sRideHeight[4];
float sSuspensionTravel[4];
float sSuspensionVelocity[4];
uint16 sSuspensionRideHeight[4];
uint16 sAirPressure[4];
float sEngineSpeed;
float sEngineTorque;
uint8 sWings[2];
uint8 sHandBrake;
uint8 sAeroDamage;
uint8 sEngineDamage;
uint32 sJoyPad;
uint8 sDPad;
char sTyreCompound[4][TYRE_NAME_LENGTH_MAX];
float sTurboBoostPressure;
float sFullPosition[3];
uint8 sBrakeBias;
uint32 TickCount;
};
struct PacketTelemetryData
{
PacketBase m_base; // Header
TelemetryData sTelemetryData; 
};
```

## **Race Data**

The race data packet details track, global and local lap info.

Frequency: Logarithmic decrease

Sent: Counter resets on entering InRace state and again each time any of the values changes

Size: 308 bytes

```c#
struct RaceData {
float sWorldFastestLapTime;
float sPersonalFastestLapTime;
float sPersonalFastestSector1Time;
float sPersonalFastestSector2Time;
float sPersonalFastestSector3Time;
float sWorldFastestSector1Time;
float sWorldFastestSector2Time;
float sWorldFastestSector3Time;
float sTrackLength;
char sTrackLocation[64];
char sTrackVariation[64];
char sTranslatedTrackLocation[64];
char sTranslatedTrackVariation[64];
uint16 slapsTimeInEvent;
int8 sEnforcedPitStopLap;
uint8 paddingA;
};

struct PacketRaceData
{
PacketBase m_base; // Header
RaceData sRaceData; 
};
```

## **Participants Data**

The participants data packet provides information about participants names & nationality.

Frequency: Logarithmic decrease

Sent: Counter resets on entering InRace state and again each  the participants change. 
      The sParticipantsChangedTimestamp represent last time the participants has changed and is to be used to sync 
	  this information with the rest of the participant related packets

Size: 1136 bytes

```c#
struct ParticipantsData {
uint32 sParticipantsChangedTimestamp;
char sName[PARTICIPANT_NAME_LENGTH_MAX];
uint32 sNationality[16];
uint16 sIndex[16];
};

struct PacketParticipantsData
{
PacketBase m_base; // Header
ParticipantData sParticipantData; 
};
```

## **Timings Data**

The timings packet provides information about participants names & intervals and laptimes.

Frequency: Each tick of the UDP streamer as it is set in the options

Sent: During Race

Size: 1063 bytes

```c#
struct ParticipantsInfo {
int16 sWorldPosition[3];
int16 sOrientation[3];
uint16 sCurrentLapDistance;
uint8 sRacePosition;
uint8 sSector;
uint8 sHighestFlag;
uint8 sPitModeSchedule;
uint16 sCarindex;
uint8 sRaceState;
uint8 sCurrentLap;
float sCurrentTime;
float sCurrentSectorTime;
uint16 sMPParticipantIndex;
};

struct PacketTimingsData {
PacketBase m_base;
int8 sNumParticipants;
uint32 sParticipantsChangedTimeStamp2;
float sEventTimeRemaining;
float sSplitTimeAhead;
float sSplitTimeBehind;
float sSplitTime;
ParticipantsInfo sParticipantsInfo[32];
uint16 sLocalParticipantIndex;
uint32 TickCount;
};
```

## **Game State Data**

The game state packet provides information about track status and weather, includes weather state packet data.

Frequency: Each 5s while being in Main Menu, Each 10s while being in race + on each change Main Menu<->Race several times.
the frequency in Race is increased in case of weather timer being faster  up to each 5s for 30x time progression

Sent: Always

Size: 24 bytes

```c#
struct GameStateData {
uint16 mBuildVersionNumber;
char mGameState;
int8 sAmbientTemperature;
int8 sTrackTemperature;
uint8 sRainDensity;
uint8 sSnowDensity;
int8 sWindSpeed;
int8 sWindDirectionX;
int8 sWindDirectionY;
short paddingD;
};

struct PacketGameStateData {
PacketBase m_base;
GameStateData sGameStateData;
};
```

## **Vehicle Class Names Data**

The time stats packet provides information about Vehicle Class Names.

Size: 1452 bytes

```c#
struct ClassInfo {
uint32 sClassIndex;
char sCName[CLASS_NAME_LENGTH_MAX];
};

struct PacketVehicleClassNamesData {
PacketBase m_base;
ClassInfo sVehicleClassNames[60];
};
```

## **Time Stats Data**

The time stats packet provides information about time stats.

Frequency: When entering the race and each time any of the values change, so basically each time any of the participants crosses a sector boundary.

Sent: During Race

Size: 1040 bytes

```c#
struct ParticipantsStatsInfo {
float	sFastestLapTime;								
float	sLastLapTime;									
float	sLastSectorTime;								
float	sFastestSector1Time;							
float	sFastestSector2Time;							
float	sFastestSector3Time;
uint32 sParticipantOnlineRep;
uint16 sMPParticipantIndex;
short paddingB;
};

struct PacketTimeStatsData {
PacketBase m_base;
uint32 sParticipantsChangedTimeStamp1_;
ParticipantsStatsInfo sParticipantsStatsInfo[32];
};
```

## **Participant Vehicle Names Data**

The participant vehicle names packet provides info of participants vehicles.

Frequency: Logarithmic decrease

Sent: Counter resets on entering InRace state and again each  the participants change. 
	  The sParticipantsChangedTimestamp represent last time the participants has changed and is  to be used to sync 
	  this information with the rest of the participant related packets

Size: 1164 bytes

```c#
struct VehicleInfo {
uint16 sIndex;
uint32 sClass;
char sVName[VEHICLE_NAME_LENGTH_MAX];
short paddingC;
};

struct PacketParticipantVehicleNamesData {
PacketBase m_base;
VehicleInfo sVehicleInfo[16];
}
```

## **PacketType IDs**

|**ID**|**Type**|
| :-: | :- |
|0|CarPhysics|
|1|RaceDefinition|
|2|Participants|
|3|Timings|
|4|GameState|
|5|WeatherState|
|6|VehicleNames|
|7|TimeStats|
|8|ParticipantVehicleNames|

## **GameState IDs**

|**ID**|**State**|
| :-: | :- |
|0|Exited|
|1|FrontEnd|
|2|Playing|
|3|Paused|
|4|InMenuTimeTicking|
|5|Retsarting|
|6|Replay|
|7|FrontEndReplay|

## **SessionState IDs**

|**ID**|**State**|
| :-: | :- |
|0|Invalid|
|1|Practice|
|2|Test|
|3|Qualify|
|4|FormationLap|
|5|Race|
|6|TimeAttack|

## **RaceState IDs**

|**ID**|**State**|
| :-: | :- |
|0|Invalid|
|1|NotStarted|
|2|Racing|
|3|Finished|
|4|DSQ|
|5|Retired|
|6|DNF|

## **FlagColours IDs**

|**ID**|**Colour**|
| :-: | :- |
|0|None|
|1|Green|
|2|Blue|
|3|WhiteSlowCar|
|4|WhiteFinalLap|
|5|Red|
|6|Yellow|
|7|DoubleYellow|
|8|BlackAndWhite|
|9|BlackOrangeCircle|
|10|Black|
|11|Chequered|

## **FlagReason IDs**

|**ID**|**Reason**|
| :-: | :- |
|0|None|
|1|SoloCrash|
|2|VehicleCrash|
|3|VehicleObstruction|

## **PitMode IDs**

|**ID**|**Mode**|
| :-: | :- |
|0|None|
|1|DrivingIntoPits|
|2|InPit|
|3|DrivingOutPits|
|4|InGarage|
|5|DrivingOutGarage|

## **PitSchedule IDs**

|**ID**|**Schedule**|
| :-: | :- |
|0|None|
|1|PlayerRequested|
|2|EngineerRequested|
|3|PitScheduleDamageRequested|
|4|PitScheduleMandatory|
|5|PitScheduleDriveThrough|
|6|PitScheduleStopGo|
|7|PitSchedulePitspotOccupied|

## **TerrainMaterial IDs**

|**ID**|**Material**|
| :-: | :- |
| 0 | TerrainRoad |
| 1 | TerrainLowGripRoad |
| 2 | TerrainBumpyRoad1 |
| 3 | TerrainBumpyRoad2 |
| 4 | TerrainBumpyRoad3 |
| 5 | TerrainMarbles |
| 6 | TerrainGrassyBerms |
| 7 | TerrainGrass |
| 8 | TerrainGravel |
| 9 | TerrainBumpyGravel |
| 10 | TerrainRumbleStrips |
| 11 | TerrainDrains |
| 12 | TerrainTyrewalls |
| 13 | TerrainCementwalls |
| 14 | TerrainGuardrails |
| 15 | TerrainSand |
| 16 | TerrainBumpySand |
| 17 | TerrainDirt |
| 18 | TerrainBumpyDirt |
| 19 | TerrainDirtRoad |
| 20 | TerrainBumpyDirtRoad |
| 21 | TerrainPavement |
| 22 | TerrainDirtBank |
| 23 | TerrainWood |
| 24 | TerrainDryVerge |
| 25 | TerrainExitRumbleStrips |
| 26 | TerrainGrasscrete |
| 27 | TerrainLongGrass |
| 28 | TerrainSlopeGrass |
| 29 | TerrainCobbles |
| 30 | TerrainSandRoad |
| 31 | TerrainBakedClay |
| 32 | TerrainAstroturf |
| 33 | TerrainSnowhalf |
| 34 | TerrainSnowfull |
| 35 | TerrainDamagedRoad1 |
| 36 | TerrainTrainTrackRoad |
| 37 | TerrainBumpycobbles |
| 38 | TerrainAriesOnly |
| 39 | TerrainOrionOnly |
| 40 | TerrainB1rumbles |
| 41 | TerrainB2rumbles |
| 42 | TerrainRoughSandMedium |
| 43 | TerrainRoughSandHeavy |
| 44 | TerrainSnowwalls |
| 45 | TerrainIceRoad |
| 46 | TerrainRunoffRoad |
| 47 | TerrainIllegalStrip |
| 48 | TerrainPaintConcrete |
| 49 | TerrainPaintConcreteIllegal |
| 50 | TerrainRallyTarmac |

## **CrashDamageState IDs**

|**ID**|**Reason**|
| :-: | :- |
|0|None|
|1|CrashDamageOfftrack|
|2|CrashDamageLargeProp|
|3|CrashDamageSpinning|
|4|CrashDamageRolling|
