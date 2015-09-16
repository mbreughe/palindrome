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

pair<string, string> split_and_mirror(const string & s){
    // Split the word in two halves and reverse second half
    size_t half_length = (s.size())/2;
    // Create a string, containing only the first half of the original
    string part1(s.begin(), s.begin()+half_length);
    // Create a string, containing only the second half in REVERSE order
    // of the original
    string part2_r(s.rbegin(), s.rbegin()+half_length);

    return make_pair(part1, part2_r);
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

    // If the original word was a palindrome, add a letter in the middle to keep it a palindrome
    if (is_palindrome(s)){
        new_s = s;
        // Iterator to middle character is used a lot
        // word of 6 characters --> middle_itr points to 4th char
        // Word of 7 characters --> middle_itr points to 4th char 
        string::iterator middle_itr = new_s.begin() + (new_s.size()/2);
        // For even number of characters, add random character in the middle
        if (s.size() % 2 == 0){
            new_s.insert(middle_itr,  'v');
            if (is_palindrome(new_s)){  
                return new_s;
            }
        }
        // Else copy the middle character
        else{
            char middle_char = *middle_itr;
            new_s.insert(middle_itr, middle_char);
            if(is_palindrome(new_s)){
                return new_s;
            }
        }
    }


    // In all other cases we need to process all characters
    new_s = string(s);
    pair<string, string> halves = split_and_mirror(new_s);
    string::iterator new_s_itr = new_s.begin();     // Note: we will loop over new_s rather than halves.first
    string::iterator p2_iter = halves.second.begin();

    char inserter = 'y';    // character to insert. Initialize random (here y).
    // Loop over both halves
    for (; new_s_itr != new_s.end() && p2_iter != halves.second.end(); new_s_itr++, p2_iter++){
        if(*new_s_itr != *p2_iter){
            inserter = *p2_iter;
            break;
        }
    }
 

    // Insert character
    new_s.insert(new_s_itr, inserter);
    //cout << "Created " << new_s << endl; 

    if(is_palindrome(new_s) ){
        return new_s;
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
