#pragma once
/*
* Enigma Swan Adams
* CS201-HW6
* 4/7/21
*
* main program (random-map.cpp) header
*
*/
#include<map>

#ifndef RANDOM_MAP_H

#define RANDOM_MAP_H
//returns uniform random number between first and last inclusive
int RandomBetweenU(int first, int last);

//return normally distributed random number between first and last inclusive
int RandomBetweenN(int first, int last);

//returns numbers using the rand() function
int RandomBetween(int first, int last);

//prints the distribution the same way the sample code did
//showing the distribution
void PrintDistribution(const std::map<int, int> & numbers);

#endif  //RANDOM_MAP_H

