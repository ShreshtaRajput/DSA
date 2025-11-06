class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int c){
        parent.resize(c+1);
        size.resize(c+1);
        for(int i = 1; i <= c; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int uParent_u = findUltimateParent(u);
        int uParent_v = findUltimateParent(v);

        if(uParent_u == uParent_v) return;

        if(size[uParent_u] < size[uParent_v]){
            parent[uParent_u] = uParent_v;
            size[uParent_v] += size[uParent_u];
        }else{
            parent[uParent_v] = uParent_u;
            size[uParent_u] += size[uParent_v];            
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        for(auto &con: connections){
            // Making connected components
            dsu.unionBySize(con[0],con[1]);
        }

        vector<bool> online(c+1, true); //To mark the online systems
        vector<int> offline(c+1, 0);    //To keep track of the number of times a system goes offline

        for(auto &q: queries){
            if(q[0] == 2){  //If offline
                online[q[1]] = false;
                offline[q[1]]++;
            }
        }

        // Now we need to keep track of the smallest id in a connected component
        vector<int> smallestIdStation(c+1, -1);

        for(int i = 1; i <= c; i++){
            // for each node, look for its parent
            int parent = dsu.findUltimateParent(i);
            int station = smallestIdStation[parent];
            // If the system is online
            if(online[i]){
                if(station == -1 || station > i){
                    smallestIdStation[parent] = i;
                }
            }
        }

        vector<int> res;

        // Now we reverse track all our queries
        for(int i = queries.size() - 1; i >= 0; i--){
            int status = queries[i][0];
            int x = queries[i][1];

            int parent = dsu.findUltimateParent(x);
            int station = smallestIdStation[parent];

            if(status == 1){
                if(online[x]){      //If the system is online, push itself
                    res.push_back(x);
                }else{      //Else push the smallest id station
                    res.push_back(station);
                }
            }

            if(status == 2){
                if(offline[x] > 1){
                    offline[x]--;      //Reduce the offline count
                }else{
                    online[x] = true;   //If offline[x] = 0 -> the system is now online
                    // Assign the smallest id to the station
                    if(station == -1 || station > x){
                        smallestIdStation[parent] = x;
                    }
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};