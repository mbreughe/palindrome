#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &s){
    size_t half_length = (s.size())/2;

    // Create a string, containing only the first half of the original
    string part1(s.begin(), s.begin()+half_length);

    // Create a string, containing only the second half in REVERSE order
    // of the original
    string part2_r(s.rbegin(), s.rbegin()+half_length);

    // Note that, in case of an odd length, the middle character
    // will not be compared.
    // This is OK for the palindrome definition
    return part1 == part2_r;
}

string make_pal(const string &s){
    string new_s;

    // If the first and last character differ
    if (s.front() != s.back()) {
        // Try adding first character to the back
        new_s = s;
        new_s.push_back(s.front());
        if (is_palindrome(new_s) ){
            return new_s;
        }

        // Try adding last character to the front
        new_s = s;
        new_s.insert(new_s.begin(), s.back());
        if (is_palindrome(new_s) ){
            return new_s;
        }
    }
    
    // If none of our attempts worked, return NA   
    return "NA";
}

int main(){
    std::string s;
    while (getline(std::cin, s)){
        std::cout << make_pal(s) << std::endl;
    }
     
    return 0;
}
