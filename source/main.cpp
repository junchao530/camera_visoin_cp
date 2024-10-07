/*

Main function to make calls to the image and the type of processing. 

*/

//include "0functions.hpp"
#include <string.h>
using namespace std;

typedef void (*FuncCall)(Image &im);
typedef void (*FuncCall1)(Image &im,Image &im1);
typedef struct{
    string argValue;
    string PrintValue;
    FuncCall filter;
    FuncCall1 filters;
}imageProcess;


imageProcess lists[] = {
     {"erosion",                 "Doing image erosion\n",                        Erosion,               NULL},      
     {"histogramEquilization",   "Doing histogram equilization on image\n",      histogramEqualization, NULL},    
     {"linearContrast",          "Applying linear contrast operation on image\n",linearContrast,        NULL},    
     {"sobelFilter",             "Applying sobel filter on image\n",             sobelFilter,           NULL},    
     {"prewittFilter",           "Applying prewitt filter on image\n",           prewittFilter,         NULL},    
     {"gaussFilter",             "Applying gauss filter on image\n",             gaussFilter,           NULL},    
     {"smoothingFilter",         "Applying smoothing filter on image\n",         smoothingFilter,       NULL},    
     {"robertFilter",            "Applying robert filter on image\n",            robertFilter,          NULL},    
     {"laplacienConvo",          "Applying laplacien convolution on image\n",    laplacienConvo,        NULL},    
     {"sharpen",                 "Sharpening image\n",                           Sharpen,               NULL},    
     {"edgeDetect",              "Doing edge detection on image\n",              edgeDetect,            NULL},    
     {"Hflip",                   "flip image horizontally\n",                    Hflip,                 NULL},    
     {"Vflip",                   "flip image vertically\n",                      Vflip,                 NULL},    
     {"Rrotate",                 "Rotate image clockwise\n",                     Rrotate,               NULL},    
     {"Lrotate",                 "Rotate image anti-clockwise\n",                Lrotate,               NULL},       
     {"luminance",               "Image luminance: \n",                          Luminance,             NULL},

     {"and",                     "Image1 AND Image2: \n",                        NULL,                  logicAnd},
     {"nand",                    "Image1 NAND Image2: \n",                       NULL,                  logicNand},
     {"or",                      "Image1 OR Image2: \n",                         NULL,                  logicOr},
     {"xor",                     "Image1 XOR Image2: \n",                        NULL,                  logicXor},
     {"sub",                     "Substract Image1 from Image2: \n",             NULL,                  Subtraction},
     {"add",                     "add Image1 to Image2: \n",                     NULL,                  Addition},
     {"merge",                   "merge Image1 to Image2: \n",                   NULL,                  Merge},
};
