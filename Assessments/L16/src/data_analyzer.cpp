#include "data_analyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <barkeep/progress.hpp>

DataAnalyzer::DataAnalyzer(const std::string& filename) : filename(filename) {
    loadData();
}

void DataAnalyzer::loadData() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    // Count total lines for progress bar
    size_t totalLines = 0;
    std::ifstream countFile(filename);
    while (std::getline(countFile, line)) {
        totalLines++;
    }
    countFile.close();
    
    // Reset file position
    file.clear();
    file.seekg(0);
    std::getline(file, line); // Skip header again
    
    // Create progress bar
    barkeep::ProgressBar progressBar(totalLines - 1, "Loading data");
    progressBar.show();
    
    size_t linesProcessed = 0;
    
    // Process each line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        
        Transaction t;
        
        // InvoiceNo
        if (std::getline(ss, token, ',')) {
            t.invoiceNo = token;
        }
        
        // StockCode
        if (std::getline(ss, token, ',')) {
            t.stockCode = token;
        }
        
        // Description (may contain commas, so we need special handling)
        if (ss.peek() == '"') {
            ss.ignore(); // Skip opening quote
            std::getline(ss, token, '"');
            t.description = token;
            ss.ignore(); // Skip comma after closing quote
        } else {
            std::getline(ss, token, ',');
            t.description = token;
        }
        
        // Quantity
        if (std::getline(ss, token, ',')) {
            try {
                t.quantity = std::stoi(token);
            } catch (...) {
                t.quantity = 0;
            }
        }
        
        // InvoiceDate
        if (std::getline(ss, token, ',')) {
            t.invoiceDate = token;
        }
        
        // UnitPrice
        if (std::getline(ss, token, ',')) {
            try {
                t.unitPrice = std::stod(token);
            } catch (...) {
                t.unitPrice = 0.0;
            }
        }
        
        // CustomerID
        if (std::getline(ss, token, ',')) {
            t.customerID = token;
        }
        
        // Country
        if (std::getline(ss, token)) {
            t.country = token;
        }
        
        // Only add valid transactions
        if (!t.invoiceNo.empty() && t.quantity > 0 && t.unitPrice > 0) {
            transactions.push_back(t);
        }
        
        // Update progress
        linesProcessed++;
        progressBar.update(linesProcessed);
    }
    
    progressBar.done();
    std::cout << "Successfully loaded " << transactions.size() << " valid transactions." << std::endl;
}

std::map<std::string, int> DataAnalyzer::countTransactionsByCountry(const std::string& countryFilter) {
    std::map<std::string, int> result;
    
    // Create progress bar
    barkeep::ProgressBar progressBar(transactions.size(), "Counting transactions");
    progressBar.show();
    
    for (size_t i = 0; i < transactions.size(); i++) {
        const auto& transaction = transactions[i];
        
        // If country filter is provided, only count that country
        if (countryFilter.empty() || transaction.country == countryFilter) {
            result[transaction.country]++;
        }
        
        // Update progress
        progressBar.update(i + 1);
    }
    
    progressBar.done();
    return result;
}

double DataAnalyzer::calculateTotalAmount(bool onlyUK) {
    double total = 0.0;
    
    // Create progress bar
    barkeep::ProgressBar progressBar(transactions.size(), "Calculating total amount");
    progressBar.show();
    
    for (size_t i = 0; i < transactions.size(); i++) {
        const auto& transaction = transactions[i];
        
        // If onlyUK flag is set, only calculate for UK transactions
        if (!onlyUK || transaction.country == "United Kingdom") {
            total += transaction.quantity * transaction.unitPrice;
        }
        
        // Update progress
        progressBar.update(i + 1);
    }
    
    progressBar.done();
    return total;
}