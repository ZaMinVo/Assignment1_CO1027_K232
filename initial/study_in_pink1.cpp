#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//Define
#define checkPassRoad2 if(M1 < V && E2 % 2 || M1 <= 0 && E2 % 2 == 0) {EXP1 = ceil(EXP1 * 1.17); EXP1 = max(0, min(600, EXP1)); HP1 = ceil(HP1 * 0.83);  return road_1(EXP1);}
#define ceil(double) ceil(float(double))

//CheckLimit
int Null = 0;

void checkLimit(int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2){
    HP1 = max(0, min(666, HP1));
    HP2 = max(0, min(666, HP2));
    EXP1 = max(0, min(600, EXP1));
    EXP2 = max(0, min(600, EXP2));
    M1 = max(0, min(3000, M1));
    M2 = max(0, min(3000, M2));
    //max(Low, min(High, x)) == clamp(x, Low, High)
    //clamp  (algorithm)
    return;
}

bool checkLimitE(int & E1, int & E2, int & E3){
    return E1 < 0 || E2 < 0 || E3 < 0 || E1 > 99 || E2 > 99 || E3 > 99;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkLimit(Null, Null , exp1, exp2, Null, Null);
    if(checkLimitE(e1, Null, Null)) return -99;
    const int CASE[7] = {0, 4, 20, 50, 66, 80, 100};
    if(e1 < CASE[1]){
        int c_1[4] = {29, 45, 75, 29 + 45 + 75};
        int d = e1 * 3 + exp1 * 7;
        exp2 += c_1[e1];
        exp1 = (d % 2) ? ceil(exp1 - d / 100.0) : ceil(exp1 + d / 200.0);
    }
    else if(e1 < CASE[6]){
        if(e1 < CASE[2]){
            exp2 += ceil(e1 / 4.0) + 19;
        }
        else if(e1 < CASE[3]){
            exp2 += ceil(e1 / 9.0) + 21;
        }
        else if(e1 < CASE[4]){
            exp2 += ceil(e1 / 16.0) + 17;
        }
        else {
            exp2 += ceil(e1 / 4.0) + 19;
            if(exp2 > 200 || e1 >= CASE[5]){
                exp2 += ceil(e1 / 9.0) + 21;
                if(exp2 > 400 && e1 >= CASE[5]){
                    exp2 += ceil(e1 / 16.0) + 17;
                    exp2 = ceil(exp2 * 1.15);
                    //bonus 15%
                }
            }
        }
        exp1 = exp1 - e1;
    }
    checkLimit(Null, Null , exp1, exp2, Null, Null);
    return exp1 + exp2;
}

// Task 2

double road_1(int EXP1){
    int S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if(EXP1 < S) return (EXP1 / S + 80) / 123.0;
    return 1;
}

double road_2(int & HP1, int & EXP1, int & M1, int E2, int V){
    checkPassRoad2
    if(HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        M1 -= 150;
    }
    else {
        HP1 = ceil(HP1 * 1.1);
        M1 -= 70;
    }
    checkLimit(HP1, Null, EXP1, Null, M1, Null);
    checkPassRoad2
    M1 -= (EXP1 < 400) ? 200 : 120;
    EXP1 = ceil(EXP1 * 1.13);
    checkPassRoad2
    M1 -= (EXP1 < 300) ? 100 : 120;
    EXP1 = ceil(EXP1 * 0.9);
    if(E2 % 2 == 0){
        EXP1 = ceil(EXP1 * 1.17);
        HP1 = ceil(HP1 * 0.83);
        checkLimit(HP1, Null, EXP1, Null, M1, Null);
        return road_1(EXP1);
    }
    return road_2(HP1, EXP1, M1, E2, V);
}

int solveE2(int E2){
    if(E2 < 10) return E2;
    return (E2 / 10 + E2 % 10) % 10;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkLimit(HP1, Null, EXP1, Null, M1, Null);
    if(checkLimitE(Null, E2, Null)) return -99;
    double  P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11},
            P_1 = road_1(EXP1),
            P_2 = road_2(HP1, EXP1, M1, E2, M1 * 0.5),
            P_3 = P[solveE2(E2)] / 100.0;
    if(P_1 + P_2 + P_3 == 3.0) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        double p = (P_1 + P_2 + P_3) / 3.0;
        if(p < 0.5){
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    checkLimit(HP1, Null, EXP1, Null, M1, Null);
    return HP1 + EXP1 + M1;
}

