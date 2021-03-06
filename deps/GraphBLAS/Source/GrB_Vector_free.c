//------------------------------------------------------------------------------
// GrB_Vector_free: free a sparse vector
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2019, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// free all the content of a vector.  After GrB_Vector_free (&v), v is set
// to NULL

// not parallel: this function does O(1) work and is already thread-safe.

#include "GB.h"

GrB_Info GrB_Vector_free    // free a vector
(
    GrB_Vector *v           // handle of vector to free
)
{ 

    GB_VECTOR_FREE (v) ;
    return (GrB_SUCCESS) ;
}

