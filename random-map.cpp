/*
* Enigma Swan Adams
* CS201-HW6
* 4/7/21
*
* file name: random-map.cpp
* main program as described in the homework assignment on blackbuard
* calling the function randomMap() from main runs the full main program
*
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include"random-map.h"
#include <stdlib.h>
#include <time.h>
#include<stdio.h>



using std::mt19937;
using std::uniform_int_distribution;
std::random_device r;


int main(){
    
    int first = 0;
    int last = 20;

    //uniformly distributed histagram
    std::map<int, int> histU;
    for (int n = 0; n < 10000; ++n) {
        ++histU[std::round(RandomBetweenU(first, last))];
    }
    std::cout << "Uniformly distributed from " << first << " to " << last << ":\n";
    std::cout << std::endl;
    PrintDistribution(histU);

   
    //normally distributed histagram
    std::map<int, int> histN;
    for (int n = 0; n < 10000; ++n) {
        ++histN[std::round(RandomBetweenN(first, last))];
    }
    std::cout << "Normal distribution around " << (last - first) / 2  << ":\n";
    PrintDistribution(histN);



    //histagram from rand() function
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(RandomBetween(first, last))];
        
    }
    std::cout << "distribution using rand() function" << (last - first) / 2 << ":\n";
    PrintDistribution(hist);

    
    /*
    for (size_t i = 0; i < 20; i++) {
        std::cout << RandomBetweenU(1, 6) << std::endl;
    }

    std::cout << "BREAK\n";
    for (size_t i = 0; i < 20; i++) {
        std::cout << RandomBetweenN(1, 6) << std::endl;
    }

    std::cout << "BREAK\n";

    srand(time(NULL));
    for (size_t i = 0; i < 20; i++) {
        std::cout << RandomBetween(1, 6) << std::endl;
    }
    */

   
}


int RandomBetweenU(int first, int last) {
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    return uniform_dist(e1);
}


int RandomBetweenN(int first, int last){
    std::random_device rd{};
    std::mt19937 gen{ rd() };

    double mean = (last - first) / 2;
    double deviation = (last - first) / 2;
    std::normal_distribution<> d{mean,deviation};

    return d(gen);
   }


int RandomBetween(int first, int last) {
    
    return rand()%(1+last-first) + first;
}


void PrintDistribution(const std::map<int, int>& numbers) {
    for (auto p : numbers) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }

}

