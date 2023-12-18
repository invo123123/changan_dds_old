#ifndef ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_IMPL_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_IMPL_HPP

#include <string>
#include <memory>
#include <atomic>

#include "asf/logging/logsdk/logcore/sdk_context.hpp"
#include "asf/logging/logsdk/logcore/stdout_sink.hpp"
#include "asf/logging/logsdk/logcore/size_file_sink.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

/**
 * \brief The implementation class for logger.
 */
class LoggerImpl : public spdlog::logger
{
public:
    using file_sink_t = sinks::size_file_sink_mt;
public:
    /**
     * \brief Construct a new LoggerImpl object with given \a name.
     * If \a name is empty, the logger is invalid.
     */
    explicit LoggerImpl(const std::string& name);
    ~LoggerImpl() override;

    void Initialize(const std::shared_ptr<SdkContext>& context);

    const std::shared_ptr<file_sink_t>& file_sink() const;
    const std::shared_ptr<sinks::stdout_sink_mt>& console_sink() const;

    /**
     * \brief Get the circle log index.
     */
    std::uint8_t& get_log_index();

    /**
     * \brief Format log preffix content to buffer \a dest.
     */
    virtual void format_log_prefix(spdlog::level::level_enum log_level,
        spdlog::memory_buf_t& dest, const std::string& trace_id);

private:
    void initialize_console_sink_(const std::shared_ptr<SdkContext>& context);
    void initialize_file_sink_(const std::shared_ptr<SdkContext>& context);

private:
    LoggerImpl(const LoggerImpl&) = delete;
    LoggerImpl& operator=(const LoggerImpl&) = delete;

private:
    /**
     * The console sink instance used to record log to console.
     */
    std::shared_ptr<sinks::stdout_sink_mt> console_sink_;
    /**
     * The file sink instance used to record log to file.
     */
    std::shared_ptr<file_sink_t> file_sink_;
    /**
     * Circle log index, in range 0-255.
     */
    std::uint8_t log_index_{ 0 };

    std::shared_ptr<details::Configurator> configurator_;
    std::shared_ptr<details::FileCompressor> compressor_;
};

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_IMPL_HPP