#ifndef DATA_ANALYZER_H
#define DATA_ANALYZER_H

#include <string>
#include <map>
#include <vector>

struct Transaction {
    std::string invoiceNo;
    std::string stockCode;
    std::string description;
    int quantity;
    std::string invoiceDate;
    double unitPrice;
    std::string customerID;
    std::string country;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::string& filename);
    
    // Analysis 1: Count transactions by country
    std::map<std::string, int> countTransactionsByCountry(const std::string& countryFilter = "");
    
    // Analysis 2: Calculate total amount
    double calculateTotalAmount(bool onlyUK = false);
    
private:
    std::string filename;
    std::vector<Transaction> transactions;
    
    void loadData();
};

#endif // DATA_ANALYZER_H