// File: PacketVehicleClassNamesData.h
#ifndef PACKETVEHICLECLASSNAMESDATA_H
#define PACKETVEHICLECLASSNAMESDATA_H
#define CLASS_NAME_LENGTH_MAX 20
#define CLASSES_SUPPORTED_PER_PACKET 60

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct ClassInfo {
    uint32_t sClassIndex; // Index of class
    char sCName[CLASS_NAME_LENGTH_MAX]; // Class name
};

class PacketVehicleClassNamesData: public PBase {
public: 
    PacketVehicleClassNamesData();
    virtual ~PacketVehicleClassNamesData();
    ClassInfo sVehicleClassNames(int index);
    void push(char*receiveBuffer);
private: 
    ClassInfo sVehicleClassNames_[60];
};

#pragma pack(pop)

#endif 