#include<iostream>
#include<string.h>
using namespace std;


char* strAdd(char* str1, char* str2)
{   
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char* connectstr = new char[length1 + length2+1];
    int i = 0;
    int j = 0;
   
    for (i = 0; i < length1; i++)
    {
        connectstr[i] = str1[i];
    }
    
    for (i; i < length1+length2; i++)
    {
        connectstr[i] = str2[j];
        j++;
    }
    connectstr[i] = '\0';

    


    return connectstr;
    
}

int main() {
    char a[] = "ABCD"; int lengtha = strlen(a);
    char b[] = "EFGH"; int lengthb = strlen(b);
    char* newstr = new char[lengtha+lengthb];
    newstr= strAdd(a, b);
    
    for (int i = 0; i <lengtha+lengthb ; i++)
    {
        cout << newstr[i]<<" ";
    }
    return 0;

}