#ifndef _THREAD_CONFIG_H_
#define _THREAD_CONFIG_H_

#include <ultra64.h>
#include <PR/os.h>


#define RMON_THREAD_ID   (OSId)0
#define IDLE_THREAD_ID   (OSId)1
#define SCHED_THREAD_ID  (OSId)2
#define MAIN_THREAD_ID   (OSId)3
#define AUDI_THREAD_ID   (OSId)4
#define TLB_THREAD_ID    (OSId)5

#define IDLE_THREAD_PRIORITY  (OSPri)0
#define MAIN_THREAD_PRIORITY  (OSPri)10
#define AUDI_THREAD_PRIORITY  (OSPri)20
#define SCHED_THREAD_PRIORITY (OSPri)30
#define TLB_THREAD_PRIORITY   (OSPri)40
#define RMON_THREAD_PRIORITY  (OSPri)250

#endif
