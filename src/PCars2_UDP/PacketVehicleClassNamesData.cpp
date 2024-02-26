// File: PacketGameStateData.h
#include "PacketVehicleClassNamesData.h"
#include <string.h>

const int VEHICLECLASSNAMES_BUFFER_SIZE = 1452;

PacketVehicleClassNamesData::PacketVehicleClassNamesData()
: PBase()
{}

PacketVehicleClassNamesData::~PacketVehicleClassNamesData()
{}

void PacketVehicleClassNamesData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, VEHICLECLASSNAMES_BUFFER_SIZE);
}

ClassInfo PacketVehicleClassNamesData::sVehicleClassNames(int index)
{
        if (index >= 0 && index < 22)
            return sVehicleClassNames_[index];
        else return{0};
}