#pragma once;
#include<iostream>
using namespace std;

class TV
{
public:
    bool TurnOn();
    bool TurnOff();
    bool SelectChannel(int channel);
    void Info();
    bool power = false;
	int channel = 0;
	int offedChannel = 0;
};
