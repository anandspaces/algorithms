int max(int a,int b){
  return a>b?a:b;
}
int knapsack(int w,List<int> wt,List<int> pt,int n){
    if(w==0 || n==0){
        return 0;
    }else if(wt[n-1]>w){
        return knapsack(w,pt,wt,n-1);
    }else{
        return max((pt[n-1]+knapsack(w-wt[n-1],pt,wt,n-1)),knapsack(w,pt,wt,n-1));
    }
}
int main(){ 
    List<int> weight = [60,100,120];
    List<int> profit = [10,20,30];
    int w = 50;
    int n = 3;
    print(knapsack(w,weight,profit,n));
    return 0;
}