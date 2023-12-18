#ifndef ASF_LOGGING_LOGSDK_DETAILS_RWMUTEX_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_RWMUTEX_HPP

#include <memory>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

class RWMutexPrivate;

/**
 * \brief Read-Write-Mutex
 */
class RWMutex
{
public:
    RWMutex();
    ~RWMutex();

    void RLock();
    void RUnLock();

    void WLock();
    void WUnLock();

private:
    RWMutex(const RWMutex&) = delete;
    RWMutex& operator=(const RWMutex&) = delete;

private:
    std::unique_ptr<RWMutexPrivate> pri_;
};

/**
 * RAII for read-lock.
 */
template<typename RWLockable>
class ReadLockGuard
{
public:
    ReadLockGuard(RWLockable& rw_lockable) 
        : rw_lockable_(rw_lockable) 
    {
        rw_lockable_.RLock();
    }

    ~ReadLockGuard()
    {
        rw_lockable_.RUnLock();
    }
    
private:
    ReadLockGuard() = delete;
    ReadLockGuard(const ReadLockGuard&) = delete;
    ReadLockGuard& operator=(const ReadLockGuard&) = delete;

private:
    RWLockable& rw_lockable_;
};

/**
 * RAII for write-lock.
 */
template<typename RWLockable>
class WriteLockGuard
{
public:
    WriteLockGuard(RWLockable& rw_lockable) 
        : rw_lockable_(rw_lockable)
    {
        rw_lockable_.WLock();
    }

    ~WriteLockGuard()
    {
        rw_lockable_.WUnLock();
    }

private:
    WriteLockGuard() = delete;
    WriteLockGuard(const WriteLockGuard&) = delete;
    WriteLockGuard& operator=(const WriteLockGuard&) = delete;

private:
    RWLockable& rw_lockable_;
};

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_RWMUTEX_HPP