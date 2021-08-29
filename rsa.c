#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <gmp.h>
#include "mpi.h"
int main (int argc, char *argv[]){
int rank,size;
unsigned long int i;
int m;
char res [300], sho [300];
MPI_Init(&argc, &argv);
double start = MPI_Wtime();
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size); /* initializing MPI, collecting info about environment*/
mpz_t N;
mpz_t D,S,I,ds,Ss,Se;
mpz_init(D);
mpz_init(S);
mpz_init(Ss);
mpz_init(Se);
mpz_init(ds);
mpz_init(I);
mpz_init_set_str (N, "18400382086761070589", 10);
mpz_sqrt(S,N);
mpz_cdiv_q_ui(ds,S,size); /* divvy up lims for loop! */
mpz_mul_si(Se,ds,rank);
mpz_add(Ss,Se,ds);
if ((mpz_divisible_ui_p(Ss,2)) != 0){
mpz_add_ui(Ss,Ss,1);
}
for (mpz_set(I,Ss);mpz_cmp(I,Se)>0;mpz_sub_ui(I,I,2)) {
m = mpz_divisible_p(N,I);
if ((mpz_divisible_ui_p(I,100000001)) != 0){
mpz_get_str(sho,10,I);
//printf("%s\n",sho);
}
if (m != 0){
mpz_get_str(sho,10,I);
printf("YAY\n%s\n",sho);
mpz_cdiv_q(D,N,I) ;
mpz_get_str(res,10,D);
printf("\n%s\n", res);
double end = MPI_Wtime()-start;
printf("\ntime taken : %f\n",end);
MPI_Finalize(); /* Tell all threads to exit(1)*/
}
}
return 0;
}