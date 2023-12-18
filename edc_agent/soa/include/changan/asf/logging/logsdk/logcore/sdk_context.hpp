#ifndef ASF_LOGGING_LOGSDK_LOGCORE_SDK_CONTEXT_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_SDK_CONTEXT_HPP

#include <memory>

#include "asf/logging/logsdk/details/loglog.hpp"

#include "asf/logging/logsdk/details/configurator.hpp"
#include "asf/logging/logsdk/details/file_compressor.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

/**
 * The context of asf_logsdk. Represents the resources required for SDK operation.
 */
struct SdkContext
{
    /// Configurator instance for load configuration.
    std::shared_ptr<details::Configurator> configurator;
    /// Compressor for compressing log file.
    std::shared_ptr<details::FileCompressor> file_compressor;
};

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_SDK_CONTEXT_HPP