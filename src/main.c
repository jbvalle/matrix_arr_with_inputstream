#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matavg.h"
#include "print2outputfile.h"
#include "print2stdout.h"


int main(void){

    //Input Stream -> Floating Point Values of matrices
    char *input_string = (char*)malloc(1000*sizeof(char));

    int  rows, columns;
    //Initialize input_string with terminator
    for(int i = 0; i < 1000; i++)input_string[i] = '\0';

    //Input - Dimensions & Matrix Values ----------------------------------
    FILE *file_input_stream = fopen("input.txt","r");
    //Read in dimensions
    fscanf(file_input_stream,"%dx%d%*[^\n]\n",&rows,&columns);getc(file_input_stream);

    //Allocate Memory for input and Output Matrix----------------------------
    //Memory allocate the matrice
    float *matrix = (float*)malloc(rows*columns*sizeof(float));
    //Memory allocate averaged matrice
    //Rows and columns reduces by 2
    float *matrix_avrg = (float*)malloc((rows-2)*(columns-2)*sizeof(float));
    //End: Allocate Memory for input and Output Matrix----------------------------

    for(int i = 0; i < rows * columns;i++){

      fscanf(file_input_stream,"%f",&matrix[i]);
    }
    fclose(file_input_stream);
    //End: Input - Dimensions & Matrix Values ----------------------------------


    //Creates averged matrix
    matavg(matrix, matrix_avrg, rows, columns);
    //Prints INPUT, OUTPUT & SUBMATRICES to ./output.txt
    print2outputfile(matrix, matrix_avrg, rows, columns);
    //Prints INPUT, OUTPUT & SUBMATRICES to STDOUT
    print2stdout(matrix, matrix_avrg, rows, columns);
}
