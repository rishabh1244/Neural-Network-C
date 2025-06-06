#include "matrix.h"

typedef struct
{
    int layer_type; // -1 = input ; 0 = hidden ; 1 = output
    Matrix *network_weight;
    Matrix *network_input;

} Layer;

typedef struct
{
    Layer *layers;

} Neural_Network;
