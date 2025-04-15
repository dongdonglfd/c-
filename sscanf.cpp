#include<iostream>
using namespace std;
int main()
{
    const char *input = "123 45.67";
    int integerValue;
    float floatValue;
    int result = sscanf(input, "%d %f", &integerValue, &floatValue);
    
    const char *input = "Hello World";
    char word1[20], word2[20];
    int result = sscanf(input, "%19s %19s", word1, word2);
    
    const char *input = "42 Alice 3.14";
    int id;
    char name[20];
    float pi;
    int result = sscanf(input, "%d %19s %f", &id, name, &pi);

    const char *input = "key:value";
    char value[20];
 
    // 使用 sscanf 跳过 "key:" 并读取 "value"
    int result = sscanf(input, "%*[^:]:%19s", value);
}