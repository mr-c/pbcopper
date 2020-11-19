#ifndef PBCOPPER_ALIGN_EDLIBALIGN_H
#define PBCOPPER_ALIGN_EDLIBALIGN_H

#include <pbcopper/PbcopperConfig.h>

#include <string>
#include <vector>

#include <pbcopper/data/Cigar.h>
#include <pbcopper/third-party/edlib.h>

namespace PacBio {
namespace Align {

///
/// RAII wrapper around edlib's alignment result
///
struct EdlibAlignment
{
    EdlibAlignment(EdlibAlignResult aln);
    ~EdlibAlignment();
    EdlibAlignResult Data;
};

///
/// Align query to target
///
EdlibAlignment EdlibAlign(const std::string& query, const std::string& target,
                          const EdlibAlignConfig& config);
EdlibAlignment EdlibAlign(const char* query, const int queryLength, const char* target,
                          const int targetLength, const EdlibAlignConfig& config);

///
/// Align queries to target
///
std::vector<EdlibAlignment> EdlibAlign(const std::vector<std::string>& queries,
                                       const std::string& target, const EdlibAlignConfig& config);

///
/// Convert edlib alignment result to CIGAR
///
Data::Cigar EdlibAlignmentToCigar(const EdlibAlignment& alignment);
Data::Cigar EdlibAlignmentToCigar(const unsigned char* alignment, int32_t alignmentLength);

}  // namespace Align
}  // namespace PacBio

#endif  // PBCOPPER_ALIGN_EDLIBALIGN_H
