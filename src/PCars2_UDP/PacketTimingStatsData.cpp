// File: PacketTimingStatsData.cpp
#include "PacketTimingStatsData.h"
#include <inttypes.h>
#include <cstring>

const int TIMINGSTATS_BUFFER_SIZE = 1040;

PacketTimeStatsData::PacketTimeStatsData()
: PBase()
{}

PacketTimeStatsData::~PacketTimeStatsData(void)
{}

void PacketTimeStatsData::push(char *receiveBuffer)
{
    std::memcpy(PBase::firstElementPointer(), receiveBuffer, TIMINGSTATS_BUFFER_SIZE);
}

uint32_t PacketTimeStatsData::sParticipantsChangedTimeStamp1(void) 
{
    return sParticipantsChangedTimeStamp1_;
}

ParticipantsStatsInfo PacketTimeStatsData::sParticipantsStatsInfo(int index)
{
        if (index >= 0 && index < 32)
            return sParticipantsStatsInfo_[index];
        else return ParticipantsStatsInfo{};
}