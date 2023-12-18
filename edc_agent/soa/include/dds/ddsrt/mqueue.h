/***************************************************************** 
 *
 * PROJECT	: DDS
 * FILE		: mqueue.h
 *
 * DESCRIPTION	: mqueue header
 * COPYRIGHT	: (c) 2020, Quectel 2020
 *
 * VERSION	: 01.03
 * DATE		: 2020-12-16
 * AUTHOR	: Paul
 * HISTORY	: 
 *
******************************************************************/
#ifndef __DDSRT_MQUEUE_H__
#define __DDSRT_MQUEUE_H__
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <errno.h>

/* all the queue use the same config */
#define MQUEUE_QMSG_NUM_MAX      (5)
#define MQUEUE_QMSG_LEN_MAX      (8192)

/* mq send timeout time, it can not exeed 1000ms(1S) */
#define MQUEUE_SEND_TIMEOUT         (10UL)   //unit:s
#define MQUEUE_RCV_TIMEOUT          (1UL)   //unit:s

/**
 * @brief init the mqueue
 * a queue can send msg after it is inited
 *
 * @param name [IN] name of the queue to be opened
 * @param flag [IN] queue open mode flag
 * 
 * @return 
 *   On success, 0 is returned.  On error, -1 is returned. 
 * 
 * @Owner		: Paul
 * @Date&Time	: 2020-12-16	7:21:39 PM
 */
int32_t ddsrt_mq_init(const char *name, mqd_t *mq_fd);


/**
 * @brief mqueue send msg to queue of the name
 * it will timeout after MQUEUE_SEND_TIMEOUT ms
 *
 * @param name [IN] which mqueue to send
 * @param msg [IN] msg to be send
 * @param msg_len [IN] length of the send msg
 * 
 * @return 
 *   On success, 0 is returned.  On error, -1 is returned. 
 * 
 * @Owner		: Paul
 * @Date&Time	: 2020-12-16	9:39:14 PM
 */
int32_t ddsrt_mq_send(const char *name, char *msg, size_t msg_len);


/**
 * @brief mqueue receive interface
 *
 * @param mqfd [IN] which queue fd to receive from
 * @param buf [IN] buffer to save msg receive from queue
 * @param buf_size [IN] buffer size
 *                      buf_size must be greater than or equal to the mq_msgsize attribute of the queue
 * 
 * @return 
 *   return the number of bytes in the received message; on error, -1 is returned. 
 * 
 * @Owner		: Paul
 * @Date&Time	: 2020-12-16	9:45:02 PM
 */
ssize_t ddsrt_mq_receive(mqd_t mqfd, char *buf, size_t buf_size);

/**
 * @brief close mqueue
 *
 * @param mq_fd [IN] mqueue to be closed
 * 
 * @return 
 *   On success, 0 is returned.  On error, -1 is returned. 
 * 
 * @Owner		: Paul
 * @Date&Time	: 2020-12-16	10:13:36 PM
 */
int32_t ddsrt_mq_close(mqd_t mq_fd);

char *ddsrt_mq_cleanpath(char *path);

#endif  //__DDSRT_MQUEUE_H__
