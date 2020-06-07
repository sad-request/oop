#include "TVcontrol.hpp"
using namespace std;

string isOn="TV is turned on";
string isOff="TV is turned off";
string dontExist="No channel like this!";
string alreadyOn="TV already turned on";
string alreadyOff="TV already turned off";
string channelMessage="TV on channel ";

bool TV::TurnOn()
{
	if (TV::power == false && TV::channel == 0&&TV::offedChannel==0) {
		TV::power = true;
		TV::channel = 1;
		return true;
	}
	else if (TV::power == false) {
		TV::power = true;
		TV::channel = TV::offedChannel;
		return true;
	}
	else {
		cout << endl << alreadyOn << endl;
		return false;
	}
}

bool TV::TurnOff()
{
	if (TV::power == true) {
		TV::power = false;
		TV::offedChannel = TV::channel;
		TV::channel = 0;
		return true;
	}
	else
	{
		cout << endl << alreadyOff << endl;
		return false;
	}
}

bool TV::SelectChannel(int channel)
{
	if (channel >= 1 && channel <= 99) {
		TV::channel = channel;
		return true;
	}
	else {
		cout << endl << dontExist << endl;
		return false;
	}
}

void TV::Info() {
	if (TV::power == false) {
		cout << endl << isOff << endl;
	}
	else {
		cout << endl << isOn << endl;
	}
	cout << channelMessage << TV::channel << endl<<endl;;

}
