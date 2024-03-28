// File: PacketTelemetryData.cpp
#include "PacketTelemetryData.h"
#include <cstring>

const int TELEMETRY_BUFFER_SIZE = 559;

PacketTelemetryData::PacketTelemetryData()
: PBase()
{}

PacketTelemetryData::~PacketTelemetryData()
{}

void PacketTelemetryData::push(char *receiveBuffer)
{
    std::memcpy(PBase::pointerToFirstElement(), receiveBuffer, TELEMETRY_BUFFER_SIZE);
}

TelemetryData PacketTelemetryData::sTelemetryData()
{
        return sTelemetryData_;
}