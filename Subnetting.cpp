#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1, x2, x3, x4;
    char separator;
    int prefixLength;

    cout << "Enter base IP address (e.g., 192.168.10.0): ";
    cin >> x1 >> separator >> x2 >> separator >> x3 >> separator >> x4;

    cout << "Enter CIDR prefix (e.g., 26 for /26): ";
    cin >> prefixLength;

    if (prefixLength < 24 || prefixLength > 30) {
        cout << "Error: This program currently supports Class C subnetting (CIDR 24 to 30)." << endl;
        return 1;
    }

    int remainingBits = 32 - prefixLength;
    int subnetSize = pow(2, remainingBits);
    int totalSubnets = 256 / subnetSize;
    int availableHosts = subnetSize - 2;
    int maskValue = 256 - subnetSize;

    cout << "\n--- General Subnet Information ---" << endl;
    cout << "Calculated Subnet Mask : 255.255.255." << maskValue << endl;
    cout << "Total Usable Hosts     : " << availableHosts << " per subnet" << endl;
    cout << "Total Subnets Created  : " << totalSubnets << "\n" << endl;

    for (int count = 0; count < totalSubnets; count++) {

        int networkIP = count * subnetSize;
        int firstIP = networkIP + 1;
        int lastIP = networkIP + availableHosts;
        int broadcastIP = networkIP + subnetSize - 1;

        cout << "Subnet " << count + 1 << endl;

        cout << "Network Address   : "
             << x1 << "." << x2 << "." << x3 << "." << networkIP << endl;

        cout << "First Host        : "
             << x1 << "." << x2 << "." << x3 << "." << firstIP << endl;

        cout << "Last Host         : "
             << x1 << "." << x2 << "." << x3 << "." << lastIP << endl;

        cout << "Broadcast Address : "
             << x1 << "." << x2 << "." << x3 << "." << broadcastIP << endl;

        cout << "\nUsable IP Addresses:" << endl;

        for (int host = firstIP; host <= lastIP; host++) {
            cout << "  "
                 << x1 << "." << x2 << "." << x3 << "." << host << endl;
        }

        cout << endl;
    }

    return 0;
}
