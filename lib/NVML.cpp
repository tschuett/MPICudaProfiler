#include <nvml.h>
#include <stdlib.h>

#include <string>

void foo() {
  unsigned int count = 0;
  int cudaDriverVersion = 0;
  nvmlReturn_t ret;

  ret = nvmlInit_v2();

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

  for (unsigned i = 0; i < count; ++i) {
    nvmlDevice_t device;
    ret = nvmlDeviceGetHandleByIndex_v2(i, &device);
    if (ret != NVML_SUCCESS) {
    }

    ret = nvmlDeviceGetCudaComputeCapability(device, &major, &minor);
    if (ret != NVML_SUCCESS) {
    }

    //    CUdevice cu_device;
    //
    //    ret = cuDeviceGetAttribute(&major_version,
    //                               CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR,
    //                               cu_device);
    //
    //    if (major_version == 6)
    //      "Pascal"
    //      else if (major_version == 7)
    //        "Volta"
    //        else if (major_version == 8)
    //          "Ampere" else if (major_version == 9)
    //            "Hopper"

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
