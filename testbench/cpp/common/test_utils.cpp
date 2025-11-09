// ====================================================================
// MAZE Network Node - Test Utilities Implementation
// ====================================================================

#include "test_utils.h"
#include <algorithm>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

// ====================================================================
// Utility Functions Implementation
// ====================================================================

string to_lower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string to_upper(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string to_string(double value, int precision) {
    stringstream ss;
    ss << fixed << setprecision(precision) << value;
    return ss.str();
}

bool file_exists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

bool create_directory(const string& path) {
    return (mkdir(path.c_str(), 0755) == 0) || (errno == EEXIST);
}

string generate_test_id(const string& prefix) {
    static uint32_t counter = 0;
    auto now = chrono::system_clock::now();
    auto timestamp = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

    return prefix + "_" + to_string(timestamp) + "_" + to_string(counter++);
}

double cycles_to_time(uint64_t cycles, double frequency_mhz) {
    return cycles / (frequency_mhz * 1000000.0); // Convert to seconds
}