// File: PacketParticipantsData.cpp
#include "PacketParticipantsData.h"
#include <inttypes.h>
#include <cstring>

const int PARTICIPANTSDATA_BUFFER_SIZE = 1136;

PacketParticipantsData::PacketParticipantsData()
: PBase()
{}

PacketParticipantsData::~PacketParticipantsData(void)
{}

void PacketParticipantsData::push(char *receiveBuffer)
{
    std::memcpy(PBase::pointerToFirstElement(), receiveBuffer, PARTICIPANTSDATA_BUFFER_SIZE);
}

ParticipantsData PacketParticipantsData::sParticipantsData(int index)
{
        if (index >= 0 && index < 16)
            return sParticipantsData_[index];
        else return ParticipantsData{};
}