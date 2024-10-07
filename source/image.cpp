/*
Image CPP file which allows us to get the image and gather the individual pixels for transformations
*/

#include "image.h"
#include  <stdlib.h>
//#include "Functions.h"
using namespace std;


Image::Image(){
    rows = 0;
    cols = 0;
    depth = 0;
    pixelVal = NULL;
    pixelVal3 = NULL;
}
//for allocating photo into memory and pointing to it
Image::Image(int numRows, int numCols, int Ndepth){
    rows        = numRows;
    cols        = numCols;
    depth       = Ndepth;
    pixelVal    = new int*[rows];
    pixelVal3   = new int**[rows];

    for(int i = 0; i < rows; i++){
        pixelVal[i] = new int[cols];
        for (int j =0; j < cols; j++){
            pixelVal[i][j] =0;
        }
    }

    for (int i = 0; i < rows; i++){
        pixelVal3[i] = new int*[cols];
        for(int j = 0; j < cols; j++){
            pixelVal3[i][j] = new int[depth];
            for (int k =0; k < depth; k++){
                pixelVal3[i][j][k] =0;
            }
        }
    }
}

//Destrucutr for deallocating the memory
Image:: ~Image(){
    for(int i = 0; i< rows; i++)
        delete pixelVal[i];

    for (int i = 0; i <rows; i++){
        for (int j = 0; j <cols; j++){
            delete pixelVal3[i][j];
        }delete pixelVal3[i];
    }
    rows = 0;
    cols = 0;
    depth = 0;
    delete pixelVal;
    delete pixelVal3;
}

//Functions for getting or setting pixel values
int Image::getPixelVal(int row, int col){
    return pixelVal[row][col];
}

void Image::setPixelVal(int row, int col, int value){
    pixelVal[row][col] = value;
}

int Image::getPixelVal3(int row, int col, int depth){
    return pixelVal3[row][col][depth];
}

void Image::setPixelVal3(int row, int col, int value, int depth){
    pixelVal3[row][col][depth]= value;
}