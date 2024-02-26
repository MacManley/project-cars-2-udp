// File: PacketTimingsData.h
#ifndef PACKETTIMINGSDATA_H
#define PACKETTIMINGSDATA_H
#define UDP_STREAMER_PARTICIPANTS_SUPPORTED 32

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsInfo {
int16_t sWorldPosition[3];
int16_t sOrientation[3];
uint16_t sCurrentLapDistance;
uint8_t sRacePosition;
uint8_t sSector;
uint8_t sHighestFlag;
uint8_t sPitModeSchedule;
uint16_t sCarindex;
uint8_t sRaceState;
uint8_t sCurrentLap;
float sCurrentTime;
float sCurrentSectorTime;
uint16_t sMPParticipantIndex;
};

class PacketTimingsData : public PBase {
public: 
    PacketTimingsData();
    virtual ~PacketTimingsData();
    int8_t sNumParticipants(void);
    uint32_t sParticipantsChangedTimeStamp2(void);
    float sEventTimeRemaining(void);
    float sSplitTimeAhead(void);
    float sSplitTimeBehind(void);
    float sSplitTime(void);
    ParticipantsInfo sParticipantInfo(int index);
    uint16_t sLocalParticipantIndex(void);
    uint32_t sTickCount(void);
    void push(char*receiveBuffer);
private: 
    int8_t sNumParticipants_;
    uint32_t sParticipantsChangedTimeStamp2_;
    float sEventTimeRemaining_;
    float sSplitTimeAhead_;
    float sSplitTimeBehind_;
    float sSplitTime_;
    ParticipantsInfo sParticipantsInfo_[32];
    uint16_t sLocalParticipantIndex_;
    uint32_t TickCount_;
};

#pragma pack(pop)

#endif 