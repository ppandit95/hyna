#pragma once

#include "ADKernelValue.h"

class LaplaceYoungSource : public ADKernelValue
{
public:
  static InputParameters validParams();

  LaplaceYoungSource(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
  const Real & _kappa;
};
