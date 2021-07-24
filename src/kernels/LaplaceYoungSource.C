#include "LaplaceYoungSource.h"

registerMooseObject("MooseApp", LaplaceYoungSource);

InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelValue::validParams();
  params.addParam<Real>("kappa",1,"Coefficient to the laplace Young Equation source term");
  params.addClassDescription("Source contribution in Laplace Young Equation");
  return params;
}

LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters) : ADKernelValue(parameters),
_kappa(getParam<Real>("kappa"))
{}

ADReal
LaplaceYoungSource::precomputeQpResidual()
{
  
  return _kappa * _u[_qp];
}
