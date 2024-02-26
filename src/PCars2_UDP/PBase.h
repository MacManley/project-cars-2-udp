// File: PBase.h
#ifndef PBASE_H
#define PBASE_H

#include <inttypes.h>

#pragma pack(push, 1)

struct PacketBase
{
    uint32_t mPacketNumber;
    uint32_t mCategoryPacketNumber;
    uint8_t mPartialPacketIndex;
    uint8_t mPartialPacketNumber;
    uint8_t mPacketType;
    uint8_t mPacketVersion;
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
    uint32_t* pointerToFirstElement();
};

#pragma pack(pop)

#endif

