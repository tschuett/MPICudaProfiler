#include <stdlib.h>


void slurmenvs() {

  getenv("SLURMD_NODENAME");
  getenv("SLURM_PROCID");
  getenv("SLURM_CPUS_ON_NODE");
  getenv("SLURM_GPUS");
}
