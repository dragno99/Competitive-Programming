#include "bits/stdc++.h"

using namespace std;

struct Matrix{
    private:
        vector<vector<int>> v;
        int n;
        const int mod = 1e9 + 7;
    public:
        Matrix(int n){
            this->n = n;
            v.assign(n,vector<int>(n,0));
        }
        Matrix(vector<vector<int>> &arr){
            this->n = arr.size();
            v = arr;
        }
        void init(){
            v.assign(n,vector<int>(n,0));
            for(int i=0;i<n;i++) v[i][i]=1;
        }
        void operator *= (const Matrix &a){
            Matrix res(n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        res.v[i][j] = (res.v[i][j] + ((long long int)this->v[i][k] * a.v[k][j] ) % mod );
                        if(res.v[i][j]>=mod) res.v[i][j]-=mod;
                    }
                }
            }
            v = res.v;
        }
        Matrix operator* (Matrix const &a){
            Matrix res(this->n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        res.v[i][j] = (res.v[i][j] + ((long long int)this->v[i][k] * a.v[k][j] ) % mod );
                        if(res.v[i][j]>=mod) res.v[i][j]-=mod;
                    }
                }
            }
            return res;
        }
        void operator= (Matrix const &a){
            this->v = a.v;
        }
        Matrix operator^ (long long int n){
            Matrix res(this->n);
            res.init();
            Matrix a(this->v);
            while(n>0){
                if(n&1) res *= a ;
                a *= a;
                n/=2;
            }
            return res;
        }
        int get(int i, int j){
            return v[i][j];
        }
        void print(){
            for(auto &i: v){
                for(auto &j: i) cout << j<<" ";
                cout <<"\n";
            }
        }
};



void __sol(){
    string a,b; cin >>a  >> b;
    int k ; cin >> k;
    const int mod = 1e9 + 7;
    if(a.size()!=b.size()){
        cout << 0;
        return;
    }
    int same=0 , diff=0;
    int n = a.size();
    for(int i=0;i<n;i++){
        bool hit = 1;
        for(int j=0;j<n && hit;j++){
            if( a[(i+j)%n] != b[j] ) hit=0;
        }
        same+= hit;
    }
    diff = n - same;
    vector<vector<int>> temp = {{diff-1,diff} , {same,same-1} };
    int p = (a!=b) , q = (a==b);
    Matrix aa(temp);
    Matrix res = aa^k;
    cout << ( ((long long int)res.get(1,0)*p)%mod + ( (long long int)res.get(1,1)*q)%mod )%mod;

}


int main(){
    __sol();
    return 0;
}