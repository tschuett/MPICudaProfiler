
#include <cstdint>

const uint64_t MIDR_IMPLEMENTOR_SHIFT = 24;
const uint64_t MIDR_VARIANT_SHIFT = 24;
const uint64_t MIDR_ARCHITECTURE_SHIFT = 24;
const uint64_t MIDR_PART_NUM_SHIFT = 4;
const uint64_t MIDR_REVISION_SHIFT = 0;

const uint64_t MIDR_REVISION_MASK = 0xf;
const uint64_t MIDR_PART_NUM_MASK = 0xfff << MIDR_PART_NUM_SHIFT;
const uint64_t MIDR_ARCHITECTURE_MASK = 0xf << MIDR_ARCHITECTURE_SHIFT;
const uint64_t MIDR_VARIANT_MASK = 0xf << MIDR_VARIANT_SHIFT;
const uint64_t MIDR_IMPLEMENTOR_MASK = 0xff << MIDR_IMPLEMENTOR_SHIFT;

uint64_t extract(uint64_t midr, uint64_t shift, uint64_t mask) {
  return (midr >> shift) & mask;
}

#if defined(__APPLE__) && defined(__aarch64__)

#elif defined(__aarch64__)

uint64_t midr = 0;
__asm __volatile("mrs %0, MIDR_EL1" : "=r"(midr));

uint64_t implementer =
    extract(midr, MIDR_IMPLEMENTER_SHIFT, MIDR_IMPLEMENTER_MASK);
uint64_t variant = extract(midr, MIDR_VARIANT_SHIFT, MIDR_VARIANT_MASK);
uint64_t architecture =
    extract(midr, MIDR_ARCHITECTURE_SHIFT, MIDR_ARCHITECTURE_MASK);
uint64_t part_num = extract(midr, MIDR_PART_NUM_SHIFT, MIDR_PART_NUM_MASK);

#endif
