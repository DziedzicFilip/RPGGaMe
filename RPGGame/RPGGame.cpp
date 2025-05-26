#include <iostream>

using namespace std;

// Import assembly functions
extern "C" int PrintText(const char* text);

int main() {
    // Welcome message using our assembly function
    const char* welcome = "Witaj w świecie RPG Game - Las Cieni";
    PrintText(welcome);
    
    return 0;
}