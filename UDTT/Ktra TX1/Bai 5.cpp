#include<bits/stdc++.h>
using namespace std;

struct Job {
    string jobCode;
    int startTime;
    int duration;
};

// khoi tao danh sach cong viec
void initializeJobs(Job jobs[], int& jobCount) {
    jobs[0] = {"Job001", 8, 120};
    jobs[1] = {"Job002", 9, 60};
    jobs[2] = {"Job003", 10, 90};
    jobs[3] = {"Job004", 11, 180};
    jobs[4] = {"Job005", 13, 240};
    jobs[5] = {"Job006", 14, 150};
    jobCount = 6;
}

// Hien thi danh sach cong viec theo thu tu nguoc lai bang phuong phap de quy
void displayJobsReverse(Job jobs[], int jobCount, int index) {
    if (index < 0) {
        return;
    }

    cout << "Job Code: " << jobs[index].jobCode <<endl;
    cout << "Start Time: " << jobs[index].startTime << endl;
    cout << "Duration: " << jobs[index].duration << endl;
    cout << endl;

    displayJobsReverse(jobs, jobCount, index - 1);
}

// Hien thi tat ca cac phuong phap lay ra 5 cong viec tu ds c bang phuong phap sinh
void generateCombinations(Job jobs[], int jobCount, bool selected[], int index, int selectedCount) {
    if (selectedCount == 5) {
        for (int i = 0; i < jobCount; i++) {
            if (selected[i]) {
                cout << "Job Code: " << jobs[i].jobCode << endl;
            }
        }
        cout << endl;
        return;
    }

    if (index >= jobCount) {
        return;
    }

    selected[index] = true;
    generateCombinations(jobs, jobCount, selected, index + 1, selectedCount + 1);

    selected[index] = false;
    generateCombinations(jobs, jobCount, selected, index + 1, selectedCount);
}

int main() {
    const int MAX_JOBS = 10;
    Job jobs[MAX_JOBS];
    int jobCount;

    initializeJobs(jobs, jobCount);

    cout << "Jobs in reverse order:" << endl;
    displayJobsReverse(jobs, jobCount, jobCount - 1);

    cout << "All combinations of 5 jobs:" << endl;
    bool selected[MAX_JOBS] = {false};
    generateCombinations(jobs, jobCount, selected, 0, 0);

    return 0;
}



