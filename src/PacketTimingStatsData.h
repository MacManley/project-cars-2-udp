// File: PacketTimingStatsData.h
#ifndef PACKETTIMINGSSTATSDATA_H
#define PACKETTIMINGSSTATSDATA_H
#define PARTICIPANT_NAME_LENGTH_MAX 64

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsStatsInfo {
float	sFastestLapTime; // Fastest lap of the selected participant						
float	sLastLapTime; // Last lap time of the selected participant								
float	sLastSectorTime; // The last logged sector time of the selected participant						
float	sFastestSector1Time; // Fastest S1 time of the selected participant				
float	sFastestSector2Time; // Fastest S2 time of the selected participant							
float	sFastestSector3Time; // Fastest S3 time of the selected participant
uint16_t sRankType; // Which safety rank the competitor is
uint16_t  sStrength; // Strength of the competitor
uint16_t sMPParticipantIndex; // Index of viewed participant (matches sIndex from participantsdata)
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