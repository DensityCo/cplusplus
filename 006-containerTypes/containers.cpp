#include <iostream>
#include <string>

// Sequence containers
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

// Associative containers
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Some algorithm stuff
#include <numeric>
#include <algorithm>


void test_array()
{
    std::cout << "std::array examples" << std::endl;

    // Never do this, but here's a new array on the heap
    auto foo = new std::array<int, 3>();
    // The .data() function returns the "underlying" array structure
    foo->data()[0] = 123;
    foo->data()[1] = 456;
    foo->data()[2] = 789;
    // Now the array has data in it (although again, never do this)
    for (auto it = foo->begin(); it != foo->end(); ++it) {
        auto item = *it;
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Normal modern way to do an array
    std::array<int, 3> bar = { 321, 654, 987 };
    for (auto it = bar.begin(); it != bar.end(); ++it) { // std::array<int, 3>::const_iterator
        auto item = *it;
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}


// void test_vector()
// {
//     std::cout << "std::vector examples" << std::endl;

//     // Vectors can be appended to, no need to specify initial size
//     std::vector<int> foo = { 123, 456 };
//     foo.push_back(789);

//     // Use .rbegin() and .rend() to iterate backwards 
//     for (auto it = foo.rbegin(); it != foo.rend(); ++it) { // std::vector<int>::const_iterator
//         auto item = *it;
//         std::cout << item << " ";
//     }
//     std::cout << std::endl;
    
//     // Assign new values
//     foo.assign({ 111, 222, 333 });

//     // Nicer iteration syntax
//     for (auto& it : foo) {
//         std::cout << it << " ";
//     }
//     std::cout << std::endl;

//     // Insert value
//     foo.insert(foo.begin() + 1, 999);
//     for (auto& it : foo) {
//         std::cout << it << " ";
//     }
//     std::cout << std::endl;

//     // How much storage do we have before it will allocate more?
//     std::cout << "storage available: " << foo.capacity() << std::endl;

//     std::cout << std::endl;
// }


// void test_deque()
// {
//     std::cout << "std::deque examples" << std::endl;

//     // Deques can be appended to, no need to specify initial size
//     std::deque<std::string> foo = { "DEF" };
//     foo.push_back("GHI");
//     foo.push_front("ABC");
//     for (auto& it : foo) {
//         std::cout << it << " ";
//     }
//     std::cout << std::endl;

//     // Both vectors and deques can pop values where allowed
//     foo.pop_front();
//     for (auto& it : foo) {
//         std::cout << it << " ";
//     }
//     std::cout << std::endl;

//     // Deques do not have a contiguous array backing them, these don't exist
//     //foo.data();
//     //foo.capacity();

//     std::cout << std::endl;
// }


// void test_map()
// {
//     std::cout << "std::map examples" << std::endl;

//     // Map literal is a tiny bit awkward, but practical
//     std::map<std::string, int> foo = {{"a", 1}, {"b", 2}, {"c", 3}};

//     // Accessing a value is pretty gravy
//     std::cout << foo.at("b") << std::endl;
//     std::cout << foo["b"] << std::endl;

//     // Assigning a value is nice too
//     foo["e"] = 5;
//     std::cout << foo["e"] << std::endl;
//     foo.insert({"d", 4});
//     std::cout << foo["d"] << std::endl;

//     // We'd need a std::multimap to avoid overwriting this key
//     foo["d"] = 1;
//     std::cout << foo["d"] << std::endl;

//     // Because this isn't a std::unordered_map, it is sorted by key
//     for (auto& it : foo) {
//         std::cout << it.first << ":" << it.second << " ";
//     }
//     std::cout << std::endl;

//     std::cout << std::endl;
// }

// void test_set()
// {
//     std::cout << "std::set examples" << std::endl;

//     // Set is like a structured vector optimized for lookups
//     std::set<std::string> foo = {"a", "b", "c"};

//     // Keys are the same as values
//     std::cout << foo.count("b") << std::endl;

//     // Insert new values
//     foo.insert("e");
//     std::cout << foo.count("e") << std::endl;
//     foo.insert("d");
//     std::cout << foo.count("d") << std::endl;

//     // A std::multiset would count two instances of "d"
//     foo.insert("d");
//     std::cout << foo.count("d") << std::endl;

//     // Any set returns a count of 0 if the element is not found
//     std::cout << foo.count("z") << std::endl;

//     // Because this isn't a std::unordered_set, it is sorted by key
//     for (auto& it : foo) {
//         std::cout << it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << std::endl;
// }


// bool longer_string(std::string item1, std::string item2)
// {
//     return item1.length() < item2.length();
// }

// void test_algorithm()
// {
//     std::cout << "std::algorithm examples" << std::endl;

//     std::vector<int> foo = {1, 2, 2, 4, 7, 4, 3};
    
//     std::cout << *max_element(foo.begin(), foo.end()) << std::endl;
//     std::cout << count(foo.begin(), foo.end(), 4) << std::endl;

//     std::vector<std::string> bar = {"asdf", "jkl", "pqrst", "xyz", "lmnop"};
    
//     // Sort strings with default (alphabetical) comparison function
//     stable_sort(bar.begin(), bar.end());
//     for (auto& it : bar) {
//         std::cout << it << " ";
//     }

//     // Sort strings by string length
//     stable_sort(bar.begin(), bar.end(), longer_string);
//     for (auto& it : bar) {
//         std::cout << it << " ";
//     }

//     std::cout << std::endl;
// }


int main(int argc, char** argv)
{
    std::cout << "Container type examples" << std::endl << std::endl;

    test_array();
    // test_vector();
    // test_deque();
    // // std::forward_list, forward-linked list
    // // std::list, double-linked list

    // test_map();
    // test_set();

    // test_algorithm();

    return 0;
}
