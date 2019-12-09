#include "memManager_t.h"
#include <iostream>

memManager_t::memManager_t()
{
    m_currentPosition = 0;
    m_actualSize = 0;
}
void memManager_t::setCurrentPosition(size_t newCur)
{
    if (newCur > m_actualSize)
    {
        m_currentPosition = m_actualSize;
    }
    else
    {
        m_currentPosition = newCur;
    }
}
void memManager_t::setactualSize(size_t newSize)
{
    m_actualSize=newSize;
}