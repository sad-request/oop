#pragma once
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <string>
#include "D:\univers\OOP\my\lab3\TVcontrol.hpp"
#include "catch.hpp"

using namespace std;

SCENARIO("Turn On") {
    TV tv;
	tv.TurnOn();
	REQUIRE(tv.power== true);
}

SCENARIO("Turn Off") {
    TV tv;
    tv.TurnOn();
    tv.TurnOff();
    REQUIRE(tv.power == false);
}

SCENARIO("Turn Off channel") {
    TV tv;
    tv.TurnOn();
    tv.TurnOff();
    REQUIRE(tv.channel == 0);
}

SCENARIO("Select channel") {
    TV tv;
    tv.TurnOn();
    tv.SelectChannel(41);
    REQUIRE(tv.channel == 41);
}

SCENARIO("Select channel and turn off") {
    TV tv;
    tv.TurnOn();
    tv.SelectChannel(41);
    tv.TurnOff();
    REQUIRE(tv.channel == 0);
}