// Task 3

int solveE3(int cnt){
    while(cnt > 9){
        cnt = cnt / 10 + cnt % 10;
    }
    return cnt;
}

pair <int, int> Fill(int array[][Max_Col], int e3){
    int cntRow = 0, cntCol = 0;
    for(int i = 0; i < Max_Row; ++i){
        for(int j = 0; j < Max_Col; ++j){
            array[i][j] = ((e3 * j) + (i * 2)) * (i - j);
            if(array[i][j] > e3 * 2) ++cntRow;
            if(array[i][j] < -e3)  ++cntCol;
        }
    }
    int col = solveE3(cntCol), row = solveE3(cntRow);
    return {row, col};
}

int Scores(int array[][Max_Col], int row, int col, int E3){
    int result = array[row][col];
    for(int i = min(col + row, 9), j = col + row - i; i > j; --i, ++j){
        result = max(result, array[i][j]);
    }
    if(row > col){
        int j = 9 - (row - col), i = 9;
        result = max(result, array[i][j]);
    }
    return result;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkLimit(HP1, HP2, EXP1, EXP2, Null, Null);
    if(checkLimitE(Null, Null, E3)) return -99;
    int matrix[Max_Col][Max_Row] , point;
    pair <int, int> address = Fill(matrix, E3);
    int row = address.first, col = address.second;
    point = Scores(matrix, row, col, E3);
    if(abs(matrix[row][col]) > point){
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
    }
    checkLimit(HP1, HP2, EXP1, EXP2, Null, Null);
    return (abs(matrix[row][col]) > point) ? matrix[row][col] : point;
}

// Task 4

bool checkKey(char s){
    if(s == '!' || s == '@' || s == '#' || s == '$' || s == '%') return true;
    return false;
}

bool checkCase2(char s){
    if(checkKey(s)) return true;
    if(s >= '0' && s <= '9') return true;
    if(s >= 'a' && s <= 'z') return true;
    if(s >= 'A' && s <= 'Z') return true;
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sizeS = strlen(s);
    if(sizeS < 8) return -1;
    if(sizeS > 20) return -2;
    int result = -10, cntKey = 0, c2 = -1;
    if(email[0] == '@') return -300;
    for(int i = 0; i < sizeS; ++i){
        if(s[i] == email[0]){
            for(int j = 1; ; ++j){
                if(email[j] == '@'){
                    result = -(300 + i);
                    return result;
                }
                if(s[i + j] != email[j]) break;
            }
        }
        if(result > -300 && i < sizeS - 2 && s[i] == s[i + 1] && s[i] == s[i + 2]){
            result = -(400 + i);
        }
        if(checkKey(s[i])) cntKey++;
        if(c2 == -1 && !checkCase2(s[i])){
            c2 = i;
        }
    }
    if(result == -10 && cntKey == 0) result = -5;
    if(result == -10 && c2 != -1)  result = c2;
    return result;
}

// Task 5
bool cmp(string A, const char *B){
    if(A.length() != strlen(B)) return false;
    for(int i = 0; i < strlen(B); ++i){
        if(A[i] != B[i]) return false;
    }
    return true;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    pair <string, int> pss[num_pwds];
    //passwork appears
    pair <int, pair <int, int>> res = {0, {0, 0}};
    //address appears length
    int cnt = 0;
    for(int i = num_pwds - 1; i >= 0; --i){
        for(int j = 0; j <= cnt ; ++j){
            if(j == cnt){
                pss[cnt].first = arr_pwds[i];
                pss[cnt].second = 1;
                ++cnt;
                int sizePss = pss[j].first.length();
                if(pss[j].second > res.second.first || pss[j].second == res.second.first && sizePss >= res.second.second){
                    res.first = i;
                    res.second.first = pss[j].second;
                    res.second.second = sizePss;
                }
                break;
            }
            if(cmp(pss[j].first, arr_pwds[i])){
                ++pss[j].second;
                int sizePss = pss[j].first.length();
                if(pss[j].second > res.second.first || pss[j].second == res.second.first && sizePss >= res.second.second){
                    res.first = i;
                    res.second.first = pss[j].second;
                    res.second.second = sizePss;
                }
                break;
            }
        }
    }
    return res.first;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////