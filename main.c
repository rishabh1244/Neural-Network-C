#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *key;
    char *value;

    struct node *next;
} node;

void setNode(struct node *node, char *key, char *value)
{
    node->key = key;
    node->value = value;
    node->next = NULL;
    return;
}

typedef struct hashMap
{
    int numberOfElements, capacity;
    struct node **arr;
} hashmap;

void init_hashMap(struct hashMap *mp, int capacity)
{
    mp->capacity = capacity;
    mp->numberOfElements = 0;

    mp->arr = (struct node **)malloc(sizeof(struct node *) * mp->capacity);
    return;
}

int hashFunction(struct hashMap *mp, char *key)
{
    int bucketIndex;
    int sum = 0, factor = 31;

    for (int i = 0; i < strlen(key); i++)
    {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        // sum = ((sum % cap) + (((int)key[i]) * factor) % cap) % cap;

        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }

    bucketIndex = sum;
    return bucketIndex;
}

void insert(struct hashMap* mp , char* key , char* value){
    int bucketIndex = hashFunction(mp , key);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key , value);


    //empty index no collision
    if(mp->arr[bucketIndex] == NULL)
    {
        mp->arr[bucketIndex] = newNode;
    }
    //collision
    else{
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}


int main(){

}