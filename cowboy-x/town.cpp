#include "town.h"
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

void Town::load_scene() {
    cout << endl << "****************************************************************" << endl << endl;
    cout << "You arrive to a dusty town. The wind blows the sand and it brushes" << endl;
    cout << "against your face. You see a nearby saloon." << endl;
    cout << endl;
    cout << "****************************************************************" << endl << endl;

    string input;

    cout << "1. Enter saloon.\n";
    cout << "2. Talk to stranger leaning against the wall." << endl;
    cout << ">";

    getline(cin, input);
    cout << input << endl;

    if(input == "1") {
        cout << "you selected 1";
        getline(cin, input);
        load_scene();
    }
}