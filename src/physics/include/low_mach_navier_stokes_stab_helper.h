//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2012 The PECOS Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the Version 2 GNU General
// Public License as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301 USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifndef LOW_MACH_NAVIER_STOKES_STAB_HELPER_H
#define LOW_MACH_NAVIER_STOKES_STAB_HELPER_H

// GRINS
#include "inc_navier_stokes_stab_helper.h"

namespace GRINS
{
  class LowMachNavierStokesStabilizationHelper : public IncompressibleNavierStokesStabilizationHelper
  {
  public:

    LowMachNavierStokesStabilizationHelper( const GetPot& input );

    ~LowMachNavierStokesStabilizationHelper();

    libMesh::Real compute_tau_energy( libMesh::FEMContext& c,
				      unsigned int qp,
				      libMesh::RealGradient& g,
				      libMesh::RealTensor& G,
				      libMesh::Real rho,
				      libMesh::Gradient U,
				      libMesh::Real k,
				      libMesh::Real cp,
				      bool is_steady ) const;

  }; // class LowMachNavierStokesStabilizationHelper

  /* ------------- Inline Functions ---------------*/
  inline
  libMesh::Real LowMachNavierStokesStabilizationHelper::compute_tau_energy( libMesh::FEMContext& c,
									    unsigned int qp,
									    libMesh::RealGradient& g,
									    libMesh::RealTensor& G,
									    libMesh::Real rho,
									    libMesh::Gradient U,
									    libMesh::Real k,
									    libMesh::Real cp,
									    bool is_steady ) const
  {
    return this->compute_tau( c, qp, k*k, g, G, rho*cp, U, is_steady );
  }
  
}
#endif // LOW_MACH_NAVIER_STOKES_STAB_HELPER_H