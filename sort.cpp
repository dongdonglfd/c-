// #include<iostream>
// #include<algorithm>
// using namespace std;
// bool compare(int a, int b) {
//     return a > b; // 降序排序
// }
// int main()
// {
//     int arr[] = {5, 3, 1, 2, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     sort(arr, arr + n); // 默认升序排序
    
//     for (int i = 0; i < n; ++i) {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
//     sort(arr,arr+n,compare);
//     for (int i = 0; i < n; ++i) {
//         cout << arr[i] << " ";
//     }


// }
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Student {
    string name;
    int score;
};
bool compareStudents(Student a, Student b) {
    return a.score < b.score; // 按分数升序排序
}

int main() {
    Student students[] = {{"Alice", 80}, {"Bob", 90}, {"Charlie", 70}};
    int n = sizeof(students) / sizeof(students[0]);
    sort(students, students + n, compareStudents);
    for (int i = 0; i < n; ++i) 
    {
        cout << students[i].name << " " << students[i].score << endl;
    }
    return 0;
}