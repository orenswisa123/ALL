#include "memPage_t.h"
#include <string>
#include <stdlib.h>
#include <cstring>
size_t memPage_t::defCapacity = 6;

memPage_t::memPage_t()
{
	capacity = defCapacity;
	buffer = new char[capacity];
}
memPage_t::memPage_t(size_t capa)
{
	capacity = capa;
	buffer = new char[capacity];
}

memPage_t::~memPage_t()
{
	delete[] buffer;
}
bool memPage_t::isMemEmpty() const
{
	if (m_actualSize == 0)
		return true;
	else
		return false;
}
bool memPage_t::isMemFull() const
{
	return m_actualSize == capacity ? true : false;
}
size_t memPage_t::read(void *output, size_t bytes)
{
	/*read(output,bytes,m_currentPosition);*/
	size_t numOfBytes;
	if (output != 0)
	{
		if (getCurrentPosition() + bytes > getactualSize())
		{
			numOfBytes = m_actualSize - m_currentPosition;
			memcpy(output, (void *)(&(buffer[m_currentPosition])), numOfBytes);
			m_currentPosition = m_actualSize;
		}
		else
		{
			numOfBytes = bytes;
			memcpy(output, (void *)(&(buffer[m_currentPosition])), bytes);
			m_currentPosition += bytes;
		}
	}
	return numOfBytes;
}
size_t memPage_t::read(void *output, size_t bytes, size_t pos)
{
	size_t numOfBytes;
	if (output != 0 && pos <= m_actualSize)
	{
		m_currentPosition = pos;
		if (m_currentPosition + bytes > m_actualSize)
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), m_actualSize - m_currentPosition);
			m_currentPosition = m_actualSize;
			numOfBytes = m_actualSize - m_currentPosition;
		}
		else
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), bytes);
			m_currentPosition += bytes;
			numOfBytes = bytes;
		}
	}
	return numOfBytes;
}
size_t memPage_t::write(const void *inputBuffer, size_t bufferSize)
{
	size_t numOfBytes;
	if (m_currentPosition + bufferSize > capacity)
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, capacity - m_currentPosition);
		numOfBytes = capacity - m_currentPosition;
		m_actualSize = capacity;
		m_currentPosition = capacity;
	}
	else
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, bufferSize);
		if (m_actualSize < m_currentPosition + bufferSize)
		{
			m_actualSize = m_currentPosition + bufferSize;
		}
		m_currentPosition += bufferSize;
		numOfBytes = bufferSize;
	}
	return numOfBytes;
}
size_t memPage_t::write(const void *inputBuffer, size_t bufferSize, size_t pos)
{
	if (pos > m_actualSize)
	{
		return 0;
	}
	size_t numOfBytes;
	m_currentPosition = pos;
	if (m_currentPosition + bufferSize > capacity)
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, capacity - m_currentPosition);
		numOfBytes = capacity - m_currentPosition;
		m_actualSize = capacity;
		m_currentPosition = capacity;
	}
	else
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, bufferSize);
		if (m_actualSize < m_currentPosition + bufferSize)
		{
			m_actualSize = m_currentPosition + bufferSize;
		}
		m_currentPosition += bufferSize;
		numOfBytes = bufferSize;
	}
	return numOfBytes;
}