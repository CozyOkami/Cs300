#include "trip.h"
#include <vector>
#include <string>


float moneyEqualizer(std::vector<float> expenses) {
    float total = 0.0;
    for (float expense : expenses) {
        total += expense;
    }

    float share = total / expenses.size();

    std::vector<float> owes(expenses.size(), 0.0);

    for (size_t i = 0; i < expenses.size(); ++i) {
        owes[i] = expenses[i] - share;
    }
    float exchange = 0.0;
    for (float amount : owes) {
            exchange += amount;
    }

    return exchange;
}
