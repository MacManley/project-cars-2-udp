// File: PacketGameStateData.h
#include "PacketGameStateData.h"
#include <string.h>

const int GAMESTATEDATA_BUFFER_SIZE = 24;

PacketGameStateData::PacketGameStateData()
: PBase()
{}

PacketGameStateData::~PacketGameStateData()
{}

void PacketGameStateData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, GAMESTATEDATA_BUFFER_SIZE);
}

GameStateData PacketGameStateData::sGameStateData()
{
        return sGameStateData_;
}