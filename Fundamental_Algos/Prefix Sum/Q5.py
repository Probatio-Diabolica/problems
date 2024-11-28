def largestAltitude( gain) -> int:
    suum=0
    maxSum=0
    for element in gain:
        suum+=element
        if(maxSum<suum):maxSum=suum
    return maxSum

print(largestAltitude([-5,1,5,0,-7]))
print(largestAltitude([-4-3-2-1,4,3,2]))


"""
better c++ solution :
int largestAltitude(vector<int>& g) {
    for(int i = 0, s = 0; i < g.size() && ((g[0] = max(g[0], s += g[i])) || 1); i++);
    return max(g[0], 0);
}
"""
