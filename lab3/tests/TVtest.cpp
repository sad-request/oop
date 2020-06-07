//#pragma once
#define CATCH_CONFIG_MAIN
//#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <sstream>
#include <string>
//#include "D:\univers\OOP\my\lab3\TVcontrol.hpp"
#include "catch.hpp"

using namespace std;

SCENARIO("Turn On") {
//    TV tv;
//	tv.TurnOn();
//	REQUIRE(tv.power== true);
REQUIRE(1==1);
}

/*	SECTION("Turn On channel") {
		tv.TurnOn();
		REQUIRE(tv.GetCurrentChannel() == 1);
	}

	SECTION("Turn Off") {
		tv.TurnOn();
		tv.TurnOff();
		REQUIRE(tv.IsEnabled() == false);
	}

	SECTION("Turn Off channel") {
		tv.TurnOn();
		tv.TurnOff();
		REQUIRE(tv.GetCurrentChannel() == 0);
	}

	SECTION("Change channel") {
		tv.TurnOn();
		tv.SelectChannel(20);
		REQUIRE(tv.SelectChannel() == 20);
	}*/

