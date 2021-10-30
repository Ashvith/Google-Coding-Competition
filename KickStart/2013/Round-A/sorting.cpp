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

vector<int> getFinal(vector<int> original, vector<int> odd, vector<int> even, int N) {
    vector<int> final;
    for(auto i: original) {
        if (i%2 == 0) {
            final.push_back(even.front());
            even.erase(even.begin());
        }
        else {
            final.push_back(odd.front());
            odd.erase(odd.begin());
        }
    }
    return final;
}

void clearVectors(vector<int> &original, vector<int> &odd, vector<int> &even, vector<int> &final) {
    original.clear();
    odd.clear();
    even.clear();
    final.clear();
}

int main() {
    int T, N;
    vector<int> original, even, odd, final;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        original = inputOriginal(N);
        splitAndSortOddandEven(original, odd, even, N);        
        final = getFinal(original, odd, even, N);
        cout << "Case #" << i+1 << ": ";
        for (auto z:final) cout << z << " ";
        cout << endl;
        clearVectors(original, odd, even, final);
    }
}