#ifndef BIT_H
#define BIT_H

typedef struct
{
  int m_NumberFitcher;
  int *m_arr; 
}BitMap;
typedef int (*BitFunc)(BitMap *BM,int n) ;


BitMap* Create_BM(int NumberFitcher);
int BitOn(BitMap *BM,int n);
int BitOff(BitMap *BM,int n);
int BitStat(BitMap *BM,int n);
void destroy (BitMap *B1);
void toBinari(int v);
int calculate(BitFunc f,BitMap* BM,int n);


#endif
