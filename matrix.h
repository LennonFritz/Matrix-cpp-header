#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <bits/stdc++.h>
using namespace std;
template<typename T> class Matrix{
    public:
        vector< vector<T> > matrix;
        
        void read(){
            cin >> ln >> col;
            for(int i = 0; i < col; i++){
                for(int j = 0; j < ln; j++){
                    cin >> tmp;
                    swp.push_back(tmp);
                }
                matrix.push_back(swp);
                swp.clear();
            }
        }
        void print(){
            setCR();
            for(int i = 0; i < col; i++){
                for(int j = 0; j < ln; j++){
                    cout << matrix[i][j] << ' ';
                }
                cout << endl;
            }
        }
        void transpose(){
            vector< vector<T> > temp;
            swap(ln,col);
            for(int i = 0; i < col; i++){
                for(int j = 0; j < ln; j++){
                    tmp = matrix[j][i];
                    swp.push_back(tmp);
                }
                temp.push_back(swp);
                swp.clear();
            }
            
            matrix.clear();
            matrix = temp;
        }
        //Not effective:
        void pprint(){
            setCR();
            int ML = getMaxLength();
            
            for(int i = 0; i < col; i++){
                for(int j = 0; j < ln; j++){
                    if(i==0 && j == 0) {cout << "┏ ";}
                    else if(i == col - 1 && j == 0) {cout << "┗ ";}
                    else if(j == 0) {cout << "┃ ";}
                    cout << setiosflags(ios::right) << setw(ML + 1) << matrix[i][j] << ' ';
                    if(i == 0 && j == ln - 1) {cout << "┓\n";}
                    else if(i == col - 1 && j == ln - 1) {cout << "┛\n";}
                    else if(j == ln - 1) {cout << "┃\n";}
                }
            }
        }
        
    private:
        int col=0, ln=0;
        T tmp=0;
        vector<T> swp;
        void setCR(){
            ln = this->matrix.size();
            col = this->matrix[0].size();
        }
        int getMaxLength(){
            int tmp1 = 0;
            for(int i = 0; i < col; i++){
                for(int j = 0; j < ln; j++){
                    tmp1 = max(tmp1,digit(matrix[i][j]));
                }
            }
            return tmp1;
        }
        int digit(int a){
            int i = 0;
            while(a /= 10){
                i++;
            }
            return i;
        }
};
template<typename T> vector< vector<T> > operator + (const vector< vector<T> > &a, const vector< vector<T> > &b){
    vector< vector<T> > c;
    if(a.size()==0||b.size()==0){
        return c;
    }
    int lnA = a.size();  
    int colA = a[0].size();  
    int lnB = b.size();  
    int colB = b[0].size();  
    if (colA != colB||lnA != lnB){
        return c;
    }
    c.resize(lnA);  
    for (int i = 0; i < lnA; ++i)  {  
        c[i].resize(lnB);  
    }
    for(int i = 0; i < lnA; i++){
        for(int j = 0; j < lnA; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
template<typename T> vector< vector<T> > operator - (const vector< vector<T> > &a, const vector< vector<T> > &b){
    vector< vector<T> > c;
    if(a.size()==0||b.size()==0){
        return c;
    }
    int lnA = a.size();  
    int colA = a[0].size();  
    int lnB = b.size();  
    int colB = b[0].size();  
    if (colA != colB||lnA != lnB){
        return c;
    }
    c.resize(lnA);  
    for (int i = 0; i < lnA; ++i)  {  
        c[i].resize(lnB);  
    }
    for(int i = 0; i < lnA; i++){
        for(int j = 0; j < lnA; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}
template<typename T> vector< vector<T> > operator * (const vector< vector<T> > &a, const vector< vector<T> > &b){
    vector< vector<T> > c;
    if(a.size()==0||b.size()==0){
        return c;
    }
    int lnA = a.size();  
    int colA = a[0].size();  
    int lnB = b.size();  
    int colB = b[0].size();  
    if (colA != lnB){
        return c;
    }
    c.resize(lnA);  
    for (int i = 0; i < lnA; ++i)  {  
        c[i].resize(colB);  
    }
    for (int i = 0; i < lnA; ++i){  
        for (int j = 0; j < colB; ++j){  
            for (int k = 0; k < colA; ++k){  
                c[i][j] += a[i][k] * b[k][j];  
            }  
        }  
    }  
    return c;
}
#endif
