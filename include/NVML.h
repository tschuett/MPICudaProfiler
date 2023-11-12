#pragma once

#ifdef HAVE_CUDA
extern void analyzeDevices();
#else
void analyzeDevices() {}
#endif
