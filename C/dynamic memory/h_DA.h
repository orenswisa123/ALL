#ifndef DA_T
#define DA_T
typedef struct{
	int* arr;
	int capacity;
	int index;
}DA_t;

DA_t* createDA(int capacity);
int insert(DA_t* da_ptr,int num);
void printDA(DA_t* da_ptr);
void destroyDA(DA_t* da_ptr);

#endif
	
