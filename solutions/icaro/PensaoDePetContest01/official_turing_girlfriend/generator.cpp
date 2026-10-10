#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){

    registerGen(argc,argv,1);

    int n=opt<int>(1);

    int MAX=opt<int>(2);

    int L=rnd.next(1,MAX-100);

    int R=rnd.next(L+1,min(MAX,L+100));

    cout<<n<<"\n";

    cout<<L<<" "<<R<<"\n";

    for(int i=0;i<n-1;i++){

        int l=rnd.next(1,MAX-1);

        int r=rnd.next(l+1,min(MAX,l+100));

        int d=rnd.next(1,MAX);

        char c=rnd.next(0,1)?'L':'R';

        cout<<l<<" "<<r<<" "<<d<<" "<<c<<"\n";

    }

}