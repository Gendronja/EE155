#include <iostream>
#include <string>
using namespace std;

void CharToString(char c, string &s){
    s = c;
    return;
}

void StringToChar_ONE(string s, char &c){
    c = s[0];
    return;
}

void StringToChar_ALL(string s, char *ptr, int &size){
    size = 0;
    int len = s.length();
    for(int i=0;i<len;i++){
        ptr[i] = s[i];
        size++;
    }
    ptr[len] = '\0';
    size++;
    return;
}

void PrintCharArray(char*ptr, int size){
    cout << "Size: " << size <<". ";
    for(int i=0; i<size; i++){
        cout << ptr[i];
    }
    cout << "." << endl;
}

int main()
{
    string s1, s2, s3;
    CharToString('1', s1);
    CharToString('A', s2);
    CharToString('d', s3);
    cout << s1 << " " << s2 << " " << s3 << endl;
    cout << s1.length() << " " << s2.length() << " " << s3.length() << endl;

    char c1, c2, c3;
    StringToChar_ONE("A", c1);
    StringToChar_ONE("1", c2);
    StringToChar_ONE("2", c3);
    cout << c1 << " " << c2 << " " << c3 << endl;
    cout << int(c1) << " " << int(c2) << " " << int(c3) << endl;

    char *c_ptr = new char[10];
    int size;
    
    StringToChar_ALL("APPLE", c_ptr, size);
    PrintCharArray(c_ptr, size);

    StringToChar_ALL("APP", c_ptr, size);
    PrintCharArray(c_ptr, size);
    
    StringToChar_ALL("1234APPLE", c_ptr, size);
    PrintCharArray(c_ptr, size);
    return 0;
}

