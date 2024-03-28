// File: PacketGameStateData.cpp
#include "PacketGameStateData.h"
#include <cstring>

const int GAMESTATEDATA_BUFFER_SIZE = 24;

PacketGameStateData::PacketGameStateData()
: PBase()
{}

PacketGameStateData::~PacketGameStateData()
{}

void PacketGameStateData::push(char *receiveBuffer)
{
    std::memcpy(PBase::pointerToFirstElement(), receiveBuffer, GAMESTATEDATA_BUFFER_SIZE);
}

GameStateData PacketGameStateData::sGameStateData()
{
        return sGameStateData_;
}