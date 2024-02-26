#include "PacketTimingsData.h"
#include <inttypes.h>
#include <string.h>

const int TIMINGS_BUFFER_SIZE = 1063;

PacketTimingsData::PacketTimingsData()
: PBase()
{}

PacketTimingsData::~PacketTimingsData(void)
{}

void PacketTimingsData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, TIMINGS_BUFFER_SIZE);
}

int8_t PacketTimingsData::sNumParticipants(void) 
{
    return sNumParticipants_;
}

uint32_t PacketTimingsData::sParticipantsChangedTimeStamp2(void) 
{
    return sParticipantsChangedTimeStamp2_;
}

float PacketTimingsData::sEventTimeRemaining(void) 
{
    return sEventTimeRemaining_;
}

float PacketTimingsData::sSplitTimeAhead(void) 
{
    return sSplitTimeAhead_;
}

float PacketTimingsData::sSplitTimeBehind(void) 
{
    return sSplitTimeBehind_;
}

float PacketTimingsData::sSplitTime(void) 
{
    return sSplitTime_;
}

ParticipantsInfo PacketTimingsData::sParticipantInfo(int index)
{
        if (index >= 0 && index < 32)
            return sParticipantsInfo_[index];
        else return{0};
}

uint16_t PacketTimingsData::sLocalParticipantIndex(void) 
{
    return sLocalParticipantIndex_;
}

uint32_t PacketTimingsData::sTickCount(void) 
{
    return TickCount_;
}