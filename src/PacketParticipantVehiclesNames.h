// File: PacketParticipantVehicleNamesData.h
#ifndef PACKETPARTICIPANTVEHICLESNAMESDATA_H
#define PACKETPARTICIPANTVEHICLESNAMESDATA_H
#define VEHICLE_NAME_LENGTH_MAX											64
#define CLASS_NAME_LENGTH_MAX											20
#define VEHICLES_PER_PACKET												16
#define CLASSES_SUPPORTED_PER_PACKET									60

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct VehicleInfo {
uint16_t sIndex; // Index
uint32_t sClass; // Vehicle class
char sVName[VEHICLE_NAME_LENGTH_MAX]; // Vehicle name
short paddingC;
};

class   PacketParticipantVehicleNamesData : public PBase {
public:
    PacketParticipantVehicleNamesData();
    virtual ~PacketParticipantVehicleNamesData();
    VehicleInfo sVehicleInfo(int index);
    void push(char*receiveBuffer);
private: 
    VehicleInfo sVehicleInfo_[16];
};

#pragma pack(pop)

#endif 