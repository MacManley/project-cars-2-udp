// File: PCars2_UDP.cpp
#include <stdio.h>

#include "PCars2_UDP.h"
#include "PacketParticipantsData.h"
#include "PacketGameStateData.h"
#include "PacketParticipantVehiclesNames.h"
#include "PacketRaceData.h"
#include "PacketTelemetryData.h"
#include "PacketTimingsData.h"
#include "PacketTimingStatsData.h"
#include "PacketVehicleClassNamesData.h"

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

void PCars2_Parser::push(char * recieveBuffer)
{
    PBase* P = new PBase();
    P->push(recieveBuffer);
    switch (P->mPacketType())
    {
        case 0: packetTelemetryData_->push(recieveBuffer);
            break;
        case 1: packetRaceData_->push(recieveBuffer);
            break;
        case 2: packetParticipantData_->push(recieveBuffer);
            break;
        case 3: packetTimingsData_->push(recieveBuffer);
            break;
        case 4: packetGameStateData_->push(recieveBuffer);
            break;
        /*case 5: packetWeatherStateData_->push(recieveBuffer);
            break;*/
        case 6: packetVehicleClassNamesData_->push(recieveBuffer);
            break;
        case 7: packetTimeStatsData_->push(recieveBuffer);
            break;
        case 8: packetParticipantVehicleNamesData_->push(recieveBuffer);
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