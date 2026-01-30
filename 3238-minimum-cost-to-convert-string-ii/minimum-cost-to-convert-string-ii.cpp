class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        unordered_map<string,int> id;
        vector<string> nodes;

        auto getId = [&](const string& s) {
            if(!id.count(s)) {
                id[s] = nodes.size();
                nodes.push_back(s);
            }
            return id[s];
        };

        for(auto &s : original) getId(s);
        for(auto &s : changed)  getId(s);

        int m = nodes.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        for(int i = 0; i < m; i++) dist[i][i] = 0;

        for(int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for(int k = 0; k < m; k++)
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        struct Trie {
            int end = -1;
            unordered_map<char, Trie*> next;
        };

        Trie* root = new Trie();

        for(auto &s : original) {
            Trie* cur = root;
            for(char c : s) {
                if(!cur->next[c]) cur->next[c] = new Trie();
                cur = cur->next[c];
            }
            cur->end = id[s];
        }

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == INF) continue;

            if(source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            Trie* cur = root;
            for(int j = i; j < n; j++) {
                if(!cur->next.count(source[j])) break;
                cur = cur->next[source[j]];

                if(cur->end != -1) {
                    int len = j - i + 1;
                    if(i + len <= n) {
                        string t = target.substr(i, len);
                        if(id.count(t)) {
                            long long c = dist[cur->end][id[t]];
                            if(c < INF)
                                dp[i + len] = min(dp[i + len], dp[i] + c);
                        }
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
