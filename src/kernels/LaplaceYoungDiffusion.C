#include "LaplaceYoungDiffusion.h"

registerMooseObject("HynaMooseApp", LaplaceYoungDiffusion);

InputParameters
LaplaceYoungDiffusion::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription("Diffusion contribution for Laplace Young Equation");
  return params;
}

LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters) : ADKernelGrad(parameters) {}

ADRealVectorValue
LaplaceYoungDiffusion::precomputeQpResidual()
{
  ADReal k = 1./std::sqrt(1 + _grad_u[_qp]*_grad_u[_qp]);
  return k * _grad_u[_qp];
}
