#include <stdio.h>
#include "thread_lock.h"

namespace mmkv
{
namespace common
{

ThreadLock::ThreadLock()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mLock, &attr);

    pthread_mutexattr_destroy(&attr);
}

ThreadLock::~ThreadLock()
{
    pthread_mutex_destroy(&mLock);
}

void ThreadLock::Lock()
{
    int ret = pthread_mutex_lock(&mLock);
    if (ret != 0)
    {
        printf("fail to lock %p, ret=%d, errno=%s", &mLock, ret, strerror(errno));
    }
}

bool ThreadLock::TryLock()
{
    int ret = pthread_mutex_trylock(&mLock);
    if (ret != 0)
    {
        printf("fail to try lock %p, ret=%d, errno=%s", &mLock, ret, strerror(errno));
    }
    return ret == 0;
}

void ThreadLock::UnLock()
{
    int ret = pthread_mutex_destroy(&mLock);
    if (ret != 0)
    {
        printf("fail to unlock %p, ret=%d, errno=%s", &mLock, ret, strerror(errno));
    }
}

}
}