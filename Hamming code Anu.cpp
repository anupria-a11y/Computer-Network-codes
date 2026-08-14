#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string input;
	int num[4], db;
	int dbit[7]= {9,9,9,9,9,9,9};
	cout << "Enter 4 digit binary: ";
	cin >> input;

	if (input.length() != 4) {
		cout << "Invalid input. More thaan 4 digits" << endl;
		return 1;
	}
	for (int i = 0; i < 4; i++) {
		if (input[i] != '0' && input[i] != '1') {
			cout << "Invalid value. Only 0 or 1 allowed" << endl;
			return 1;
		}
		num[i] = input[i] - 48; //conver char to integer use'0' or 48
	}
	cout << "Your data is: ";
	for (int i = 0; i < 4; i++) {
		cout << num[i];
	}
	cout << endl;
	int r = 0, m = 4;
	int flag=0;

	while (flag==0)
	{		if((pow(2,r))>=(4+r+1))
		{
			cout<<"Number of parity bits= "<<r;
			flag=1;
		}	else r++;
	}

	cout << endl;
	cout<<"Position of parity bits: ";
	for( int i=0; i<r; i++) {
		cout<<pow(2,i)<<"   ";
		db=7-pow(2,i);
		dbit[db]=4;
	}

	cout << endl;
	for (int i = 0; i < 7; i++) {
		cout << dbit[i]<<" ";
	}
	int j= 0;
	for (int i = 0; i < 7; i++) {
		if(dbit[i]!=4) {
			dbit[i]=num[j];
			j++;
		}
	}

	cout << endl;
	for (int i = 0; i < 7; i++) {
		cout << dbit[i]<<" "; }
	cout<<endl;


	for(int pbit = 1; pbit <= 4; pbit *= 2)       //001
	{	int parity = 0;
		for(int pos = 1; pos <= 7; pos++)
		{	if(pos & pbit)                  //011&001 = 001 !=000
			{	if(pos != pbit)
				{parity ^= dbit[7 - pos];	}
			}
		}

		dbit[7 - pbit] = parity;
		cout << parity<< endl;
	}

	cout << "\n\nHamming Code : ";

	for(int i = 0; i <=6; i++)
		cout << dbit[i]<<" ";

	cout << endl;

	//-----------------------------------------------

	string received;
	int rbit[7];

	cout << "\nEnter hamming code: ";
	cin >> received;

	for(int i=0; i<7; i++)
	{
		rbit[i]=received[i]-'0';
	}

	int error = 0;
	for(int pbit=1; pbit<=4; pbit*=2)
	{
		int parity = 0;

		for(int pos=1; pos<=7; pos++)
		{
			if(pos & pbit)
			{
				int index = 7-pos;
				parity ^= rbit[index];
			}
		}

		if(parity!=0)
			error += pbit;
	}

	if(error==0)
	{
		cout<<"No error detected."<<endl;
	}
	else
	{
		cout<<"Error at bit number "<<error<<endl;
		rbit[7-error] ^= 1;
		cout << "\nCorrected Hamming Code : ";

		for(int i = 0; i <=6; i++)
			cout << rbit[i]<<" ";

		cout << endl;

	}
	return 0;
}


