#include "PacketParticipantVehiclesNames.h"
#include <inttypes.h>
#include <string.h>

const int PARTICIPANTVEHICLENAMES_BUFFER_SIZE = 1164;

PacketParticipantVehicleNamesData::PacketParticipantVehicleNamesData()
: PBase()
{}

PacketParticipantVehicleNamesData::~PacketParticipantVehicleNamesData(void)
{}

void PacketParticipantVehicleNamesData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, PARTICIPANTVEHICLENAMES_BUFFER_SIZE);
}

VehicleInfo PacketParticipantVehicleNamesData::sVehicleInfo(int index)
{
        if (index >= 0 && index < 16)
            return sVehicleInfo_[index];
        else return{0};
}