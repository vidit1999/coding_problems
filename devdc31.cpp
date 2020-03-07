#include <bits/stdc++.h>
using namespace std;

/*
Write a function that accepts starting and ending IPv4 addresses and
returns the number of IP addresses from start to end, excluding the ending address.
All input will be valid IPv4 addresses in the forms of strings.

Examples:
ipsBetween("10.0.0.0", "10.0.0.50") => 50
ipsBetween("10.0.0.0", "10.0.1.0") => 256
ipsBetween("20.0.0.10", "20.0.1.0") => 246

It would be impressive if anyone wanted to try their hand at creating the same function for IPv6.
You might have to work with some hefty numbers though. 
*/

// for ipv4
// get the decimal representation of ip
long long ipToInt(string ip){
    int start = 0;
    string temp = "";
    vector<long long> parts;
    for(int i=0;i<ip.length();i++){
        if(ip[i] == '.' || i == ip.length()-1){
            if(i == ip.length()-1)
                temp += ip[i];
            parts.push_back(atoll(temp.c_str()));
            start = i+1;
            temp = "";
        }
        else{
            temp += ip[i];
        }
    }

    reverse(parts.begin(),parts.end());

    long long address = 0;
    for(int i=0;i<parts.size();i++){
        address += parts[i]*pow(256,i);
    }
    return address;
}

// for ipv4
int ipsBetween(string ip1, string ip2){
    long long i1 = ipToInt(ip1);
    long long i2 = ipToInt(ip2);
    return max(i1,i2) - min(i1,i2);
}

// main function
int main(){
    cout << ipsBetween("10.0.0.0", "10.0.0.50") << "\n";
    cout << ipsBetween("10.0.0.0", "10.0.1.0") << "\n";
    cout << ipsBetween("20.0.0.10", "20.0.1.0") << "\n";
    return 0;
}