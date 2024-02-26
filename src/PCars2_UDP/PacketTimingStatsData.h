// File: PacketTimingStatsData.h
#ifndef PACKETTIMINGSSTATSDATA_H
#define PACKETTIMINGSSTATSDATA_H
#define PARTICIPANT_NAME_LENGTH_MAX 64

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsStatsInfo {
float	sFastestLapTime;								
float	sLastLapTime;									
float	sLastSectorTime;								
float	sFastestSector1Time;							
float	sFastestSector2Time;							
float	sFastestSector3Time;
uint32_t sParticipantOnlineRep;
uint16_t sMPParticipantIndex;
short paddingB;
};

class PacketTimeStatsData : public PBase {
public:
    PacketTimeStatsData();
    virtual ~PacketTimeStatsData();
    uint32_t sParticipantsChangedTimeStamp1(void);
    ParticipantsStatsInfo sParticipantsStatsInfo(int index);
    void push(char *receiveBuffer);
private: 
    uint32_t sParticipantsChangedTimeStamp1_;
    ParticipantsStatsInfo sParticipantsStatsInfo_[32];
};

#pragma pack(pop)

#endif 