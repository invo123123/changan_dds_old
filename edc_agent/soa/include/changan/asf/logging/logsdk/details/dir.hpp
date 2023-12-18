#ifndef ASF_LOGGING_LOGSDK_DETAILS_DIR_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_DIR_HPP

#include <vector>
#include <list>
#include <string>
#include <functional>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {
namespace dir {

/**
 * \brief List file names of a directory, not recursive.
 * 
 * \param folder The folder where to search in
 * \param filter filter the file. if nullptr, do not filter.
 * \param loop_predicate If returns false, exit early.
 * \return The output files list. If full_path is false, just file name; otherwise full path.
 * 
 * \note Returns empty if the loop is canceled
 */
std::vector<std::string> ListFileNames(const std::string& folder, bool full_path,
    const std::function<bool(const std::string&)>& filter = nullptr, 
    const std::function<bool()>& loop_predicate = nullptr);

} // namespace dir
} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_DIR_HPP
