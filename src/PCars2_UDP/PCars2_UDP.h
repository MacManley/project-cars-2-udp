// File: PCars2_UDP.h
#ifndef PCARS2_UDP_H
#define PCARS2_UDP_H

#include "PacketParticipantsData.h"
#include "PacketGameStateData.h"
#include "PacketParticipantVehiclesNames.h"
#include "PacketRaceData.h"
#include "PacketTelemetryData.h"
#include "PacketTimingsData.h"
#include "PacketTimingStatsData.h"
#include "PacketVehicleClassNamesData.h"

class PCars2_Parser
{
public:
    PCars2_Parser();
    virtual ~PCars2_Parser();
    void push(char * recieveBuffer);
    PacketTelemetryData* packetTelemetryData(void);
    PacketRaceData* packetRaceData(void);
    PacketParticipantsData* packetParticipantData(void);
    PacketTimingsData* packetTimingsData(void);
    PacketGameStateData* packetGameStateData(void);
    //PacketWeatherStateData* packetWeatherStateData(void);
    PacketVehicleClassNamesData* packetVehicleClassNamesData(void);
    PacketTimeStatsData* packetTimeStatsData(void);
    PacketParticipantVehicleNamesData* packetParticipantVehicleNamesData(void);

private:
    PacketTelemetryData* packetTelemetryData_;
    PacketRaceData* packetRaceData_;
    PacketParticipantsData* packetParticipantData_;
    PacketTimingsData* packetTimingsData_;
    PacketGameStateData* packetGameStateData_;
    //PacketWeatherStateData* packetWeatherStateData(void);
    PacketVehicleClassNamesData* packetVehicleClassNamesData_;
    PacketTimeStatsData* packetTimeStatsData_;
    PacketParticipantVehicleNamesData* packetParticipantVehicleNamesData_;
};

#endif

