#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> inputOriginal(int N) {
    int input;
    vector<int> original;
    for(int i=0; i<N; i++) {
        cin >> input;
        original.push_back(input);
    }
    return original;
}

void splitAndSortOddandEven(vector<int> original, vector<int> &odd, vector<int> &even, int N) {
    for(auto i:original) {
        if (i%2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());
}

vector<int> getAnswer(vector<int> original, vector<int> odd, vector<int> even, int N) {
    vector<int> answer;
    for(auto i: original) {
        if (i%2 == 0) {
            answer.push_back(even.front());
            even.erase(even.begin());
        }
        else {
            answer.push_back(odd.front());
            odd.erase(odd.begin());
        }
    }
    return answer;
}

void clearVectors(vector<int> &original, vector<int> &odd, vector<int> &even, vector<int> &answer) {
    original.clear();
    odd.clear();
    even.clear();
    answer.clear();
}

int main() {
    int T, N;
    vector<int> original, even, odd, answer;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        original = inputOriginal(N);
        splitAndSortOddandEven(original, odd, even, N);        
        answer = getAnswer(original, odd, even, N);
        cout << "Case #" << i+1 << ": ";
        for (auto z:answer) cout << z << " ";
        cout << endl;
        clearVectors(original, odd, even, answer);
    }
}