// File: PacketRaceData.cpp
#include "PacketRaceData.h"
#include <string.h>

const int RACEDATA_BUFFER_SIZE = 308;

PacketRaceData::PacketRaceData()
: PBase()
{}

PacketRaceData::~PacketRaceData()
{}

void PacketRaceData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, RACEDATA_BUFFER_SIZE);
}

RaceData PacketRaceData::sRaceData()
{
        return sRaceData_;
}