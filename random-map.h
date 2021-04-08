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
int RnadomBetweenU(int first, int last);

//return normally distributed random number between first and last inclusive
int RandomBetweenN(int first, int last);

//returns numbers using the rand() function
int RandomBetween(int first, int last);

//prints the distribution the same way the sample code did
//showing the distribution
void PrintDistribution(const std::map<int, int> & numbers);

//defualt example code I slapped into a function for organization
//it prints a histogram of normally distributed number centered around 4
void DefualtExample();

#endif  //RANDOM_MAP_H

