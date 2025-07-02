Monte Carlo European Options Pricing
A high-performance C++ implementation of Monte Carlo simulation for pricing European call and put options using the Black-Scholes model.

📊 Overview
This project demonstrates quantitative finance modelling and statistical simulation techniques by implementing a Monte Carlo method for European options valuation. The simulation generates thousands of random price paths to estimate option prices, showcasing both financial mathematics and efficient C++ programming.

🚀 Features
European Call & Put Options: Calculates fair value for both option types

Monte Carlo Simulation: Uses 100,000+ simulations for accurate pricing

Geometric Brownian Motion: Models stock price evolution with drift and volatility

Optimised Performance: Precomputed constants and efficient random number generation

Clean Architecture: Modular design with separate payoff functions

🛠️ Technologies
C++17: Modern C++ with STL containers and algorithms

Statistical Libraries: <random> for Mersenne Twister RNG and normal distribution

Mathematical Computing: <cmath> for exponential and logarithmic operations

Cross-platform: Compatible with GCC, Clang, and MSVC compilers

⚡ Quick Start
Prerequisites
C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)

Standard C++ library

Compilation & Execution
bash
# Compile
g++ -std=c++17 -O3 -o monte_carlo monte_carlo.cpp

# Run
./monte_carlo
Sample Output
text
European Call Price: 10.4502
European Put Price: 5.5734
📈 How It Works
Price Path Generation: Simulates stock price evolution using the risk-neutral measure

Random Sampling: Employs Mersenne Twister for high-quality pseudorandom numbers

Payoff Calculation: Computes option payoffs at expiration

Statistical Estimation: Average payoffs across all simulations

Present Value: Discounts expected payoff using risk-free rate

Mathematical Model
The simulation uses the Black-Scholes framework:

text
S(T) = S(0) * exp((r - σ²/2) * T + σ * √T * Z)
Where:

S(T) = Stock price at expiration

r = Risk-free rate

σ = Volatility

T = Time to maturity

Z = Standard normal random variable

🔧 Configuration
Modify parameters in main() to test different scenarios:

cpp
double S0 = 100.0;      // Initial stock price
double K = 100.0;       // Strike price  
double r = 0.05;        // Risk-free rate (5%)
double sigma = 0.2;     // Volatility (20%)
double T = 1.0;         // Time to expiry (1 year)
int simulations = 100000; // Number of Monte Carlo paths
🎯 Key Skills Demonstrated
Quantitative Finance: Options pricing, risk-neutral valuation, stochastic processes

C++ Proficiency: STL usage, static optimization, memory efficiency

Statistical Computing: Monte Carlo methods, random number generation

Mathematical Modeling: Implementing financial derivatives mathematics

Software Architecture: Clean, modular, and maintainable code design

📚 Applications
This implementation serves as a foundation for:

Risk Management: Portfolio hedging and risk assessment

Trading Systems: Options pricing engines

Financial Research: Academic and quantitative analysis

Interview Preparation: Demonstrates both coding and finance knowledge


Built with: Modern C++17 | Focus: Quantitative Finance & High-Performance Computing
