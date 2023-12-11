#include <iostream>

using namespace std;

const int MAX_JOBS = 100;

struct Job {
    char id;
    int deadline;
    int profit;
};

class JobSequencing {
private:
    Job jobs[MAX_JOBS];
    int numJobs;

public:
    JobSequencing(int n) : numJobs(n) {}

    void addJob(char id, int deadline, int profit) {
        jobs[numJobs].id = id;
        jobs[numJobs].deadline = deadline;
        jobs[numJobs].profit = profit;
        ++numJobs;
    }

    void jobSequence() {
        // Sort jobs based on profit in descending order
        sortJobs();

        int result[MAX_JOBS];
        bool slot[MAX_JOBS];

        // Initialize all slots to be available
        for (int i = 0; i < numJobs; ++i) {
            slot[i] = false;
        }

        // Fill the slots in a greedy manner
        for (int i = 0; i < numJobs; ++i) {
            for (int j = min(numJobs, jobs[i].deadline) - 1; j >= 0; --j) {
                if (!slot[j]) {
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }

        printJobSequence(result);
    }

    void sortJobs() {
        for (int i = 0; i < numJobs - 1; ++i) {
            for (int j = 0; j < numJobs - i - 1; ++j) {
                if (jobs[j].profit < jobs[j + 1].profit) {
                    swap(jobs[j], jobs[j + 1]);
                }
            }
        }
    }

    void printJobSequence(const int result[]) {
        int totalProfit = 0;

        cout << "Job sequence with maximum profit:" << endl;

        for (int i = 0; i < numJobs; ++i) {
            if (result[i] != -1) {
                cout << jobs[result[i]].id << " ";
                totalProfit += jobs[result[i]].profit;
            }
        }

        cout << "\nTotal profit: " << totalProfit << endl;
    }
};

int main() {
    int numJobs = 5;

    JobSequencing jobSeq(numJobs);

    jobSeq.addJob('a', 2, 100);
    jobSeq.addJob('b', 1, 19);
    jobSeq.addJob('c', 2, 27);
    jobSeq.addJob('d', 1, 25);
    jobSeq.addJob('e', 3, 15);

    jobSeq.jobSequence();

    return 0;
}
