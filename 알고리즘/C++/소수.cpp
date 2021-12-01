#include <string>
#include <vector>

using namespace std;

string translation(int n, int k) {
    string ret = "";
    while (n != 0) {
        int cur = n % k;    //현재 자릿수
        n /= k;
        ret += (char)(cur + 48);
    }
    string temp;
    int size = ret.size();
    for (int i = 0; i < size; i++) {
        temp += ret[size - i - 1];
    }
    return temp;
}
bool find_prime(string cur) {
    if (cur == "")
        return false;
    int num = stoi(cur);
    bool ret = true;
    if (num == 1)
        ret = false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            if (num == i)
                break;
            ret = false;
            break;
        }
    }
    return ret;
}
int solution(int n, int k) {
    int answer = 0;
    string num = translation(n, k);
    int size = num.size();
    int i = 0;
    while (i < size) {
        string cur = "";
        while (num[i] != '0'&&i<size) {
            cur += num[i];
            i++;
        }
        bool check = find_prime(cur);
        if (check) {
            answer++;
        }
        i++;
    }
    return answer;
}
