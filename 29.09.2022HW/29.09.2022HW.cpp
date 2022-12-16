#include <iostream>
#include <cmath>

using namespace std;


//2
//2.1
char* DelS() {
    char* strin = new char[256] { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
    char* new_strin = new char[strlen(strin) - 1];
    int delIndex = 3;
    strncpy_s(new_strin, strlen(strin), strin, delIndex - 1);
    strcat_s(new_strin, strlen(strin), strin + delIndex);
    delete[] strin;
    return new_strin;
}

//2.2
char* DelAllS() {
    char* strin = new char[256] { "ddddddddddddddddddddddddddddddddddd" };
    char* new_strin = new char[256] {""};
    char* str;
    char element = 'l';
    while (str = strchr(strin, element)) {
        strncat_s(new_strin, strlen(strin), strin, strlen(strin) - strlen(str));
        strin = str + 1;
    }
    strcat_s(new_strin, strlen(str) + 5, str);
    return new_strin;
}

//2.3
char* SInStr() {
    char* strin = new char[256] { "sssssssssssssssssssssssssssssssssss" };
    int index = 5;
    char litera = 'A';
    char* new_strin = new char[strlen(strin) + 1];
    strncpy_s(new_strin, strlen(strin), strin, index + 1);
    *(new_strin + index) = litera;
    strcat_s(new_strin, strlen(strin) + 2, strin + index);
    return new_strin;
}

//2.4
char* SPRep() {
    char* strin = new char[256];
    gets_s(strin, 256);
    char* str;
    while (str = strchr(strin, '.')) {
        *(str) = '!';
        strcpy_s(strin + strlen(strin) - strlen(str), strlen(strin), str);
    }
    return strin;
}

//2.5
void SRep() {
    char* strin = new char[256];
    gets_s(strin, 256);
    char us = 'o'; // пользователя символ
    int count = 0; // счестчик
    char* str;
    while (str = strchr(strin, us)) {
        count++;
        strin = str + 1;
    }
    cout << count;
}

//2.6
void CheckS() {
    char* strin = new char[256];
    gets_s(strin, 256);
    int digit = 0;
    int alpha = 0;
    int other = 0;
    for (int i = 0; i < strlen(strin); i++) {
        if (isdigit(strin[i]))
            digit++;
        else if (isalpha(strin[i]))
            alpha++;
        else
            other++;
    }
    cout << "Digits:" << digit << endl <<
        "Letters: " << alpha << endl <<
        "Other symbols: " << other;
}

int main()
{
    //cout << DelS();    //1
    //cout << DelAllS(); //2
    //cout << SInStr()   //3
    //cout << SPRep();   //4
    CheckS();            //5
    //CheckS();          //6
}

