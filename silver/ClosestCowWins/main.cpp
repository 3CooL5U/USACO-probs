#include <bits/stdc++.h>
using namespace std;

int K, M, N, rival[200005];
pair<int,int> grass[200005];
vector<long long> increases;

int main() {
    cin >> K >> M >> N;
    /*for(int i = 0; i < K; i++)
        cin >> grass[i].first >> grass[i].second;
    for(int i = 0; i < M; i++)
        cin >> rival[i];

    sort(grass, grass + K);
    sort(rival, rival + M);

    int current = 0;
    long long score = 0, one = 0, two = 0;
    while (grass[current].first < rival[0]) {
        score += grass[current].second;
        current++;
    }
    increases.push_back(score);

    for(int i = 0; i < M - 1; i++){
        score = 0, one = 0, two = 0;
        int left = current, q = current;

        while(q < K && grass[q].first < rival[i+1]) {
            two += grass[q].second;
            q++;
        }


        while(left < K && current < K && grass[current].first < rival[i+1] && grass[left].first < rival[i+1]) {
            while (current < K && (grass[current].first - grass[left].first) * 2 < rival[i+1] - rival[i] - 1) {
                score += grass[current].second;
                current++;
            }
            one = max(one, score);
            score -= grass[left].second;
            left++;
        }
        increases.push_back(one);
        increases.push_back(two - one);
    }

    score = 0;
    while(current < K){
        score += grass[current].second;
        current++;
    }
    increases.push_back(score);

    sort(increases.begin(), increases.end());
    reverse(increases.begin(), increases.end());

    int count = 0;
    long long ans = 0;
    while(count < N){
        ans += increases[count];
        count++;
    }
    cout << ans;
    */




    vector<pair<int, int>> patches(K + M); // patches and Nhoj's cows
    for (int i = 0; i < K; ++i)
        cin >> patches[i].first >> patches[i].second;
    for (int i = K; i < K + M; ++i) {
        cin >> patches[i].first;
        patches[i].second = -1;
    }
    sort(begin(patches), end(patches));
    vector<uint64_t> increases;
    int last_i = -1;
    uint64_t sum_range = 0;
    for (int i = 0; i < (int)patches.size(); ++i) {
        if (patches[i].second == -1) {
            if (last_i == -1) { // try placing to left of Nhoj's leftmost cow
                increases.push_back(sum_range);
            } else {
                uint64_t cur_ans_1 = 0;	 // current sum of window
                uint64_t best_ans_1 = 0; // best sum over all windows
                for (int j = last_i + 1, r = last_i + 1; j < i; ++j) {
                    // assume j is the leftmost patch in the window
                    while (r < i && (patches[r].first - patches[j].first) * 2 < patches[i].first - patches[last_i].first) {
                        cur_ans_1 += patches[++r].second;
                    }
                    // window sum is now sum(tastinesses(j..r))
                    best_ans_1 = max(best_ans_1, cur_ans_1);
                    cur_ans_1 -= patches[j].second;
                }
                // answer for one cow
                increases.push_back(best_ans_1);
                // answer for two cows - answer for one cow
                increases.push_back(sum_range - best_ans_1);
            }
            last_i = i;
            sum_range = 0;
        } else {
            sum_range += patches[i].second;
        }
    }
    // try placing to right of Nhoj's rightmost cow
    increases.push_back(sum_range);
    // sort in decreasing order
    sort(rbegin(increases), rend(increases));
    increases.resize(N);
    long long ans = 0;
    for (auto val : increases)
        ans += val;
    cout << ans;
}
