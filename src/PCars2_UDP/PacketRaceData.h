// File: PacketRaceData.h
#ifndef PACKETRACEDATA_H
#define PACKETRACEDATA_H
#define TRACKNAME_LENGTH_MAX 64

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

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
char sTrackLocation[TRACKNAME_LENGTH_MAX];
char sTrackVariation[TRACKNAME_LENGTH_MAX];
char sTranslatedTrackLocation[TRACKNAME_LENGTH_MAX];
char sTranslatedTrackVariation[TRACKNAME_LENGTH_MAX];
uint16_t slapsTimeInEvent;
int8_t sEnforcedPitStopLap;
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