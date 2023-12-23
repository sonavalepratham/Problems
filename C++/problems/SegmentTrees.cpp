#include <bits/stdc++.h>
using namespace std;

void build(int arr[], int segtree[], int s, int e, int idx){
    if(s==e){
        segtree[idx]=s;
        return;
    }
    int mid=(s+e)/2;
    build(arr, segtree, s, mid, 2*idx);
    build(arr, segtree, mid+1, e, 2*idx+1);
    segtree[idx]=segtree[2*idx]+segtree[2*idx+1];
}

void update(int arr[], int segtree[], int s, int e, int ip, int val, int idx){
    if(s==e and s==ip){
        arr[ip]=val;
        segtree[idx]=val;
        return ;
    }
    int mid=(s+e)/2;
    if(mid>=ip) update(arr, segtree, s, mid, ip, val, 2*idx);
    else update(arr, segtree, mid+1, e, ip, val, 2*idx+1);
    segtree[idx]=segtree[2*idx]+segtree[2*idx+1];
}

int query(int segtree[], int s, int e, int l, int r, int tidx){
    if(s>r or e<l){
        return 0;
    }
    if(s>=l and e<=r) return segtree[tidx];
    int s1, s2, mid=(s+e)/2;
    s1=query(segtree, s, mid, l, r, 2*tidx);
    s2=query(segtree, mid+1, e, l, r, 2*tidx+1);
    return s1+s2;
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int arr[n], segtree[4*n];
    for(int i=0; i<n; i++) cin>>arr[i];
    build(arr, segtree, 0, n-1, 1);
    int q; cin>>q;
    while(q--){
        int qtype; cin>>qtype;
        if(qtype==1){
            // update
            int i, val; cin>>i>>val;
            update(arr, segtree, 0, n-1, i, val, 1);
        }
        else if(qtype==2){
            // show
            int l, r;
            cin>>l>>r;
            cout<<query(segtree, 0, n-1, l, r, 1)<<"\n";
        }
    }
    return 0;
}