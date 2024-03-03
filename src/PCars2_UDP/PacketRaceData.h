// File: PacketRaceData.h
#ifndef PACKETRACEDATA_H
#define PACKETRACEDATA_H
#define TRACKNAME_LENGTH_MAX 64

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct RaceData {
float sWorldFastestLapTime; // Fastest global laptime (FORMAT: SECONDS.MILLISECONDS)
float sPersonalFastestLapTime;  // Fastest personal laptime (FORMAT: SECONDS.MILLISECONDS)
float sPersonalFastestSector1Time; // Fastest personal sector 1 time (FORMAT: SECONDS.MILLISECONDS)
float sPersonalFastestSector2Time; // Fastest personal sector 2 time (FORMAT: SECONDS.MILLISECONDS)
float sPersonalFastestSector3Time; // Fastest personal sector 3 time (FORMAT: SECONDS.MILLISECONDS)
float sWorldFastestSector1Time; // Fastest global sector 1 time (FORMAT: SECONDS.MILLISECONDS)
float sWorldFastestSector2Time; // Fastest global sector 2 time (FORMAT: SECONDS.MILLISECONDS)
float sWorldFastestSector3Time; // Fastest global sector 3 time (FORMAT: SECONDS.MILLISECONDS)
float sTrackLength; // Track length in meters
char sTrackLocation[TRACKNAME_LENGTH_MAX]; // Track location
char sTrackVariation[TRACKNAME_LENGTH_MAX]; // Track variation
char sTranslatedTrackLocation[TRACKNAME_LENGTH_MAX]; // Translated track location
char sTranslatedTrackVariation[TRACKNAME_LENGTH_MAX]; // Translated track variation
uint16_t slapsTimeInEvent; // Contains lap number for lap based session or quantized session duration (number of 5mins) for timed sessions, the top bit is 1 for timed sessions
int8_t sEnforcedPitStopLap; // Mandatory pit stop lap
uint8_t paddingA;
};

class PacketRaceData: public PBase {
public:
    PacketRaceData();
    virtual ~PacketRaceData();
    RaceData sRaceData(void);
    void push(char*receiveBuffer);
private:
    RaceData sRaceData_;
};

#pragma pack(pop)

#endif 