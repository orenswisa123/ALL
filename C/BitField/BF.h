#ifndef BIT_FIELD
#define BIT_FIELD

typedef struct
{
    unsigned int R : 4;
    unsigned int L : 4;
}lr;

union U
{
    lr LRB;
    char c;
};
int pack(char* c);
int packfield(char* c);
void decToBinary(char c);







#endif