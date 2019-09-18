#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void* handle;
    void(*func_lib)(void);

    handle = dlopen("./libN.so",RTLD_LAZY);
    *(void**)(&func_lib)=dlsym(handle,"lib1Func");
    func_lib();
    return 1;
}