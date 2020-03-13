#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that takes an object as an argument, and returns a very similar object but with a special property.
The returned object should allow a user to access values by providing only the beginning of the key for the value they want.
For example if the given object has a key idNumber, you should be able to access its value on the returned object
by using a key idNum or even simply id. Num and Number shouldn't work because we are only looking for matches at the beginning of a key.

Be aware that you could simply add all these partial keys one by one to the object.
However, for the sake of avoiding clutter, we don't want to have a JSON with a bunch of nonsensical keys.

Also, if a key is tested that appears as the beginning of more than one key in the original object
(e.g. if the original object had a key idNumber and idString and we wanted to test the key id)
then return the value corresponding with whichever key comes first alphabetically.
(In this case it would be idNumbers value because it comes first alphabetically.)

Example
let o = partialKeys({ abcd: 1 })

o.abcd === 1 // true
o.abc === 1 // true
o.ab === 1 // true
o.a === 1 // true

o.b === 1 // false!

Object.keys(o) // ['abcd'] 
Tests
partialKeys({
aaa: 1,
abc: 2,
dfg: 3,
def: 4,
dfgh: 5
})
*/

class ObjectSpecial{
    map<string, int> mapSpecial;
    public:
    // constructor
    ObjectSpecial(map<string, int> mapObject){
        this->mapSpecial = mapObject;
    }

    // cpp map already stores the keys in alphabetical order
    // so start from first and if we find a string starts with the partial key
    // then return its value
    // if key not found then return 0
    int operator[](string s){
        for(auto it : mapSpecial){

            // check if key starts with the given partial key s
            // if true then return corresponding value
            if(it.first.rfind(s,0) == 0)
                return it.second;
        }
        return 0;
    }
};

ObjectSpecial partialKeys(map<string, int> m){
    return ObjectSpecial(m);
}

// main function
int main(){
    ObjectSpecial o = partialKeys({{"abcd",1},{"abbd", 2}});
    cout << o["ab"] << "\n"; // output : 2
    cout << o["k"] << "\n"; // output : 0 as key is not present
    cout << o["abc"] << "\n"; // output : 1
    cout << o["abd"] << "\n"; // output : 0 as key is not present
    return 0;
}