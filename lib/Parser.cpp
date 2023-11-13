#include "Parser.h"

#include <string
#include <string_view>

void CUDAVisibleDevicesParser::parse() {
  if (VisibleDevices.starts_with("GPU-")) {
    parseGPU();
    return;
  } else if (VisibleDevices.starts_with("MIG-GPU-")) {
    parseMIG();
    return;
  }
  parseDigits();
}

void CUDAVisibleDevicesParser::parseDigits() {
  std::string_view data = VisibleDevices;
  std::vector<int> ids;

  std::string_view::size_type pos = data.find_first_of(',');

  while (pos != std::string_view::npos) {
    std::string_view digit = data.substr(0, npos - 1);

    int id = std::stoi(digit);
    ids.push_back(id);

    data = data.remove_prefix(digit);
    data = data.remove_prefix(",");

    pos = data.find_first_of(',');
  }
}
