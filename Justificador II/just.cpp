#include<iostream>
#include<string.h>
using namespace std;

string trimEdges(string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

string trimMiddle(string& str){
    string result = "";
    for (size_t i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            result += str.at(i);
        }
        else if(str.at(i) == ' '){
            result += str.at(i);
            while(str.at(i+1) == ' '){
                i++;
            }
        }
    }

    return result;
    
}

int main(){
    int numEntradas;
    bool read = true;
    while(read){
        cin >> numEntradas;
        char dummy = cin.get();
        if(numEntradas == 0) read = false;
        else {
            string linhas[numEntradas];
            for(int i = 0; i < numEntradas; i++){
                getline(cin, linhas[i]);
            }

            int l = 0, m = 0;

            for (size_t i = 0; i < numEntradas; i++){
                linhas[i] = trimEdges(linhas[i]);
                linhas[i] = trimMiddle(linhas[i]);
                l = linhas[i].length();
                if(l > m) m = l;
            }
    
            for(int i = 0; i < numEntradas; i++){
                int la = linhas[i].length();
                la = m - la;
                while(la--){
                    cout << " ";
                }
                cout << linhas[i] << endl;
            }
            cout << endl;
        }
    }

    return 0;
}