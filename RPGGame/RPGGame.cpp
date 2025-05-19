
#include <iostream>
#include "NPC.h"
using namespace std;
extern "C" int PrintText(const char* text);

int main() {
	const char* test = "Witaj w grze";
	PrintText(test);
    return 0;
}