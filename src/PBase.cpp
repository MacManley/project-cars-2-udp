// File: PBase.cpp
#include "PBase.h"
#include <inttypes.h>
#include <cstdio>
#include <cstring>

using namespace std;

const int BASE_BUFFER_SIZE = 12;

PBase::PBase()
{
    
}

PBase::~PBase()
{
}

void PBase::push(char *receiveBuffer)
{
    std::memcpy(&m_base, receiveBuffer, BASE_BUFFER_SIZE);
}

uint32_t PBase::mPacketNumber(void) {
    return m_base.mPacketNumber;
}

uint32_t PBase::mCategoryPacketNumber(void) {
    return m_base.mCategoryPacketNumber;
}

uint8_t PBase::mPartialPacketIndex(void) {
    return m_base.mPartialPacketIndex;
}

uint8_t PBase::mPartialPacketNumber(void) {
    return m_base.mPartialPacketNumber;
}

uint8_t PBase::mPacketType(void) {
    return m_base.mPacketType;
}

uint8_t PBase::mPacketVersion(void) {
    return m_base.mPacketVersion;
}

uint32_t* PBase::firstElementPointer(void)
{
    return &m_base.mPacketNumber;
}
