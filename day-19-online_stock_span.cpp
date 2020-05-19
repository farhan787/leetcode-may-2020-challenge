// Problem link: https://leetcode.com/problems/online-stock-span

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Time complexity => O(|Queries|)
// Space complexity => O(|Queries|)
class StockSpanner {
    struct Pair {
        int value, index;
        Pair(int index, int value) {
            this->index = index;
            this->value = value;
        }
    };

    int currIndex;
    stack<Pair> stk;

    void insertStock(int price) {
        Pair newStock(currIndex, price);
        stk.push(newStock);
        ++currIndex;
    }

   public:
    StockSpanner() {
        this->currIndex = 0;
    }

    int next(int price) {
        int span = 0;

        // if stack is empty, then just insert new Pair(index, price) and return 1
        if (stk.empty()) {
            insertStock(price);
            return 1;
        }

        // if stk.top().value > price then insert new Pair(index, price) and the answer is 1
        if (!stk.empty() && stk.top().value > price) {
            insertStock(price);
            return 1;
        }

        // if stk.top().value <= price then remove all elements from stack until you get a Pair having
        // value grater than current price and then find span by taking the difference of currIndex and stk.top().index
        while (!stk.empty() && stk.top().value <= price) {
            stk.pop();
        }

        if (!stk.empty()) {
            span = currIndex - stk.top().index;
        } else {
            span = currIndex + 1;
        }
        insertStock(price);

        return span;
    }
};

int main() {
}
