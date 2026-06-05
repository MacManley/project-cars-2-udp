// File: PacketGameStateData.h
#ifndef PACKETGAMESTATEDATA_H
#define PACKETGAMESTATEDATA_H

#include "PBase.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct GameStateData {
uint16_t mBuildVersionNumber; // Build version number
uint8_t mGameState; // Game state
int8_t sAmbientTemperature; // Ambient temperature
int8_t sTrackTemperature; // Track temperature
uint8_t sRainDensity; // Rain density (RANGE: 0 -> 255)
uint8_t sSnowDensity; // Snow density (RANGE: 0 -> 255) (will be same as sRainDensity on non-snow tracks)
int8_t sWindSpeed; // Wind speed
int8_t sWindDirectionX; // Wind direction in X Direction
int8_t sWindDirectionY; // Wind Direction in Y Direction
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