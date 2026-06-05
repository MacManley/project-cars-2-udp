// File: PacketRaceData.cpp
#include "PacketRaceData.h"
#include <cstring>

const int RACEDATA_BUFFER_SIZE = 308;

PacketRaceData::PacketRaceData()
: PBase()
{}

PacketRaceData::~PacketRaceData()
{}

void PacketRaceData::push(char *receiveBuffer)
{
    std::memcpy(PBase::firstElementPointer(), receiveBuffer, RACEDATA_BUFFER_SIZE);
}

RaceData PacketRaceData::sRaceData()
{
        return sRaceData_;
}