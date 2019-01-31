#include <wiringSerial.h>
#include <iostream>

using namespace std;

 //dmesg | grep tty

int main(int argc, char** argv)
{
    
    int serialDescriptor = serialOpen ("/dev/ttyAMA0", 9600);

    cout << "Starting Serial with"<< serialDescriptor<< endl;
    serialClose(serialDescriptor);


}
