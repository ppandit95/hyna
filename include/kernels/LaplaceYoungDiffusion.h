#pragma once

#include "ADKernelGrad.h"

class LaplaceYoungDiffusion : public ADKernelGrad
{
public:
  static InputParameters validParams();

  LaplaceYoungDiffusion(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
};
