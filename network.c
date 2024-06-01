#include "layer.h"

int init_network(Neural_Network *network, int *layer_array, const int size)
{

    for (int i = 0; i < size; i++)
    {
        network->layers = ((Layer *)malloc((size) * sizeof(Layer)));
    }
    for (int i = 0; i < size; i++)
    {
        network->layers[i].network_input = (Matrix *)malloc(sizeof(Matrix));
    }
    init_matrix(network->layers[0].network_input, layer_array[0], 1);
    // size = 3
    for (int i = 0; i < size; i++)
    {
        printf("size %d", size);
        (network->layers[i]).network_weight = (Matrix *)malloc(sizeof(Matrix));
        init_weight((network->layers[i]).network_weight, layer_array[i + 1], layer_array[i]);
    }

    return size;
}

int feedForward(Neural_Network *network, Matrix *input, int layer_no, int size)
{
    if (layer_no == 0)
    {
        network->layers[0].network_input = input;
    }
    dot_product(network->layers[layer_no].network_weight, network->layers[layer_no].network_input, network->layers[layer_no + 1].network_input);
    layer_no++;

    if (layer_no != size - 1)
    {
        return feedForward(network, input, layer_no, size);
    }

    return 0;
}
void network_log(Neural_Network *network,int size){
    for (int i = 0; i < size - 1; i++)
    {
        printf("layer weight :%d \n", i);
        view((network->layers[i]).network_weight);
    }
    for (int i = 0; i < size; i++)
    {
        printf("input :%d \n", i);
        view((network->layers[i]).network_input);
    }
}


//sample neural netwrork ;
int main()
{
    int x[4] = {50, 50,1, 11};
    int size = sizeof(x) / sizeof(int);

    srand(time(NULL));
    Neural_Network *network = (Neural_Network *)malloc(sizeof(Neural_Network));

    Matrix input;
    init_weight(&input, x[0], 1);

    init_network(network, x, size);
    feedForward(network, &input, 0, size);

    network_log(network ,size);

    printf("FINAL OUTPUT : \n");
    view((network->layers[size-1]).network_input);



    free(network);
}
