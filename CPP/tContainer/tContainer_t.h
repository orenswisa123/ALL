#include <vector>
#include <list>
#include <algorithm>
#include <string>

template <class T, class C>
class tContainer_t
{
public:
    tContainer_t();
    virtual ~tContainer_t();
    bool isEmpty() const{return cont.empty();}
    size_t numOfelements() const{return cont.size();}
    void insertToend(const T* t){cont.push_back(x);}
    T* getFirstelement()const{return *(cont.begin());}
    T* getLastelement()const{return *(cont.end()--)};
    T* findSpecificElement(const T* x)const{find_if(cont.begin(),cont.end(),isExist(x))};
    T* removeElemetnotDel(T);
    void removeAllnotDel();
    void removeElementAndDel(T);
    void removeAllAndDel();
    T* &operator[](const T &t) {}


private:
    typedef typename C::iterator it;
    typedef typename C::const_iterator c_it;
    tContainer_t(const tContainer_t &t) {}
    tContainer_t &operator=(const tContainer_t &t) {}
    C cont;
    it contit;
    c_it const_it;
}

template <class T>
class isExist{
   public:
   isExist(const T& t):val(t){}
   bool operator()(const T* parm)const{return *parm==t;} 
   private:
   T val;
}
