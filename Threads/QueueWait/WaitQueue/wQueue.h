#ifndef waitQueue_H
#define waitQueue_H

	typedef struct waitQueue* waitQueue;

	waitQueue queueCreate(unsigned int size);
	void* readFromQueue(waitQueue q);
	int writeToQueue(waitQueue q, void* message);
	unsigned int getAmount(waitQueue q);
	int destroyQueue(waitQueue q);
	int setFinished(waitQueue q, int threadsNum);
	int getFinished(waitQueue q);

#endif