#include <iostream>

struct Team {
    int id;
    int solved;
    long long penalty;
};

void merge(Team* a, int l, int m, int r) {
    int n1 = m - l +1;
    int n2 = r - m;
    Team L[n1];
    Team R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        int take_left = 0;
        if (L[i].solved > R[j].solved) take_left = 1;
        else if (L[i].solved == R[j].solved) {
            if (L[i].penalty < R[j].penalty) take_left = 1;
            else if (L[i].penalty == R[j].penalty && L[i].id < R[j].id) take_left = 1;
        }
        if (take_left == 1) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Team* a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int num_teams, num_problems;
    std::cin >> num_teams >> num_problems;
    int num_logs;
    std::cin >> num_logs;
    int accept[1001][21];
    int wrong[1001][21];
    for (int i = 0; i <= num_teams; i++){
        for (int j = 0; j <= num_problems; j++){
            accept[i][j] = -1;
            wrong[i][j] = 0;
        }
    }
    for (int i = 0; i < num_logs; i++) {
        int m, id, t, v;
        std::cin >> m >> id >> t >> v;
        if (accept[id][t] == -1) {
            if (v == 1) {
                accept[id][t] = m;
            } else {
                wrong[id][t] ++;
            }
        }
    }

    Team teams[num_teams];
    for (int i = 0; i < num_teams; i++) {
        teams[i].id = i +1;
        teams[i].solved = 0;
        teams[i].penalty = 0;
        for (int j = 1; j <= num_problems; j++) {
            if (accept[teams[i].id][j] != -1) {
                teams[i].solved += 1;
                teams[i].penalty += accept[teams[i].id][j] + 20LL * wrong[teams[i].id][j];
            }
        }
    }
    mergeSort(teams, 0, num_teams-1);

    int rank = 1;
    for (int i = 0; i < num_teams; i++) {
        if (i > 0) {
            if (teams[i].solved < teams[i-1].solved || (teams[i].solved == teams[i-1].solved && teams[i].penalty > teams[i-1].penalty)) {
                rank = i +1;
            }
        }
        std::cout << rank << " " << teams[i].id << " " << teams[i].solved << " " << teams[i].penalty << std::endl;
    }

    return (0);
}
