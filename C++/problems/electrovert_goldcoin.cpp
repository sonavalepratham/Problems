#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        multiset<int> ms;
        for(int i=0; i<n; i++){
            int tmp; cin>>tmp;
            ms.insert(tmp);
        }
        int ans=0;
        while(k--){
            ans+=*--ms.end();
            int tmp = (*--ms.end())/2;
            ms.erase(ms.find(*--ms.end())); 
            ms.insert(tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}