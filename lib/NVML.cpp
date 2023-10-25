

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

  for (unsigned i = 0; i < count; ++i) {
    nvmlDevice_t device;
    ret = nvmlDeviceGetHandleByIndex_v2(i, &device);
    if (ret != NVML_SUCCESS) {
    }

    ret = nvmlDeviceGetCudaComputeCapability(device, &major, &minor);
    if (ret != NVML_SUCCESS) {
    }

    CUdevice cu_device;

    ret = cuDeviceGetAttribute(&major_version,
                               CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR,
                               cu_device);

//    if (major_version == 6)
//      "Pascal"
//      else if (major_version == 7)
//        "Volta"
//        else if (major_version == 8)
//          "Ampere" else if (major_version == 9)
//            "Hopper"
  }

  ret = nvmlShutdown();
}
