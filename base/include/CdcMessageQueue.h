/*
 * Copyright (c) 2007-2020 Allwinnertech Co., Ltd.
 *
 * This software is licensed under the terms of the GNU Lesser General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * CedarC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 */

/*
 *
 * File : CdxMessageQueue.h
 * Description : message queue
 * History :
 *
 */

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <stdint.h>
#include <semaphore.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MessageQueueContext CdcMessageQueue;

#ifndef uintptr_t
typedef size_t uintptr_t;
#endif

//typedef void (*msgHandlerT)(CdcMessage *msg, void *arg);

typedef struct CdcMessage {
    int          messageId;
    uintptr_t    params[4];
  //  msgHandlerT  execute;
}CdcMessage;

/**
 * @param nMaxMessageNum How many messages the message queue can hold
 * @param pName The name of the message queue which is used in log output
 * @param nMessageSize sizeof(struct AwMessage)
 */
CdcMessageQueue* CdcMessageQueueCreate(int nMaxMessageNum, const char* pName);

void CdcMessageQueueDestroy(CdcMessageQueue* mq);

int CdcMessageQueuePostMessage(CdcMessageQueue* mq, CdcMessage* m);

int CdcMessageQueueWaitMessage(CdcMessageQueue* mq, int64_t timeout);

int CdcMessageQueueGetMessage(CdcMessageQueue* mq, CdcMessage* m);

int CdcMessageQueueTryGetMessage(CdcMessageQueue* mq, CdcMessage* m, int64_t timeout);

int CdcMessageQueueFlush(CdcMessageQueue* mq);

int CdcMessageQueueGetCount(CdcMessageQueue* mq);

//* define a semaphore timedwait method for common use.
int SemTimedWait(sem_t* sem, int64_t time_ms);

#ifdef __cplusplus
}
#endif

#endif
