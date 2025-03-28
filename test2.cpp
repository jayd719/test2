#include<iostream>
#include<ctime>
#include<unistd.h>

using namespace std;

int main() {


    time_t timeStamp;
    while (true)
    {
        system("clear");
        time(&timeStamp);
        cout << "Hello world\t\t" << ctime(&timeStamp) << "\r";
        sleep(1);
    }


    return 1;
}