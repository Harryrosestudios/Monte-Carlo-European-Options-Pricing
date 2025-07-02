#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <functional>

// Combined payoff function using function pointer
double optionPayoff(double S, double K, bool isCall) {
    return isCall ? std::max(S - K, 0.0) : std::max(K - S, 0.0);
}

// Monte Carlo simulation with precomputed constants
double priceEuropeanOption(
    double spot, 
    double strike, 
    double rate, 
    double vol, 
    double expiry, 
    int num_paths, 
    bool isCall
) {
    // Precompute constants outside loop
    const double drift = (rate - 0.5 * vol * vol) * expiry;
    const double diffusion = vol * std::sqrt(expiry);
    const double discount_factor = std::exp(-rate * expiry);
    
    // Static random setup for efficiency
    static std::mt19937 generator(std::random_device{}());
    std::normal_distribution<double> distribution(0.0, 1.0);
    
    double total_payoff = 0.0;
    
    for (int i = 0; i < num_paths; ++i) {
        // Generate terminal price directly
        double terminal_price = spot * std::exp(drift + diffusion * distribution(generator));
        total_payoff += optionPayoff(terminal_price, strike, isCall);
    }
    
    return discount_factor * (total_payoff / num_paths);
}

int main() {
    // Market parameters
    const double spot_price = 100.0;
    const double strike_price = 100.0;
    const double risk_free_rate = 0.05;
    const double volatility = 0.2;
    const double time_to_expiry = 1.0;
    const int simulations = 100000;
    
    // Price both options
    double call_price = priceEuropeanOption(
        spot_price, strike_price, risk_free_rate,
        volatility, time_to_expiry, simulations, true
    );
    
    double put_price = priceEuropeanOption(
        spot_price, strike_price, risk_free_rate,
        volatility, time_to_expiry, simulations, false
    );
    
    // Output results
    std::cout << "European Call Price: " << call_price << "\n";
    std::cout << "European Put Price: " << put_price << std::endl;
    
    return 0;
}
