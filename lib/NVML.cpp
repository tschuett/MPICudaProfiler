#include "NVML.h"
#include "JSON.h"

#include <nvml.h>
#include <stdlib.h>

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

static std::vector<uint64_t> parseDigits(std::string_view VisibleDevices) {
  std::vector<uint64_t> digits;
  if (VisibleDevices.empty())
    return digits;
  if (not std::isdigit(VisibleDevices.front())
    return digits;

  if (std::isdigit(VisibleDevices.front())) {
    // sneak until , or empty
    uint64_t digit;
    while (not VisibleDevices.empty() and
           std::isdigit(VisibleDevices.front())) {

      remove_prefix(1);
    }
  }
}

static void parseCUDAVisibleDevices(std::string_view VisibleDevices) {
  if (VisibleDevices.starts_with("GPU-")) {
  } else if (VisibleDevices.starts_with("MIG-GPU-")) {
  } else {
    // digits
  }
}

void analyzeDevices() {
  unsigned int count = 0;
  int cudaDriverVersion = 0;
  nvmlReturn_t ret;

  ret = nvmlInit_v2();

  Object jsonNVML;

  ret = nvmlSystemGetCudaDriverVersion_v2(&cudaDriverVersion);
  if (ret != NVML_SUCCESS) {
  }

  ret = nvmlDeviceGetCount_v2(&count);
  if (ret != NVML_SUCCESS) {
  }

  std::string visibleDEvices = getenv("CUDA_VISIBLE_DEVICES");
  std::string deviceOrder = getenv("CUDA_DEVICE_ORDER");
  if (deviceOrder == "PCI_BUS_ID") {
  }
  if (deviceOrder == "FASTEST_FIRST") {
  }

  jsonNVML.insert("count", std::make_unique<Number>(count));

  for (unsigned i = 0; i < count; ++i) {
    nvmlDevice_t device;
    ret = nvmlDeviceGetHandleByIndex_v2(i, &device);
    if (ret != NVML_SUCCESS) {
    }

    ret = nvmlDeviceGetCudaComputeCapability(device, &major, &minor);
    if (ret != NVML_SUCCESS) {
    }

    nvmlDeviceArchitecture_t arch;

    ret = nvmlDeviceGetArchitecture(device, &arch);
    if (ret != NVML_SUCCESS) {
    }

    if (arch == NVML_DEVICE_ARCH_HOPPER) {
    }
    if (arch == NVML_DEVICE_ARCH_AMPERE) {
    }
  }

  ret = nvmlShutdown();
}
