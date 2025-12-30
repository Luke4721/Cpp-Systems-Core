// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>
// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    double rate {hourly_rate*8};
    // rate
    return rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double price_after = before_discount * (1 - (discount / 100));
    return price_after;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    
    double base = daily_rate(hourly_rate) * 22; // 22 working days per month
    double discounted = apply_discount(base, discount);
    return std::ceil(discounted);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double per_day = apply_discount(daily_rate(hourly_rate), discount);
    return std::floor(budget / per_day);
}
