//
//  1.cpp
//
//
//  Created by Louis on 2019/7/20.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> dict(256, -1);
    vector<int>::iterator itr = dict.begin();
    for (itr; itr != dict.end(); itr++) {
        cout << itr << endl;
    }
}
