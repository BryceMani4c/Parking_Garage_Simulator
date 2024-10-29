#ifndef smartpointer_h
#define smartpointer_h

template<typename T>
class smartPointer{
    private:
        T* data;

    public:
        smartPointer(){
            T* data = NULL;
        } 
        ~smartPointer(){
            delete data;
        }



};







#endif