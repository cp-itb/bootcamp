const int INF = 1e9;

struct maxQueue {
    deque<int> dq;

    void add(int x) {
        while (!dq.empty() && dq.back() < x)
            dq.pop_back();
        dq.emplace_back(x);
    }

    void remove(int x) {
        if (!dq.empty() && dq.front() == x)
            dq.pop_front();
    }

    int maxi() {
        if (dq.empty())
            return -INF;
        return dq.front();
    }
};
