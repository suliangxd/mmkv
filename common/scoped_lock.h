#ifndef MMKV_COMMON_SCOPED_LOCK_H
#define MMKV_COMMON_SCOPED_LOCK_H

namespace mmkv
{
namespace common
{

template <typename T>
class ScopedLock
{
public:
    ScopedLock(T* lock) : mLock(lock)
    {
        assert(mLock);
        Lock();
    }

    ~ScopedLock()
    {
        Unlock();
        mLock = nullptr;
    }

    void Lock()
    {
        if (mLock)
        {
            mLock->Lock();
        }
    }

    bool TryLock()
    {
        if (mLock)
        {
            mLock->TryLock();
        }
    }

    void Unlock()
    {
        if (mLock)
        {
            mLock->Unlock();
        }
    }
private:
    T* mLock;

    ScopedLock(const ScopedLock<T> &other) = delete;
    ScopedLock &operator = (const ScopedLock<T> &other) = delete;
};

}
}

#endif // MMKV_COMMON_SCOPED_LOCK_H