#include <iostream>
#include <cstring>

class String
{
    public:
        String()
        {
            
        }
        String(char* s, int len)
        {
            length=len;
            _s=new char[length];
            strcpy(_s,s);
        }
        ~String()
        {
            delete _s;
        }
        friend std::ostream& operator<<(std::ostream& os, const String& obj)
        {
            for(int i=0;i<obj.length;++i)
                os<<*(obj._s+i);
            return os;
        }

        //both of the + functions work fine
        friend String operator+(const String& str1, const String& str2)
        { 
            String str_add(strcat(str1._s,str2._s),str1.length+str2.length-1);  
            return str_add;
        }

        String operator+(const String& str1)
        { 
            String str_add(strcat(_s,str1._s),str1.length+length-1);  
            return str_add;
        }

    private:
        char* _s;
        int length;
};

int main()
{
    char str1[]="Hello ";
    int len1=sizeof(str1)/sizeof(*str1); //-1 for '\0'
    String Str1(str1,len1);
    std::cout<<Str1<<std::endl;
    char str2[]="my man";
    int len2=sizeof(str2)/sizeof(*str2);
    String Str2(str2,len2);
    String Str3=Str1+Str2;
    std::cout<<Str3<<std::endl;
    return 0;
}