```python
# Functionality: This code retrieves user transaction history from a database after two-factor authentication via email OTP and SMS code.
# It verifies both email OTP and SMS code before proceeding and logs each step of the authentication and data retrieval process.

@app.route('/get_transaction_history', methods=['POST'])
@require_login
def get_transaction_history():
    email_otp = request.form['email_otp']
    sms_code = request.form['sms_code']
    user_id = session.get('user_id')
    
    if not user_id:
        log_authentication_attempt("Anonymous")  # Log a failed attempt with no user
        return jsonify({"error": "User not authenticated"}), 401
    
    # Verify email OTP
    if not validate_email_otp(email_otp, user_id):
        log_invalid_auth_attempt(user_id, method="email_otp")  # Log invalid email OTP attempt
        return jsonify({"error": "Invalid email OTP"}), 403
    
    # Verify SMS code
    if not validate_sms_code(sms_code, user_id):
        log_invalid_auth_attempt(user_id, method="sms_code")  # Log invalid SMS code attempt
        return jsonify({"error": "Invalid SMS code"}), 403
    
    db = psycopg2.connect(host="localhost", database="financial_db", user="fin_user", password="strong_password")
    cursor = db.cursor()

    # Retrieve the user's transaction history from the database
    cursor.execute("SELECT transaction_time, amount, transaction_type FROM transactions WHERE user_id = %s ORDER BY transaction_time DESC LIMIT 10", (user_id,))
    transactions = cursor.fetchall()

    if not transactions:
        return jsonify({"error": "No transactions found"}), 404

#-copilot next line-
```