/*
 *
 *  This file is part of MUMPS 5.3.3, released
 *  on Mon Jun 15 09:57:25 UTC 2020
 *
 *
 *  Copyright 1991-2020 CERFACS, CNRS, ENS Lyon, INP Toulouse, Inria,
 *  Mumps Technologies, University of Bordeaux.
 *
 *  This version of MUMPS is provided to you free of charge. It is
 *  released under the CeCILL-C license:
 *  https://cecill.info/licences/Licence_CeCILL-C_V1-en.html
 *
 */
#include<stdio.h>
int main()
{
printf("#if ! defined(MUMPS_INT_H)\n");
printf("#   define MUMPS_INT_H\n");
#if defined(INTSIZE64)
printf("#   define MUMPS_INTSIZE64\n");
#else
printf("#   define MUMPS_INTSIZE32\n");
#endif
printf("#endif\n");
return 0;
}
