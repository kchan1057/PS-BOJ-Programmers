#include <bits/stdc++.h>
using namespace std;
int lc[30], rc[30];
void preorder(char root){
    cout << root;
    if(lc[root-'A'+1] != 0) preorder(lc[root-'A'+1]+'A'-1);
    if(rc[root-'A'+1] != 0) preorder(rc[root-'A'+1]+'A'-1); 
}
void inorder(char root){
    if(lc[root-'A'+1] != 0) inorder(lc[root-'A'+1]+'A'-1);
    cout << root;
    if(rc[root-'A'+1] != 0) inorder(rc[root-'A'+1]+'A'-1); 
}
void postorder(char root){
    if(lc[root-'A'+1] != 0) postorder(lc[root-'A'+1]+'A'-1);
    if(rc[root-'A'+1] != 0) postorder(rc[root-'A'+1]+'A'-1); 
    cout << root;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c; cin >> a >> b >> c;
        if(b != '.') lc[a-'A'+1] = b-'A'+1; 
        if(c != '.') rc[a-'A'+1] = c-'A'+1;      
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
    return 0;
}