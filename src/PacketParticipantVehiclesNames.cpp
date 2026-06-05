// File: PacketParticipantVehiclesNames.cpp
#include "PacketParticipantVehiclesNames.h"
#include <inttypes.h>
#include <cstring>

const int PARTICIPANTVEHICLENAMES_BUFFER_SIZE = 1164;

PacketParticipantVehicleNamesData::PacketParticipantVehicleNamesData()
: PBase()
{}

PacketParticipantVehicleNamesData::~PacketParticipantVehicleNamesData(void)
{}

void PacketParticipantVehicleNamesData::push(char *receiveBuffer)
{
    std::memcpy(PBase::firstElementPointer(), receiveBuffer, PARTICIPANTVEHICLENAMES_BUFFER_SIZE);
}

VehicleInfo PacketParticipantVehicleNamesData::sVehicleInfo(int index)
{
        if (index >= 0 && index < 16)
            return sVehicleInfo_[index];
        else return VehicleInfo{};
}