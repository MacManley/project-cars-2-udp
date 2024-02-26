// File: PacketParticipantsData.h
#ifndef PACKETPARTICIPANTSDATA_H
#define PACKETPARTICIPANTSDATA_H
#define PARTICIPANT_NAME_LENGTH_MAX 64

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ParticipantsData {
uint32_t sParticipantsChangedTimestamp;
char sName[PARTICIPANT_NAME_LENGTH_MAX];
uint32_t sNationality[16];
uint16_t sIndex[16];
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