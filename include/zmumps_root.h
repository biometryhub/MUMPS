!
!  This file is part of MUMPS 5.7.0, released
!  on Tue Apr 23 10:25:09 UTC 2024
!
!
!  Copyright 1991-2024 CERFACS, CNRS, ENS Lyon, INP Toulouse, Inria,
!  Mumps Technologies, University of Bordeaux.
!
!  This version of MUMPS is provided to you free of charge. It is
!  released under the CeCILL-C license 
!  (see doc/CeCILL-C_V1-en.txt, doc/CeCILL-C_V1-fr.txt, and
!  https://cecill.info/licences/Licence_CeCILL-C_V1-en.html)
!
!     This file includes various internal datastructures
!     passed through the main MUMPS structure between successive
!     phases of the solver. The main one is root information for
!     the multifrontal tree.
      TYPE ZMUMPS_ROOT_STRUC
        SEQUENCE
        INTEGER :: MBLOCK, NBLOCK, NPROW, NPCOL
        INTEGER :: MYROW, MYCOL
        INTEGER :: SCHUR_MLOC, SCHUR_NLOC, SCHUR_LLD
        INTEGER :: RHS_NLOC
        INTEGER :: ROOT_SIZE, TOT_ROOT_SIZE
!       descriptor for scalapack
        INTEGER, DIMENSION( 9 ) :: DESCRIPTOR
        INTEGER :: CNTXT_BLACS, LPIV, rootpad0
        INTEGER, DIMENSION(:), POINTER :: RG2L
        INTEGER, DIMENSION(:), POINTER :: IPIV
!       Centralized master of root
        COMPLEX(kind=8), DIMENSION(:), POINTER :: RHS_CNTR_MASTER_ROOT
!       Used to access Schur easily from root structure
        COMPLEX(kind=8), DIMENSION(:), POINTER :: SCHUR_POINTER
!       for try_null_space preprocessing constant only:
        COMPLEX(kind=8), DIMENSION(:), POINTER :: QR_TAU, rootpad1
!       Fwd in facto: 
!           case of scalapack root: to store RHS in 2D block cyclic
!           format compatible with root distribution
        COMPLEX(kind=8), DIMENSION(:,:), POINTER :: RHS_ROOT, rootpad2
!       for try_nullspace preprocessing constant only:
        DOUBLE PRECISION :: QR_RCOND, rootpad3
        LOGICAL :: yes, gridinit_done
!       for SVD on root (#define try_null_space)
        COMPLEX(kind=8), DIMENSION(:,:), POINTER :: SVD_U, SVD_VT
!       for RR on root (#define try_null_space)
        DOUBLE PRECISION, DIMENSION(:), POINTER :: SINGULAR_VALUES
        INTEGER :: NB_SINGULAR_VALUES,rootpad4
!
      END TYPE ZMUMPS_ROOT_STRUC
!     multicore
      TYPE ZMUMPS_L0OMPFAC_T
         SEQUENCE
         COMPLEX(kind=8), POINTER, DIMENSION(:) :: A
         INTEGER(8) :: LA
      END TYPE ZMUMPS_L0OMPFAC_T
