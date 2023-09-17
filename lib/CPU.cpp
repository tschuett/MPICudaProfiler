
const MIDR_IMPLEMENTOR_SHIFT: u64 = 24;
const MIDR_VARIANT_SHIFT: u64 = 24;
const MIDR_ARCHITECTURE_SHIFT: u64 = 24;
const MIDR_PART_NUM_SHIFT: u64 = 4;
const MIDR_REVISION_SHIFT: u64 = 0;

const MIDR_REVISION_MASK: u64 = 0xf;
const MIDR_PART_NUM_MASK: u64 = 0xfff << MIDR_PART_NUM_SHIFT;
const MIDR_ARCHITECTURE_MASK: u64 = 0xf << MIDR_ARCHITECTURE_SHIFT;
const MIDR_VARIANT_MASK: u64 = 0xf << MIDR_VARIANT_SHIFT;
const MIDR_IMPLEMENTOR_MASK: u64 = 0xff << MIDR_IMPLEMENTOR_SHIFT;

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
