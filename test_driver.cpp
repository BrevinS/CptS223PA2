#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "header.h"

using namespace std;
using namespace chrono;

int main(int argc, char** argv){
    //Notify the file designated
    cout << "You have entered the file: " << argv[1] << endl;

    std::vector<int> a;
    string temp;
    ifstream infile;
    int inputLength = 0, r1, r2, r3, r4;
    infile.open(argv[1]);
    while(getline(infile, temp)){
        a.push_back(stoi(temp)); 
        inputLength += 1;
        temp = " ";
    }

    auto start1 = high_resolution_clock::now();
    r1 = maxSubSum1(a);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "maxSubSum1 Execution Time: " << duration1.count() << " microseconds" << endl;
    
    auto start2 = high_resolution_clock::now();
    r2 = maxSubSum2(a);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "maxSubSum2 Execution Time: " << duration2.count() << " microseconds" << endl;


    auto start3 = high_resolution_clock::now();
    r3 = maxSubSum3(a);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "maxSubSum3 Execution Time: " << duration3.count() << " microseconds" << endl;


    auto start4 = high_resolution_clock::now();
    r4 = maxSubSum4(a);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "maxSubSum4 Execution Time: " << duration4.count() << " microseconds" << endl << endl;

    cout << "Size of input sequence: " << inputLength << endl;
    cout << "maxSubSum1 Result: " << r1 << endl;
    cout << "maxSubSum2 Result: " << r2 << endl;
    cout << "maxSubSum3 Result: " << r3 << endl;
    cout << "maxSubSum4 Result: " << r4 << endl;

    infile.close();
    return 0;
}