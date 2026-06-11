/*
ALTERNATIVE QUESTION 01.2: Maximize your marks

Write a code for the following scenario using greedy algorithm:
You are attending your mid-term of the course "CS101". The total marks of the exam is M and the total
time is T minutes. You have to answer N questions, where the i-th question carries m_i marks and takes
t_i minutes for you to answer. The marks you receive will be proportional to the percentage of your
answer compared to the full answer, e.g., if a question contains 100 marks and you complete 30% of it,
you will get 30 marks.
a) Find the maximum marks you can get in this exam.
b) Print the questions you have to answer for that.
c) Find the maximum marks you can get in this exam if you are allowed to take the same exam in a
group with your one friend (as long as a question is answered, both of you get marks
irrespective of who answered it) and your friend's answering capacity is exactly the same as you.

Sample Input
120 20 5
20 10
20 5
30 5
30 6
20 40

Sample Output
Maximum 88 marks answering alone
ques 3 100% done -- 30 marks
ques 4 100% done -- 30 marks
ques 2 100% done -- 20 marks
ques 1 40% done -- 8 marks
Maximum 107 marks answering with a friend
*/

#include <bits/stdc++.h>
using namespace std;

struct Question {
    int id;
    double marks;
    double time;
    double ratio;
};

bool compareQuestions(const Question& a, const Question& b) {
    return a.ratio > b.ratio;
}

int main() {
    double m, t;
    int n;
    if (!(cin >> m >> t >> n)) return 0;

    vector<Question> q(n);
    for (int i = 0; i < n; i++) {
        q[i].id = i + 1;
        cin >> q[i].marks >> q[i].time;
        q[i].ratio = q[i].marks / q[i].time;
    }

    sort(q.begin(), q.end(), compareQuestions);

    double timeLeft = t;
    double maxMarksAlone = 0;
    vector<string> soloOutput;

    for (int i = 0; i < n; i++) {
        if (timeLeft <= 0) break;
        if (q[i].time <= timeLeft) {
            timeLeft -= q[i].time;
            maxMarksAlone += q[i].marks;
            soloOutput.push_back("ques " + to_string(q[i].id) + " 100% done -- " + to_string((int)q[i].marks) + " marks");
        } else {
            double percentage = timeLeft / q[i].time;
            double obtained = q[i].marks * percentage;
            maxMarksAlone += obtained;
            soloOutput.push_back("ques " + to_string(q[i].id) + " " + to_string((int)(percentage * 100)) + "% done -- " + to_string((int)obtained) + " marks");
            timeLeft = 0;
        }
    }

    cout << "Maximum " << (int)round(maxMarksAlone) << " marks answering alone\n";
    for (const string& s : soloOutput) {
        cout << s << "\n";
    }

    double collectiveTime = t * 2;
    double maxMarksGroup = 0;

    for (int i = 0; i < n; i++) {
        if (collectiveTime <= 0) break;
        if (q[i].time <= collectiveTime) {
            collectiveTime -= q[i].time;
            maxMarksGroup += q[i].marks;
        } else {
            double percentage = collectiveTime / q[i].time;
            maxMarksGroup += q[i].marks * percentage;
            collectiveTime = 0;
        }
    }
    
    if (maxMarksGroup > m) maxMarksGroup = m;

    cout << "Maximum " << (int)round(maxMarksGroup) << " marks answering with a friend\n";

    return 0;
}