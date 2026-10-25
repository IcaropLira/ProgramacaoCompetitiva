#include <bits/stdc++.h>
using namespace std;
#define ll long long

void build(int no, int l, int r, vector<ll>& seg, vector<ll>& p){
    if (l == r){
        return;
    }
    int meio = ((l+r) / 2);
    build(no*2, l, meio, seg, p);
    build(no*2+1, meio+1, r, seg, p);
    seg[no] = 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);

    cout << s << "\n";

    return 0;
}