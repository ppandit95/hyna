[Mesh]
	type = GeneratedMesh
	dim = 2
	nx = 100
	ny = 100
[]

[Variables]
	[u]
	[]
[]

[Kernels]
	[diffusion]
		type = LaplaceYoungDiffusion
		variable = u
	[]
	[source]
		type = LaplaceYoungSource
		variable = u
		kappa = 0.9
	[]
[]
	
[BCs]
	[all]
		type = ADNeumannBC
		variable = u
		value = 0.2
		boundary = "left right top bottom"
	[]
[]

[Executioner]
	type = Steady
[]

[Outputs]
	exodus = true
[]

