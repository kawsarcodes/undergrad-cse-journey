/*
ALTERNATIVE QUESTION 02.1:

Suppose you are managing a multipurpose hall of your university, where seminars, lectures, and even
cultural events are held. N clubs have sent you booking requests for their events tomorrow. Each
booking request contains the club id (c_i), the start time (s_i) and the duration (d_i) of the events.
Approve the booking requests such that you can accommodate maximum events tomorrow, without
creating conflict. Note that, after an event you need X hour to clean up and prepare for the next event.

Sample input
4
a 2 8
b 3 4
d 8 1
c 7 1
0

Sample output
Chosen clubs:
b
c
d
*/

#include <bits/stdc++.h>
using namespace std;

struct Event {
    string clubId;
    int start;
    int duration;
    int finish;
};

bool compareEvents(const Event& a, const Event& b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Event> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].clubId >> events[i].start >> events[i].duration;
        events[i].finish = events[i].start + events[i].duration;
    }

    int x;
    cin >> x;

    sort(events.begin(), events.end(), compareEvents);

    vector<string> chosenClubs;
    if (n > 0) {
        chosenClubs.push_back(events[0].clubId);
        int lastFinishWithBuffer = events[0].finish + x;

        for (int i = 1; i < n; i++) {
            if (events[i].start >= lastFinishWithBuffer) {
                chosenClubs.push_back(events[i].clubId);
                lastFinishWithBuffer = events[i].finish + x;
            }
        }
    }

    cout << "Chosen clubs:\n";
    for (const string& club : chosenClubs) {
        cout << club << "\n";
    }

    return 0;
}