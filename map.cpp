// #include <iostream>
// #include <map>
// #include <string>
 
// int main() {
//     std::map<std::string, int> myMap;
//     myMap["apple"] = 5;
//     myMap["banana"] = 3;
//     myMap["orange"] = 8;
 
//     for (const auto& pair : myMap) {
//         std::cout << pair.first << ": " << pair.second << std::endl;
//     }
 
//     return 0;
// }
#include <iostream>
#include <unordered_map>
#include <string>
 
int main() {
    std::unordered_map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["orange"] = 8;
 
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
 
    return 0;
}