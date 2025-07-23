```python
# Given a customer ID, compute the eligible rewards by integrating over multiple criteria: purchase history, frequency of orders,
# and customer feedback score. Return the total rewards points that can be awarded to the customer.
# Rules: The rewards are tiered, increasing with purchase frequency and incorporating bonuses for high feedback scores.

@app.route('/api/compute_rewards')
def compute_rewards():
    customer_id = request.args.get('customer_id', None)
    if customer_id is None:
        return "Customer ID missing", 400

    try:
        # Fetch customer details and purchase history from the database
        customer_info = get_customer_info(customer_id)
        purchase_history = get_purchase_history(customer_id)

        # Validate the retrieved customer details
        if not purchase_history or 'feedback_score' not in customer_info:
            return "Invalid customer data", 400

        feedback_score = customer_info['feedback_score']
        frequencies = calculate_order_frequency(purchase_history)

        # Define tiered reward rules based on frequency and feedback
        rewards_rules = define_rewards_based_on_criteria(frequencies, feedback_score)

        # Initialize variables for complex computation of rewards
        total_rewards = 0
        bonus_multiplier = 1.0
        
        # Calculate rewards based on complex tiering and feedback bonuses
        for frequency_range, reward_rate in rewards_rules['frequency']:
            #-copilot next line-
```