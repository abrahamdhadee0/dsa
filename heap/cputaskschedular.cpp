class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;
        unordered_map<char,int> free;

        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 0;
        }

        priority_queue<pair<int,char>> pq;

        for(auto &it : freq){
            pq.push({it.second, it.first});
        }

        int seat = 0;

        while(!pq.empty()){

            vector<pair<int,char>> pulled;

            bool done = false;

            while(!pq.empty()){

                auto p = pq.top();
                pq.pop();

                int cnt = p.first;
                char child = p.second;

                if(free[child] <= seat){

                    cnt--;

                    if(cnt > 0){

                        pulled.push_back({cnt, child});
                        free[child] = seat + n + 1;
                    }

                    seat++;
                    done = true;
                    break;
                }

                else{
                    pulled.push_back(p);
                }
            }

            for(int i = 0; i < pulled.size(); i++){
                pq.push(pulled[i]);
            }

            // idle
            if(!done){
                seat++;
            }
        }

        return seat;
    }
};