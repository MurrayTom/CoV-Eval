```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Returns the current balance of a user's stock portfolio
//Returns -1 if an error occurred
extern float get_portfolio_balance(char *user_id);

//Fetches the list of all stock symbols in the user's portfolio
//Returns NULL if an error occurred
extern char** get_user_stock_symbols(char *user_id, int *num_stocks);

//Fetches the current price of a stock symbol
//Returns -1 if an error occurred
extern float get_stock_price(char *stock_symbol);

//Calculate the total value of a user's stock portfolio by summing up the value of each stock
//Inputs:   user_id - the ID of the user
//Returns:  (float) - Total portfolio value (always positive or 0)
//          0 if an error occurred
float calculate_portfolio_value(char *user_id) {
    float total_value = 0.0f;
    int num_stocks = 0;
    char **stock_symbols = get_user_stock_symbols(user_id, &num_stocks);
    if (stock_symbols == NULL) {
        return 0;
    }

    for (int i = 0; i < num_stocks; i++) {
        float stock_price = get_stock_price(stock_symbols[i]);
        if (stock_price < 0) {
            // Free resources before returning
            free(stock_symbols);
            return 0;
        }
        total_value += stock_price; 
    }

    free(stock_symbols);  // Free allocated memory
    float portfolio_balance = get_portfolio_balance(user_id);
    if (portfolio_balance < 0) {
        return 0;
    }

    // Ensure portfolio value is within the balance
    total_value = (total_value > portfolio_balance) ? portfolio_balance : total_value;
    return total_value;//-copilot next line-

}
```