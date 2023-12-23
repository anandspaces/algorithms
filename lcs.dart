int max(int a, int b){
    return a>b?a:b;
}
int lcs(String X, String Y, int m, int n){
    if (m == 0 || n == 0)
        return 0;
    else if (X[m-1] == Y[n-1])
        return (1 + lcs(X, Y, m-1, n-1));
    else 
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
    
}
int main(){
    String s1 = "AGGTAB";
    String s2 = "GXTXAYB";
    int m = s1.length;
    int n = s2.length;
    print("Length of LCS is ${lcs(s1, s2, m, n)}");
    return 0;
}