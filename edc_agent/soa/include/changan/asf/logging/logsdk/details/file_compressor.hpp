#ifndef ASF_LOGGING_LOGSDK_DETAILS_FILE_COMPRESSOR_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_FILE_COMPRESSOR_HPP

#include <string>
#include <memory>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

class FileCompressorPrivate;

/**
 * \brief The FileCompressor class used to compress file.
 */
class FileCompressor
{
public:
    explicit FileCompressor(size_t max_log_files);
    ~FileCompressor();

    /**
     * \brief Compress source file synchronously.
     * 
     * The target file is \a source_file + ".gz".
     * 
     * If Success, the source file will be deleted.
     * Otherwise, the source file will be retained.
     */
    static bool Compress(const std::string& source_file);

    /**
     * \brief Compress source file asynchronously.
     * 
     * The target file is \a source_file + ".gz".
     * 
     * If Success, the source file will be deleted.
     * Otherwise, the source file will be retained.
     */
    void AsyncCompress(std::string&& source_file);
    void AsyncCompress(const std::string& source_file);

private:
    FileCompressor(const FileCompressor&) = delete;
    FileCompressor& operator=(const FileCompressor&) = delete;
    
private:
    std::unique_ptr<FileCompressorPrivate> pri_;
};

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_FILE_COMPRESSOR_HPP