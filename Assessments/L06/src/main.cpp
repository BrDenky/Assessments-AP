#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <CLI/CLI.hpp>
#include <barkeep/progress.hpp>
#include "data_analyzer.h"

int main(int argc, char** argv) {
    // Parse command line arguments using CLI11
    CLI::App app{"Online Retail Data Analyzer"};
    
    std::string filename;
    std::string country;
    bool onlyUK = false;
    
    app.add_option("-f,--file", filename, "Input CSV file")->required();
    app.add_option("-c,--country", country, "Filter transactions by country");
    app.add_flag("--only-uk", onlyUK, "Calculate total amount only for UK transactions");
    
    CLI11_PARSE(app, argc, argv);
    
    // Create data analyzer
    DataAnalyzer analyzer(filename);
    
    // First analysis: Transactions per country
    std::cout << "\n=== ANALYSIS 1: Transactions per country ===" << std::endl;
    auto countryTransactions = analyzer.countTransactionsByCountry(country);
    
    if (country.empty()) {
        for (const auto& [c, count] : countryTransactions) {
            std::cout << c << ": " << count << " transactions" << std::endl;
        }
    } else {
        if (countryTransactions.find(country) != countryTransactions.end()) {
            std::cout << country << ": " << countryTransactions[country] << " transactions" << std::endl;
        } else {
            std::cout << "No transactions found for country: " << country << std::endl;
        }
    }
    
    // Second analysis: Total amount of transactions
    std::cout << "\n=== ANALYSIS 2: Total transaction amount ===" << std::endl;
    double totalAmount = analyzer.calculateTotalAmount(onlyUK);
    
    if (onlyUK) {
        std::cout << "Total amount for UK transactions: £" << totalAmount << std::endl;
    } else {
        std::cout << "Total amount for all transactions: £" << totalAmount << std::endl;
    }
    
    return 0;
}