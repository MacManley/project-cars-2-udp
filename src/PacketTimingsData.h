// File: PacketTimingsData.h
#ifndef PACKETTIMINGSDATA_H
#define PACKETTIMINGSDATA_H
#define UDP_STREAMER_PARTICIPANTS_SUPPORTED 32

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsInfo {
int16_t sWorldPosition[3]; // 
int16_t sOrientation[3]; //  Quantized heading (-PI .. +PI) , Quantized pitch (-PI / 2 .. +PI / 2),  Quantized bank (-PI .. +PI)
uint16_t sCurrentLapDistance; // Distance in current lap
uint8_t sRacePosition; // Race position, + top bit shows if the participant is active or not
uint8_t sSector; //current sector + extra precision bits for x/z position
uint8_t sHighestFlag; // Flag color and reason (enum 3 bits/enum 2 bits)
uint8_t sPitModeSchedule; // Pit mode and pit schedule (enum 3 bits/enum 2 bits)
uint16_t sCarIndex; // top bit shows if particpant is a human player or not
uint8_t sRaceState; // race state flags & invalidated lap indication
uint8_t sCurrentLap; // Current lap
float sCurrentTime; // Current lap time
float sCurrentSectorTime; // Current sector time
uint16_t sMPParticipantIndex; // Matches sIndex from ParticipantsData
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
    int8_t sNumParticipants_; // Number of participants
    uint32_t sParticipantsChangedTimeStamp2_;
    float sEventTimeRemaining_; // Time remaining in the event
    float sSplitTimeAhead_; // Split time to car ahead
    float sSplitTimeBehind_; // Split time to car behind
    float sSplitTime_; // Split time
    ParticipantsInfo sParticipantsInfo_[32];
    uint16_t sLocalParticipantIndex_; // Identifies which participant is the local player
    uint32_t TickCount_; // Tick count of game
};

#pragma pack(pop)

#endif 