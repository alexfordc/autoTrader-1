/**
 * portfolio_entry.cpp
 **/

#include <portfolio_entry.hpp>

using namespace std;

namespace autoTrader
{
    PortfolioEntry::PortfolioEntry(vector<string> vec, time_t timeStamp)
    {
        this->timeStamp = timeStamp;
        this->ticker = vec[0];
        this->stockName = (vec.size() > 1) ? vec[1] : "NULL";
        this->position = (vec.size() > 2) ? atoi(vec[2].c_str()) : 0;

        this->avgPrice = (vec.size() > 3) ? atof(vec[3].c_str()) : -1;
        this->pnl = (vec.size() > 4) ? atof(vec[4].c_str()) : -1;
        this->cashPnl = (vec.size() > 5) ? atof(vec[5].c_str()) : -1;
        this->currentPrice = (vec.size() > 6) ? atof(vec[6].c_str()) : -1;
    }

    PortfolioEntry::~PortfolioEntry()
    {
        
    }

    string PortfolioEntry::toString()
    {
        return ("ticker: " + ticker + 
                "\nstockName: " + stockName + 
                "\nposition: " + to_string(position) + 
                "\navgPrice: " + to_string(avgPrice) +
                "\npnl: " + to_string(pnl) +
                "\ncashPnl: " + to_string(cashPnl) +
                "\ncurrentPrice: " + to_string(currentPrice) +
                "\ntimeStamp: " + asctime(gmtime(&timeStamp)));
    }

    string PortfolioEntry::toCsvString()
    {
        return (ticker + "," + stockName + "," + to_string(position) + "," 
                + to_string(avgPrice) + "," + to_string(pnl) + ","
                + to_string(cashPnl) + "," + to_string(currentPrice) + ","
                + to_string(timeStamp));
    }

    vector<string> PortfolioEntry::entryToVector()
    {
        vector<string> vec(8, "");

        vec[0] = ticker;
        vec[1] = stockName;
        vec[2] = to_string(position);
        vec[3] = to_string(avgPrice);
        vec[4] = to_string(pnl);
        vec[5] = to_string(cashPnl);
        vec[6] = to_string(currentPrice);
        vec[7] = to_string(timeStamp);

        return vec; 
    }

    string PortfolioEntry::getTicker()
    {
        return ticker;
    }

    string PortfolioEntry::getStockName()
    {
        return stockName;
    }

    int PortfolioEntry::getPosition()
    {
        return position;
    }

    float PortfolioEntry::getAvgPrice()
    {
        return avgPrice;
    }

    float PortfolioEntry::getPnl()
    {
        return pnl;
    }

    float PortfolioEntry::getCashPnl()
    {
        return cashPnl;
    }

    float PortfolioEntry::getCurrentPrice()
    {
        return currentPrice;
    }
}//namespace autoTrader
