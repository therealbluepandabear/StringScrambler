#include <iostream>
#include <vector>
#include <ctime>
#include <set>
#include <algorithm>
#include <map>

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
    std::vector<char> asVector;

    for (auto c : str) {
        asVector.push_back(c);
    }

    std::vector<int> randomList;
    while (randomList.size() != asVector.size()) {
        auto random = RandomNumberGenerator::Random(0, (int)asVector.size() - 1);

        if (!(std::find(randomList.begin(), randomList.end(), random) != randomList.end())) {
            randomList.push_back(random);
        }
    }

    std::map<int, int> toIterate;

    int index = 0;
    for (auto i : randomList) {
        toIterate.insert(std::map<int, int>::value_type(i, index));
        index++;
    }

    std::vector<char> scrambled;

    std::vector<char> ref;

    ref.reserve(toIterate.size());
    for (auto const &[key, val] : toIterate) {
        ref.push_back(asVector[val]);
    }

    std::string asStr;

    for (auto letter : ref) {
        asStr += letter;
    }

    return asStr;
}

std::string ScrambleStringItr(std::string &str, int iterations) {
    std::string scrambled;
    for (int i = 0; i < iterations; i++) {
        scrambled = ScrambleString(str);
    }
    return scrambled;
}

[[noreturn]] void GetNumberOfUniqueScrambles(std::string &str) {
    std::vector<std::string> scrambled;
    while (true) {
        auto random = ScrambleString(str);

        if (!(std::find(scrambled.begin(), scrambled.end(), random) != scrambled.end())) {
            scrambled.push_back(random);
        } else {
        }

        std::cout << scrambled.size() << "\n";
    }
}

int main() {
    std::string in = "Hello";
    std::string scrambledTenTimes = ScrambleStringItr(in, 100);

    std::cout << scrambledTenTimes << "\n";

    return 0;
}
