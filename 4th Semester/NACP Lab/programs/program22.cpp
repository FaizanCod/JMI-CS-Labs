#include <iostream>
using namespace std;

int main() {
    cout<<"\nFAIZAN CHOUDHARY\n20BCS021\n";

    int box[] = {
        2, 10, 20 , 5, 5, 2, 20, 50, 50, 2,
        10, 20, 50, 5, 10, 2, 2, 20, 10, 20, 
        5, 2, 50, 5, 10, 2, 2, 50, 10, 10,
        2, 5, 50, 50, 10, 2, 20, 10, 20, 5
    };

    int twoRupeeCoins = 0;
    int fiveRupeeCoin = 0;
    int tenRupeeCoins = 0;
    int twentyRupeeCoins = 0;
    int fiftyRupeeCoins = 0;

    for (int i=0; i<50; i++) {
        switch(box[i]) {
            case 2:
                twoRupeeCoins++;
                break;
            case 5:
                fiveRupeeCoin++;
                break;
            case 10:
                tenRupeeCoins++;
                break;
            case 20:
                twentyRupeeCoins++;
                break;
            case 50:
                fiftyRupeeCoins++;
                break;
        }
    }

    int sum_twoRupeeCoins = twoRupeeCoins * 2;
    int sum_fiveRupeeCoin = fiveRupeeCoin * 5;
    int sum_tenRupeeCoins = tenRupeeCoins * 10;
    int sum_twentyRupeeCoins = twentyRupeeCoins * 20;
    int sum_fiftyRupeeCoins = fiftyRupeeCoins * 50;

    cout<<"\nIn the box there are:\n";
    cout<<"\nTwo Rupee Coins: "<<twoRupeeCoins<<"\t"<<"Total: "<<sum_twoRupeeCoins;
    cout<<"\nFive Rupee Coins: "<<fiveRupeeCoin<<"\t"<<"Total: "<<sum_fiveRupeeCoin;
    cout<<"\nTen Rupee Coins: "<<tenRupeeCoins<<"\t"<<"Total: "<<sum_tenRupeeCoins;
    cout<<"\nTwenty Rupee Coins: "<<twentyRupeeCoins<<"\t"<<"Total: "<<sum_twentyRupeeCoins;
    cout<<"\nFifty Rupee Coins: "<<fiftyRupeeCoins<<"\t"<<"Total: "<<sum_fiftyRupeeCoins;

    
    int total_sum = sum_twoRupeeCoins + sum_fiveRupeeCoin + sum_tenRupeeCoins + sum_twentyRupeeCoins + sum_fiftyRupeeCoins;
    cout<<"\n\nTotal sum of all the coins: "<<total_sum;

    return 0;
}