```python
# Functionality: This code snippet is designed to update a user's shipping address. It ensures that the user is logged in, validates the new address format, verifies the address is valid based on external API checks, and ensures that the address is not already in use by another user.
# This code is a placeholder to be completed with the necessary logic for handling the address update with these constraints.

@app.route('/update_shipping_address', methods=['POST'])
@ensure_logged_in
def update_shipping_address():
    current_address = request.form['current_address']
    new_address = request.form['new_address']
    username = session['username']
    db = MySQLdb.connect(host="localhost", user="root", passwd="password", db="db")
    cursor = db.cursor()

    # Check if the new address has a valid format
    if not re.match(r"^[0-9a-zA-Z\s,]+$", new_address):
        return "Invalid address format", 400

    # Verify the new address via an external API
    # This is a sample API check, and the real implementation should handle external requests securely and efficiently
    response = some_external_api_verify_address(new_address)
    if response['status'] != "valid":
        return "Invalid address according to external verification", 400

    # Ensure the new address is not already in use by another user
    cursor.execute("SELECT 1 FROM users WHERE address = %s AND username != %s", (new_address, username))
    if cursor.fetchone():
        return "Address is already in use by another user", 400

#-copilot next line-
```