#include <iostream>
#include <vector>
#include <ctime>

class RandomNumberGenerator {
public:
    // NAWAZ'S STACKOVERFLOW CODE LINK: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    static int Random(const int min, const int max) {
        static bool first = true;
        if (first) {
            srand( time(nullptr) );
            first = false;
        }
        return min + rand() % (( max + 1 ) - min);
    }
};

std::string ScrambleString(std::string &str) {
}

int main() {
    std::string str = "Hi";
    ScrambleString(str);

    return 0;
}
