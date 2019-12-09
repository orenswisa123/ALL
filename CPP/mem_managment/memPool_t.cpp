#include "memPool_t.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

bool memPool_t::isMemEmpty() const
{
    if (v.size() == 0 || v.size() == 1 && v[0]->getactualSize() == 0)
        return true;
    else
        return false;
}
size_t memPool_t::read(void *buffer, size_t size)
{
    return read(buffer, size, m_currentPosition);
}

size_t memPool_t::read(void *buffer, size_t size, size_t pos)
{
    if (buffer == 0 || size == 0)
    {
        return 0;
    }

    setCurrentPosition(pos);
    size_t pageIndex = m_currentPosition / pageSize;
    size_t tempSize, readCount, buffPos = 0;

    if (size > (m_actualSize - m_currentPosition))
    {
        size = m_actualSize - m_currentPosition;
    }
    tempSize = size;

    while (true)
    {
        v[pageIndex]->setCurrentPosition(m_currentPosition % pageSize);
        readCount = v[pageIndex]->read((char *)buffer + buffPos, tempSize);
        setCurrentPosition(m_currentPosition + readCount);

        if (readCount != tempSize)
        {
            tempSize -= readCount;
            buffPos += readCount;
            pageIndex++;
        }
        else
        {
            break;
        }
    }

    return size;
}

size_t memPool_t::write(const void *buffer, size_t size)
{
    return write(buffer, size, m_currentPosition);
}

size_t memPool_t::write(const void *buffer, size_t size, size_t pos)
{
    if (buffer == 0 || size == 0)
    {
        return 0;
    }

    setCurrentPosition(pos);
    size_t pageIndex = m_currentPosition / pageSize;
    size_t writeCount, buffPos = 0, tempSize = size;

    while (true)
    {
        v[pageIndex]->setCurrentPosition(m_currentPosition % pageSize);
        writeCount = v[pageIndex]->write((char *)buffer + buffPos, tempSize);
        setactualSize(writeCount);
        setCurrentPosition(m_currentPosition + writeCount);

        if (writeCount != tempSize)
        {
            memPage_t *pg = new memPage_t(pageSize);
            v.push_back(pg);

            tempSize -= writeCount;
            buffPos += writeCount;
            pageIndex++;
        }
        else
        {
            break;
        }
    }

    return size;
}