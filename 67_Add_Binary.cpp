#include<bits/stdc++.h>
using namespace std;

string binadd(char a1, char a2, string c){
        string s = "0";
        if (a1 == '1' && a2 == '1' && c == "1"){
            s = '1';
            c = "1";
        }

        else if ((a1 == '1' && a2 == '1' && c == "0") || (a1 == '1' && a2 == '0' && c == "1") || (a1 == '0' && a2 == '1' && c == "1")){
            c = "1";
        }

        else if ((a1 == '1' && a2 == '0' && c == "0") || (a1 == '0' && a2 == '1' && c == "0") || (a1 == '0' && a2 == '0' && c == "1")){
            s = '1';
            c = "0";
        }

        else {
            c = "0";
        }
        string result = s + c;
        return result;
    }

string addBinary(string a, string b) {
    string b1;
    string c = "0";
    string s = "";
    int i;
    int la = a.length();
    int lb = b.length();
    int maxi = max(la, lb);
    int mini = min(la, lb);

    for (i=0; i<mini; i++){
        b1 = binadd(a[la-1-i], b[lb-1-i], c);
        s = b1[0] + s;
        c = b1[1];
    }

    if (la == maxi){
        for (i; i<maxi; i++){
            b1 = binadd(a[la-1-i], '0', c);
            s = b1[0] + s;
            c = b1[1];            
        }
    }

    else{
        for (i; i<maxi; i++){
            b1 = binadd('0', b[lb-1-i], c);
            s = b1[0] + s;
            c = b1[1];            
        }
    }

    if (c == "1"){s = "1" + s;}

    return s;
}


int main(){
    
    return 0;
}