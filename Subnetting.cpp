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
