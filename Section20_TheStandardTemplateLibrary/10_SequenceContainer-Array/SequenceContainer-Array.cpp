/***
 * [std::array (C++11)]
 * 
 * #include <array>
 * 
 * Fixed size       => What makes this different frow a raw array. First, it's an object type. std array always has its size associated with it. Unlike a raw array, a td array doesn't decay to a pointer to the first element of the array when we pass it into a function. Element access happens in constant time. Constant time means that the time it takes to access an element is independent of the number of elements in the container. 
 *  Size must be known at compile time
 * 
 * Direct element access
 * 
 * Provides access to the underlying raw array
 * 
 * Use instead of raw arrays when possible
 * 
 * All iterators available and do not invalidate
 * 
 * [std::array - initialization and assignment]
 * 
 * => The size of the array must be know at compile time,
 * 
 * std::array<int, 5> arr1 {{1,2,3,4,5}};       C++11 vs. C++14
 * std::array<std::string, 3> stooges{
 *  std::string("Larry");
 *  "Moe",
 *  std::string("Curly");
 * };
 * 
 * arr1 = {2,4,6,8,10};
 * 
 * [std::array - common methods]
 * 
 * std::array<int, 5> arr {1,2,3,4,5};
 * 
 * std::cout << arr.size();     // 5
 * std::cout << arr.at(0);      // 1
 * std::cout << arr[1];         // 2
 * std::cout << arr.front();    // 1
 * std::cout << arr.back();     // 5
 * 
 * std::array<int, 5> arr1 {10,20,30,40,50};
 * 
 * std::cout << arr.empty();    // 0 (false)
 * std::cout << arr.max_size(); // 5
 * arr.swap(arr1);              // swaps the 2 arrays
 * int *data = arr.data();      // get raw array address
 * ***/
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>      // for more algorithms like accumulate

//Display the array -- note the size MUST be included when passing a std::array to a function

void display(const std::array<int, 5> & array){
    std::cout << "[ ";
    for(int i = 0; i < array.size(); i++){
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

void test1(){
    std::cout << "\nTest 1=======================================\n";
    std::array<int, 5> arr1 {1,2,3,4,5};        // double {{}} if C++ 11
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2);          // Elements are not initialized (contain 'garbage')
    
    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       // 5
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       // 5

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);
    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;        // 10
    std::cout << "Back of arr2: " << arr2.back() << std::endl;          // 50
}

void test2(){
    std::cout << "\nTest 2=======================================\n";
    std::array<int, 5> arr1 {1,2,3,4,5};        // double {{}} is C++ 11
    std::array<int, 5> arr2 {10,20,30,40,50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
}

void test3(){
    std::cout << "\nTest 3=======================================\n";

    std::array<int, 5> arr1 {1,2,3,4,5};        // double {{}} is C++ 11

    int *ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000;

    display(arr1);
}

void test4(){
    std::cout << "\nTest 4=======================================\n";

    std::array<int, 5> arr1 {2,1,4,5,3};        // double {{}} is C++ 11
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5(){
    std::cout << "\nTest 5=======================================\n";

    std::array<int, 5> arr1 {2,1,4,5,3};        // double {{}} is C++ 11

    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    std::cout << "min: " << *min_num << ", max: " << *max_num << std::endl;
}

void test6(){
    std::cout << "\nTest 6=======================================\n";

    std::array<int, 5> arr1 {2,1,3,3,5};        // double {{}} is C++ 11

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else 
        std::cout << "No adjacent elements found\n";
}

void test7(){
    std::cout << "\nTest 7=======================================\n";

    //accumulate is from #include<numeric>
    std::array<int,5> arr1 {1,2,3,4,5};         // double {{}} is C++ 11
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test8(){
    std::cout << "\nTest 8=======================================\n";
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};

    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times\n";
}

void test9(){
    std::cout << "\nTest 9=======================================\n";
    std::array<int, 10> arr1 {1,2,3,59,69,79,89,299,399,499};
    //find how many numbers are between 10 and 200 -> 59 69 79 89

    int count = std::count_if(arr1.begin(), arr1.end(), [] (int x) {return x > 10 && x < 200;});
    std::cout << "Found " << count << " matches\n";
}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}