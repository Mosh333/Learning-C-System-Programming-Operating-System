#ifndef DIAGMAT_H_   /* Include guard */
#define DIAGMAT_H_

#define N 4

/*Why all but the first dimension in array must have a bound:
diagMat.h:6:21: note: declaration of ‘mat’ as multidimensional array must have bounds for all dimensions except the first
*/
int is_diag_dom(int mat[][N]);


#endif