using namespace std;
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int parent[100];
void make(int v){
    parent[v]=v;
}

int find(int v){
    if (v==parent[v]) return v;
    //path compression
    return parent[v]=find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a!=b){
        //Union by size
        if (size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        make(i);
    }
    while (k--){
        int u, v;
        cin>>u,v;
        Union(u,v);
    }

    int connected_ct = 0;
    for (int i =1; i<=n;++i){
        if (find(i)==i) connected_ct++;
    }
}