#include <iostream>
#include <vector>
#include "Value.h"
#include "Coder.h"
#include "Decoder.h"
#include "Channel.h"
#include "Polynomial.h"
#include "Test.h"
#include "CLI.h"

#define DEBUG true

using namespace std;

int main()
{

    CLI cli;
    cli.run();
    return 0;

// Test test;
//    test.run();
//    return 0;
    GF2m::get_field()->set_m(8);

    Coder coder(2);
//    vector<Value> coded = coder.encode({213, 224, 234, 229, 240});
    vector<Value> coded = coder.encode({177, 135, 236});
    for (int i = 0; i < coded.size(); ++i) {
        cout << coded[i] << " ";
    }
    cout << endl;

    Decoder decoder(3);
    decoder.debug(true);

    try {
//            vector<Value> testMessage = {213-10, 224, 234 + 2, 229, 240, 5, 61, 81, 228}; // 4 6 7
//            vector<Value> testMessage = {213+10, 224+5, 234, 229, 240, 5, 61, 81, 228}; // 4 6 7
//            vector<Value> testMessage = {213+10, 224+5, 234+6, 229, 240, 110, 22, 82, 104, 199, 234}; // 4 6 7

        // error locator
//        vector<Value> testMessage = {135, 220, 143, 126, 93, 115, 141};
//        vector<Value> testMessage = {187, 111, 92, 208, 233, 152, 78};
//        vector<Value> testMessage = {88, 249, 78, 227, 23, 142};
//        vector<Value> testMessage = {29, 136,  42, 202,  83, 132, 125};

        vector<Value> testMessage = {177, 135, 236,  71, 185, 126};
        // he:lo
//        vector<Value> testMessage = {int('h'), int('e'), int(':'),  71, 185, 126};

        vector<Value> decoded = decoder.decode(testMessage);
        for (int i = 0; i < decoded.size(); ++i) {
            cout << decoded[i] << " ";
        }
        cout << endl;
    }catch(Error& e) {
        cout << e.message() << endl;
    }




    return 0;
}