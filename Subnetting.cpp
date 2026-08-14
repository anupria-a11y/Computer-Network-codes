#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int ip[4];
    char dot;
    cout << "Enter IP address: ";
    cin >> ip[0] >> dot >> ip[1] >> dot >> ip[2] >> dot >> ip[3];
    
    if(ip[0]>255||ip[1]>255||ip[2]>255||ip[3]>255) cout<<"Invalid IP address";
    else 
    {
        if(ip[0]>=0 && ip[0]<=126) {
            cout<<"This belongs to class A."<<endl<<"The default subnet mask is 255.0.0.0";
            cout<<endl<<"Number of hosts per network (excluding network and broadcast[so -2]) is 2^24 -2 = "<< (pow(2, 24) - 2);
            cout<<endl<<"Number of networks is 2^7= "<< pow(2, 7) ;
            cout<<". because the first bit of the first octet is fixed";
        }
        else if(ip[0]>127 && ip[0]<=191) {
            cout<<"This belongs to class B."<<endl<<"The defualt subnet mask is 255.255.0.0";
            cout<<endl<<"Number of hosts per network (excluding network and broadcast[so -2]) is 2^16 -2 = "<< (pow(2, 16) - 2);
            cout<<endl<<"Number of networks is 2^14 = "<< pow(2, 14) ;
            cout<<". because the first 2 bit of the first octet is fixed";

        }
        else if(ip[0]>191 && ip[0]<=233) {
            cout<<"This belongs to class C."<<endl<<"The default subnet mask is 255.255.255.0";
            cout<<endl<<"Number of hosts per network (excluding network and broadcast[so -2]) is 2^8 -2 = "<< (pow(2, 8) - 2);
            cout<<endl<<"Number of networks is 2^21 = "<< pow(2, 21) ;
            cout<<". because the first 3 bit of the first octet is fixed";

        }
        else if(ip[0]>233 && ip[0]<=239) {
            cout<<"This belongs to class D."<<endl<<"No subnet mask exists"<<endl;
            cout << "Used for multicast communication.";
        }
        else if(ip[0]>239 && ip[0]<=255) {
            cout<<"This belongs to class E."<<endl<<"No subnet mask exists"<<endl;
            cout << "Reserved for experimental purposes.";
        }
        else cout<<"This is a loop back IP. It is an internal address that allows a device to send network traffic to itself";
    }
    return 0;
}











/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ip[4];
    char dot;

    cout << "Enter IP address: ";
    cin >> ip[0] >> dot >> ip[1] >> dot >> ip[2] >> dot >> ip[3];

    // Validate IP address
    if (ip[0] < 0 || ip[0] > 255 ||
        ip[1] < 0 || ip[1] > 255 ||
        ip[2] < 0 || ip[2] > 255 ||
        ip[3] < 0 || ip[3] > 255) {
        cout << "Invalid IP address";
    }
    else {
        if (ip[0] >= 0 && ip[0] <= 126) {
            cout << "This belongs to Class A." << endl;
            cout << "Default subnet mask: 255.0.0.0" << endl;
            cout << "Number of hosts (excluding network and broadcast): "
                 << (pow(2, 24) - 2) << endl;
            cout << "Number of networks: 126" << endl;
        }
        else if (ip[0] == 127) {
            cout << "This is a Loopback IP address." << endl;
            cout << "It is used by a device to communicate with itself.";
        }
        else if (ip[0] >= 128 && ip[0] <= 191) {
            cout << "This belongs to Class B." << endl;
            cout << "Default subnet mask: 255.255.0.0" << endl;
            cout << "Number of hosts (excluding network and broadcast): "
                 << (pow(2, 16) - 2) << endl;
            cout << "Number of networks: " << pow(2, 14) << endl;
        }
        else if (ip[0] >= 192 && ip[0] <= 223) {
            cout << "This belongs to Class C." << endl;
            cout << "Default subnet mask: 255.255.255.0" << endl;
            cout << "Number of hosts (excluding network and broadcast): "
                 << (pow(2, 8) - 2) << endl;
            cout << "Number of networks: " << pow(2, 21) << endl;
        }
        else if (ip[0] >= 224 && ip[0] <= 239) {
            cout << "This belongs to Class D." << endl;
            cout << "Default subnet mask: None" << endl;
            cout << "Used for multicast communication.";
        }
        else { // 240 - 255
            cout << "This belongs to Class E." << endl;
            cout << "Default subnet mask: None" << endl;
            cout << "Reserved for experimental purposes.";
        }
    }

    return 0;
}*/


















/*#include <iostream>

using namespace std;

int main() {
    int ip[4];
    char dot;

    cout << "Enter IP address: ";
    cin >> ip[0] >> dot >> ip[1] >> dot >> ip[2] >> dot >> ip[3];

    cout << "Stored IP Address: "
         << ip[0] << "."
         << ip[1] << "."
         << ip[2] << "."
         << ip[3] << endl;

    return 0;
}*/