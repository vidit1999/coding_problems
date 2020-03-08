#include <bits/stdc++.h>
using namespace std;

/*
Initialize an individual's middle name (if there is any).

Example:
'Jack Ryan' => 'Jack Ryan'
'Lois Mary Lane' => 'Lois M. Lane'
'Dimitri' => 'Dimitri'
'Alice Betty Catherine Davis' => 'Alice B. C. Davis'
*/

// split a string wrt space
vector<string> splitString(string s){
    string part = "";
    vector<string> splited;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            if(part.length() > 0)
                splited.push_back(part);
            part = "";
        }
        else{
            part += s[i];
        }
    }
    if(part.length() > 0)
        splited.push_back(part);
    return splited;
}


string initializeMiddleName(string name){
    vector<string> splitedName = splitString(name);
    if(splitedName.size() < 3)
        return name;
    string modifiedName = "";
    for(int i=1;i<splitedName.size()-1;i++){
        modifiedName += splitedName[i][0];
        modifiedName += ". ";
    }
    return splitedName[0] + " " + modifiedName + splitedName[splitedName.size()-1];
}

// main function
int main(){
    cout << initializeMiddleName("Jack Ryan") << "\n";
    cout << initializeMiddleName("Lois Mary Lane") << "\n";
    cout << initializeMiddleName("Dimitri") << "\n";
    cout << initializeMiddleName("Alice Betty Catherine Davis") << "\n";
    cout << initializeMiddleName("Alice   Catherine Davis") << "\n";
    return 0;
}