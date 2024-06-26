
vector<int> get_phash(int start, int end, string &s, const int &p, const int &M)
{
    vector<int> pre;
    int cur = 1;
    long long hash = 0;
    for (int i = start; i <= end; i++)
    {
        hash = madd(hash, mmul(cur, s[i] - '0', M), M);
        pre.push_back(hash);
        cur = mmul(cur, p, M);
    }
    return pre;
}
 
vector<int> get_shash(int start, int end, string &s, const int &p, const int &M)
{
    vector<int> suf;
    int cur = 1;
    long long hash = 0;
    for (int i = end; i >= start; i--)
    {
        hash = madd(hash, mmul(cur, s[i] - '0', M), M);
        suf.push_back(hash);
        cur = mmul(cur, p, M);
    }
    reverse(suf.begin(), suf.end());
    return suf;
}
 
int get_substring_phash(int start, int end, const int &p, const int &M, vector<int> &pre)
{
    if (start == 0)
    {
        return pre[end];
    }
    int ans = msub(pre[end], pre[start - 1], M);
    // int k = mpow(p, start, M);
    // ans = mdiv(ans, k, M);
    return ans;
}
 
int get_substring_shash(int start, int end, const int &p, const int &M, vector<int> &suf)
{
    int n = suf.size();
    if (end == n - 1)
    {
        return suf[start];
    }
    int ans = msub(suf[start], suf[end + 1], M);
    // int k = mpow(p, n - end, M);
    // ans = mdiv(ans, k, M);
    return ans;
}
