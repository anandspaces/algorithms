#include<iostream>
using namespace std;
int max(int a,int b){
    return (a>b?a:b);
}
int knapsack(int w,int pt[],int wt[],int n){
    if(w==0 || n==0){
        return 0;
    }else if(wt[n-1]>w){
        return knapsack(w,pt,wt,n-1);
    }else{
        return max((pt[n-1]+knapsack(w-wt[n-1],pt,wt,n-1)),knapsack(w,pt,wt,n-1));
    }
}
int main(){
    int profit[] = {60,100,120};
    int weight[] = {10,20,30};
    int w = 50;
    int n = 3;
    cout << knapsack(w,profit,weight,n);   
    return 0;
}