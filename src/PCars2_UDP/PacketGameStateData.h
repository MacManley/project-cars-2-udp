// File: PacketGameStateData.h
#ifndef PACKETGAMESTATEDATA_H
#define PACKETGAMESTATEDATA_H

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct GameStateData {
uint16_t mBuildVersionNumber;
char mGameState;
int8_t sAmbientTemperature;
int8_t sTrackTemperature;
uint8_t sRainDensity;
uint8_t sSnowDensity;
int8_t sWindSpeed;
int8_t sWindDirectionX;
int8_t sWindDirectionY;
short paddingD;
};

class PacketGameStateData: public PBase {
public:
    PacketGameStateData();
    virtual ~PacketGameStateData();
    GameStateData sGameStateData(void);
    void push(char*receiveBuffer);
private:
    GameStateData sGameStateData_;
};

#pragma pack(pop)

#endif 