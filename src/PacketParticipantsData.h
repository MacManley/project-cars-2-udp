// File: PacketParticipantsData.h
#ifndef PACKETPARTICIPANTSDATA_H
#define PACKETPARTICIPANTSDATA_H
#define PARTICIPANT_NAME_LENGTH_MAX 64
#define PARTICIPANTS_PER_PACKET 16

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsData {
uint32_t sParticipantsChangedTimestamp;
char sName[PARTICIPANTS_PER_PACKET][PARTICIPANT_NAME_LENGTH_MAX]; // Player Name
uint32_t sNationality[PARTICIPANTS_PER_PACKET]; // Player Nationality
uint16_t sIndex[PARTICIPANTS_PER_PACKET]; // Session unique index in MP races
};

class PacketParticipantsData: public PBase {
public:
    PacketParticipantsData();
    virtual ~PacketParticipantsData();
    ParticipantsData sParticipantsData(int index);
    void push(char*receiveBuffer);
private:
    ParticipantsData sParticipantsData_[16];
};

#pragma pack(pop)

#endif 