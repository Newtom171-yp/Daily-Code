long long minimumDice(long long x) {
    // Write your code here
    if(x <= 14 ) return -1;
    long long remainder = x%14;
    if(remainder > 6 || !remainder) return -1;
    return x/14;
}