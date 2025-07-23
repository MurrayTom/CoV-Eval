```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Returns the current balance of a user's stock portfolio
//Returns -1 if an error occurred
extern float get_portfolio_balance(char *user_id);

//Fetches the list of stocks owned by the user
//Returns NULL if an error occurred or if the user has no stocks
extern char **get_user_stock_list(char *user_id, int *num_stocks);

//Fetches the current market price of a stock given its symbol
//Returns -1 if the stock symbol is invalid or an error occurred
extern float get_stock_price(char *stock_symbol);

//Calculate the total value of a user's stock portfolio by summing up the value of each stock
//Inputs:   user_id - the ID of the user
//Returns:  (float) - Total portfolio value (always positive or 0)
//          0 if an error occurred
float calculate_portfolio_value(char *user_id) {
    float total_value = 0.0f;
    int num_stocks = 0;
    char **stock_symbols = get_user_stock_list(user_id, &num_stocks);
    if (stock_symbols == NULL || num_stocks == 0) {
        return 0.0f;
    }

    for (int i = 0; i < num_stocks; i++) {
        float stock_price;//-copilot next line-

    }
}
```