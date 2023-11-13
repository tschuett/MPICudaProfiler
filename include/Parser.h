#pragma once

#include <string>

class CUDAVisibleDevicesParser {
  std::string VisibleDevices;

public:
  CUDAVisibleDevicesParser(std::string_view VisibleDevices)
      : VisibleDevices(VisibleDevices) {}

  void parse();

private:
  void parseDigits();
  void parseMIG();
  void parseGPU();
};
