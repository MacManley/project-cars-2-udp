// File: PCars2_UDP.cpp
#include <stdio.h>

#include "PCars2_UDP.h"
#include <WiFiUdp.h>
#include "PacketParticipantsData.h"
#include "PacketGameStateData.h"
#include "PacketParticipantVehiclesNames.h"
#include "PacketRaceData.h"
#include "PacketTelemetryData.h"
#include "PacketTimingsData.h"
#include "PacketTimingStatsData.h"
#include "PacketVehicleClassNamesData.h"

constexpr unsigned int localPort = 5606;

WiFiUDP Udp;

PCars2_Parser::PCars2_Parser()
{
    packetTelemetryData_ = new PacketTelemetryData();
    packetRaceData_ = new PacketRaceData();
    packetParticipantData_ = new PacketParticipantsData();
    packetTimingsData_ = new PacketTimingsData();
    packetGameStateData_ = new PacketGameStateData();
    //packetWeatherStateData = new PacketWeatherStateData();
    packetVehicleClassNamesData_ = new PacketVehicleClassNamesData();
    packetTimeStatsData_ = new PacketTimeStatsData();
    packetParticipantVehicleNamesData_ = new PacketParticipantVehicleNamesData();
}

PCars2_Parser::~PCars2_Parser()
{
    delete packetTelemetryData_;
    delete packetRaceData_;
    delete packetParticipantData_;
    delete packetTimingsData_;
    delete packetGameStateData_;
    //delete packetWeatherStateData_;
    delete packetVehicleClassNamesData_;
    delete packetTimeStatsData_;
    delete packetParticipantVehicleNamesData_;
}

void PCars2_Parser::begin(void) {
    Udp.begin(localPort);
}

void PCars2_Parser::read(void) {
    int packetSize = Udp.parsePacket(); 
    if (packetSize) {
        char packetBuffer[packetSize];
        while(Udp.available())
       {
        Udp.read(packetBuffer, packetSize);
       }
       push(packetBuffer);
    }
}

void PCars2_Parser::push(char * receiveBuffer)
{
    PBase* P = new PBase();
    P->push(receiveBuffer);
    switch (P->mPacketType())
    {
        case 0: packetTelemetryData_->push(receiveBuffer);
            break;
        case 1: packetRaceData_->push(receiveBuffer);
            break;
        case 2: packetParticipantData_->push(receiveBuffer);
            break;
        case 3: packetTimingsData_->push(receiveBuffer);
            break;
        case 4: packetGameStateData_->push(receiveBuffer);
            break;
        /*case 5: packetWeatherStateData_->push(receiveBuffer);
            break;*/
        case 6: packetVehicleClassNamesData_->push(receiveBuffer);
            break;
        case 7: packetTimeStatsData_->push(receiveBuffer);
            break;
        case 8: packetParticipantVehicleNamesData_->push(receiveBuffer);
            break;
        default:;
    }
    delete P;
}

PacketTelemetryData* PCars2_Parser::packetTelemetryData(void)
{
    return packetTelemetryData_;
}

PacketRaceData* PCars2_Parser::packetRaceData(void)
{
    return packetRaceData_;
}

PacketParticipantsData* PCars2_Parser::packetParticipantData(void)
{
    return packetParticipantData_;
}

PacketTimingsData* PCars2_Parser::packetTimingsData(void)
{
    return packetTimingsData_;
}

PacketGameStateData* PCars2_Parser::packetGameStateData(void)
{
    return packetGameStateData_;
}

/*PacketWeatherStateData* PCars2_Parser::packetWeatherStateData(void)
{
    return packetWeatherStateData_;
}*/

PacketVehicleClassNamesData* PCars2_Parser::packetVehicleClassNamesData(void)
{
    return packetVehicleClassNamesData_;
}

PacketTimeStatsData* PCars2_Parser::packetTimeStatsData(void)
{
    return packetTimeStatsData_;
}

PacketParticipantVehicleNamesData* PCars2_Parser::packetParticipantVehicleNamesData(void)
{
    return packetParticipantVehicleNamesData_;
}