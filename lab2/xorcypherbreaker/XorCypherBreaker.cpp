//
// Created by dawid on 13.03.17.
//

#include "XorCypherBreaker.h"
using namespace std;
vector<string> dictionary {"the","of"};
void PrintVector(vector<char> &v) {

    for(auto n : v) {

        cout << n;

    }
    cout<<endl;
}

string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary)
{
    vector<char> decrypt;
    char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int size=1201,sizeletters=26;
    int words_found=0;
    char key[3];
    for(int l=0;l<sizeletters;l++){
        for(int j=0;j<sizeletters;j++)
        {
            for(int k=0;k<sizeletters;k++)
            {
                for(int i=0; i<size-3;i+=3) {

                    char _a,_b,_c;
                    char cryptogram1,cryptogram2,cryptogram3;
                    cryptogram1=cryptogram[i];
                    cryptogram2=cryptogram[i+1];
                    cryptogram3=cryptogram[i+2];
                    _a=letters[k]^cryptogram1;
                    _b=letters[j]^cryptogram2;
                    _c=letters[l]^cryptogram3;
                    decrypt.emplace_back(_a);
                    decrypt.emplace_back(_b);
                    decrypt.emplace_back(_c);

                }
                for(int m=0;m<decrypt.size()-3;m++) {
                    char x, y, z;
                    x = decrypt[m];
                    y = decrypt[m + 1];
                    z = decrypt[m + 2];

                    if (((x == dictionary[0][0] and y == dictionary[0][1] and z == dictionary[0][2]) or
                         (x == dictionary[9][0] and y == dictionary[9][1] and z == dictionary[9][2]))) {
                        words_found++;
                    }
                }

                if(words_found>=12)
                {
                    string key;
                    key+=letters[k]; key+=letters[j]; key+=letters[l];
                    return key;
                }
                words_found=0;

                decrypt.clear();
            }
        }
    }

}