// TextBuddyExecutable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "App.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage : TextBuddy <filename>\n");
    } else {
        App::runWithFile(std::string(argv[1]));
    }
    return 0;

}

