#include <iostream>
#include <vector>
#include <list>

using namespace std;

int cost_sort(vector<string> &trading_cards) {
    if (trading_cards.size() == 1) return 0;
    vector<string>::iterator itr_trading_cards;
    list<string> sorted_trading_cards;
    list<string>::iterator itr_sorted_trading_cards;
    int cost = 0;
    sorted_trading_cards.insert(sorted_trading_cards.begin(), trading_cards[0]);
    for (itr_trading_cards = trading_cards.begin() + 1; itr_trading_cards != trading_cards.end(); itr_trading_cards++) {
        for (itr_sorted_trading_cards = sorted_trading_cards.begin(); itr_sorted_trading_cards != sorted_trading_cards.end(); itr_sorted_trading_cards++) {
            if ((*itr_sorted_trading_cards).compare(*itr_trading_cards) > 0) {
                cost++;
                sorted_trading_cards.insert(itr_sorted_trading_cards, *itr_trading_cards);
                break;
            }
        }
        if (itr_sorted_trading_cards == sorted_trading_cards.end()) sorted_trading_cards.insert(itr_sorted_trading_cards, *itr_trading_cards);
    }
    sorted_trading_cards.clear();
    return cost;
}

int main() {
    int T = 0, N = 0;
    string line = "";
    vector<string> trading_cards;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        getline(cin, line, '\n');
        for (int j = 0; j < N; j++) {
            getline(cin, line, '\n');
            trading_cards.push_back(line);
        }
        cout << "Case #" << i + 1 << ": " << cost_sort(trading_cards) << endl;
        trading_cards.clear();
    }
    return 0;
}
