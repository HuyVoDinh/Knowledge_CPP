/***
 * Note: Since C++11 the STL has std::array which is a template-based array class
 * Use std::array instead of raw array whenever possible
 * 
 * Note that we can have non-type template parameters 
 * That's what N is in this acse
 * ***/

#include <iostream>
#include <string>

// template<int N> //=> The user provides the n at compile time.
// class Array {
//         int size {N};           // How do we get the N???
//         int values[N];          // The N needs to be known at compile-time

//         friend std::ostream &operator<<(std::ostream &os, const Array<N> &arr){ //Need to know N
//             os << "[ ";
//             for (const auto &val : arr.values)
//                 os << val << " ";
//             os << "]" << std::endl;
//             return os;
//         }
//     public:
//         Array() = default;      // The problem with that is that the compiler needs to know what the value of n is in order to create this array. Now we're not doing something like using a pointer and creating a new array of integers, like we did before, we're not doing that. That's not what I want to do. I want to create it on the stack. So the compiler needs to know the value of that n. It can't know that if we pass it into a constructor argument because it could be a variable, it could be any value.
//         Array(int init_val) {   // I want to be able to create an array class. Array arr; That's not good enough because there;s no size information. But if I can do something like Array<5> arr I can pass in the size of the array as a template parameter. Can use template
//             for(auto &item : values)
//                 item = init_val;
//         }

//         void fill (int val){
//             for(auto &item : values){
//                 item = val;
//             }
//         }

//         int get_size() const {
//             return size;
//         }

//         // overloaded subscript operator for easy use
//         int &operator[](int index){ // 2 bracket use it as array indexing. And all we're doing is returning a reference, so that we're able to change it as well.
//             return values[index];
//         }
// };

// int main(){

//     Array <5> nums;
//     std::cout << "The size of nums is: " << nums.get_size() << std::endl;
//     std::cout << nums << std::endl;

//     nums.fill(0);
//     std::cout << "The size of nums is: " << nums.get_size() << std::endl;
//     std::cout << nums << std::endl;

//     nums.fill(10);
//     std::cout << nums << std::endl;

//     nums[0] = 1000;
//     nums[3] = 2000;
//     std::cout << nums << std::endl;

//     Array<100> nums2 {1};   // We're creating an array of 100 integers.  It's fixed size array. We're not doing any memory allocation. It's happening on the stack. The compilers handling the sizing, and we're initializing all of those elements to one. We're displaying them all right 1 there's 100 of them. 
//     std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
//     std::cout << nums2 << std::endl;

//     return 0;
// }

template<typename T, int N> //=> The user provides the n at compile time.
class Array {
        int size {N};           // How do we get the N???
        T values[N];          // The N needs to be known at compile-time

        friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr){ //Need to know N
            os << "[ ";
            for (const auto &val : arr.values)
                os << val << " ";
            os << "]" << std::endl;
            return os;
        }
    public:
        Array() = default;      // The problem with that is that the compiler needs to know what the value of n is in order to create this array. Now we're not doing something like using a pointer and creating a new array of integers, like we did before, we're not doing that. That's not what I want to do. I want to create it on the stack. So the compiler needs to know the value of that n. It can't know that if we pass it into a constructor argument because it could be a variable, it could be any value.
        Array(T init_val) {   // I want to be able to create an array class. Array arr; That's not good enough because there;s no size information. But if I can do something like Array<5> arr I can pass in the size of the array as a template parameter. Can use template
            for(auto &item : values)
                item = init_val;
        }

        void fill (T val){
            for(auto &item : values){
                item = val;
            }
        }

        int get_size() const {
            return size;
        }

        // overloaded subscript operator for easy use
        T &operator[](int index){ // 2 bracket use it as array indexing. And all we're doing is returning a reference, so that we're able to change it as well.
            return values[index];
        }
};

int main(){

    Array <int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2 {1};   // We're creating an array of 100 integers.  It's fixed size array. We're not doing any memory allocation. It's happening on the stack. The compilers handling the sizing, and we're initializing all of those elements to one. We're displaying them all right 1 there's 100 of them. 
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings(std::string{"Frank"});
    std::cout << "The size of strings is: " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;

    strings.fill(std::string{"X"});
    std::cout << strings << std::endl;

    return 0;
}