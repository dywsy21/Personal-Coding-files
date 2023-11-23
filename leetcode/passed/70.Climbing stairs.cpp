int climbStairs(int n) {
    if(n<=3) return n;
    return climbStairs(n-1)*2+climbStairs(n-2)*5;
}