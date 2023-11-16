#pragma once

#include <string>
#include <vector>

class CUDAVisibleDevicesParser {
  std::string VisibleDevices;

public:
  CUDAVisibleDevicesParser(std::string_view VisibleDevices)
      : VisibleDevices(VisibleDevices) {}

  void parse();

private:
  std::vector<int> parseDigits();
  void parseMIG();
  void parseGPU();
};
