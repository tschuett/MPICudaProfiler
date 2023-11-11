#include "Entry.h"

#include NVML.h "

void startProfiler() {
#idef HAVE_CUDA
  analyzeDevices();
#endif
}

void stopProfiler() {}
