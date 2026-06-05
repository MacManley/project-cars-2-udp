// File: PBase.h
#ifndef PBASE_H
#define PBASE_H

#include <inttypes.h>

#pragma pack(push, 1)

struct PacketBase
{
    uint32_t mPacketNumber; //Number reflecting how many packets have been sent while game is running
    uint32_t mCategoryPacketNumber; //Number reflecting how many packets have been sent while game is running from a specific category
    uint8_t mPartialPacketIndex; // If the data from this class has been sent in several packets, the index number of them packets
    uint8_t mPartialPacketNumber; // If the data from this class has been sent in several packets, the amount of the packets
    uint8_t mPacketType; // Which type of packet it is
    uint8_t mPacketVersion; // What version of the packet it is
};

using namespace std;

class PBase
{
public:
    PBase();
    virtual ~PBase();
    uint32_t mPacketNumber(void);
    uint32_t mCategoryPacketNumber(void);
    uint8_t mPartialPacketIndex(void);
    uint8_t mPartialPacketNumber(void);
    uint8_t mPacketType(void);
    uint8_t mPacketVersion(void);
    void push(char *receiveBuffer);

protected:
    PacketBase m_base;
    uint32_t* firstElementPointer();
};

#pragma pack(pop)

#endif

