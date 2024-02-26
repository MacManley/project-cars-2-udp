// File: PacketMotionData.cpp
#include "PacketTelemetryData.h"
#include <string.h>

const int TELEMETRY_BUFFER_SIZE = 559;

PacketTelemetryData::PacketTelemetryData()
: PBase()
{}

PacketTelemetryData::~PacketTelemetryData()
{}

void PacketTelemetryData::push(char *receiveBuffer)
{
    memmove(PBase::pointerToFirstElement(), receiveBuffer, TELEMETRY_BUFFER_SIZE);
}

TelemetryData PacketTelemetryData::sTelemetryData()
{
        return sTelemetryData_;
}