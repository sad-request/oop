#include <iostream>
#include "TVcontrol.hpp"

string usualMessage="--------------------\nTurn TV on - 1\nTurn TV off - 2\nSelect channel - 3\nInfo - 4\nExit - 0\n--------------------\n";
string enterChannel = "Enter channel (1-99): \n";

using namespace std;
int main()
{
	int menu = 0;
	TV MyTV;
	while (true) {
        cout << usualMessage<<endl;;
		cin >> menu;
		if (menu == 1) {
			MyTV.TurnOn();
		}
		if (menu == 2) {
			MyTV.TurnOff();
		}
		if (menu == 3) {
			int channel = 1;
			cout << enterChannel;
			cin >> channel;
			MyTV.SelectChannel(channel);

		}
		if (menu == 4) {
			MyTV.Info();
		}
		if (menu == 0) {
			break;
		}
	}
	return 0;
}
