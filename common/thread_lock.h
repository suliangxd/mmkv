#ifndef MMKV_COMMON_THREAD_LOCK_H
#define MMKV_COMMON_THREAD_LOCK_H

#include <pthread.h>

namespace mmkv
{
namespace common
{
class ThreadLock
{
public:
    ThreadLock();
    ~ThreadLock();

    void Lock();
    bool TryLock();
    void UnLock();

private:
    pthread_mutex_t mLock;
};

}
}
#endif // MMKV_COMMON_THREAD_LOCK_H

