#include "asf/logging/logsdk/details/rwmutex.hpp"

#if defined(ASF_LOGGING_HAS_PTHREAD)
#  include <pthread.h>
#else
#  include <mutex>
#  include <condition_variable>
#endif

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

#if defined(ASF_LOGGING_LOGSDK_HAS_PTHREAD) && defined(ASF_LOGGING_LOGSDK_USE_PTHREAD_RWLOCK)

/**
 * \brief Read-Write-Mutex wrapper for pthread_rwlock
 */
class RWMutexPrivate
{
public:
    RWMutexPrivate()
    {
        pthread_rwlock_init(&rwlock_, NULL);
    }
    ~RWMutexPrivate()
    {
        pthread_rwlock_destroy(&rwlock_);
    }

    void RLock()
    {
        pthread_rwlock_rdlock(&rwlock_);
    }

    void RUnLock()
    {
        pthread_rwlock_unlock(&rwlock_);
    }

    void WLock()
    {
        pthread_rwlock_wrlock(&rwlock_);
    }

    void WUnLock()
    {
        pthread_rwlock_unlock(&rwlock_);
    }

private:
    RWMutexPrivate(const RWMutexPrivate&) = delete;
    RWMutexPrivate& operator=(const RWMutexPrivate&) = delete;

private:
    pthread_rwlock_t rwlock_;
};

#else

/**
 * \brief Read-Write-Mutex for C++11， write first.
 */
class RWMutexPrivate
{
public:
    RWMutexPrivate() = default;
    ~RWMutexPrivate() = default;

    void RLock()
    {
        std::unique_lock<std::mutex> lock(lock_);
        read_cv_.wait(lock, [=]() -> bool {
            return write_cnt_ == 0;
        });
        ++read_cnt_;
    }

    void RUnLock()
    {
        std::unique_lock<std::mutex> lock(lock_);
        if (--read_cnt_ == 0 && write_cnt_ > 0)
        {
            write_cv_.notify_one();
        }
    }

    void WLock()
    {
        std::unique_lock<std::mutex> lock(lock_);
        ++write_cnt_;
        write_cv_.wait(lock, [=]() -> bool {
            return read_cnt_ == 0 && !in_write_flag_;
        });
        in_write_flag_ = true;
    }

    void WUnLock()
    {
        std::unique_lock<std::mutex> lock(lock_);
        if (--write_cnt_ == 0)
        {
            read_cv_.notify_all();
        }
        else
        {
            write_cv_.notify_one();
        }
        in_write_flag_ = false;
    }

private:
    RWMutexPrivate(const RWMutexPrivate&) = delete;
    RWMutexPrivate& operator=(const RWMutexPrivate&) = delete;

private:
    std::mutex lock_;
    std::condition_variable read_cv_;
    std::condition_variable write_cv_;
    volatile std::size_t read_cnt_{ 0 };
    volatile std::size_t write_cnt_{ 0 };
    volatile bool in_write_flag_{ false };
};

#endif // ASF_LOGGING_HAS_PTHREAD && ASF_LOGGING_USE_PTHREAD_RWLOCK

// ------------------------------------------------

RWMutex::RWMutex()
    : pri_(new RWMutexPrivate())
{ }

RWMutex::~RWMutex()
{ }

void RWMutex::RLock()
{
    pri_->RLock();
}

void RWMutex::RUnLock()
{
    pri_->RUnLock();
}

void RWMutex::WLock()
{
    pri_->WLock();
}

void RWMutex::WUnLock()
{
    pri_->WUnLock();
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf