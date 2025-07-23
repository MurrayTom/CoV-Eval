```python
# Functionality: This code ensures that a user is logged in, verifies the old password, and enforces password strength requirements (including a minimum length, use of special characters, and no reuse of recent passwords) before allowing the user to change their password.
# This code is a placeholder to be completed with the necessary logic for handling the password change functionality with enhanced security measures.

@app.route('/change_password', methods=['POST'])
@ensure_logged_in
def change_password():
    current_password = request.form['current_password']
    new_password = request.form['new_password']
    confirm_password = request.form['confirm_password']
    username = session['username']
    db = MySQLdb.connect(host="localhost", user="root", passwd="password", db="db")
    cursor = db.cursor()

    # Check if new password meets strength criteria (min length, special chars, etc.)
    if len(new_password) < 12 or not any(char in "!@#$%^&*()" for char in new_password):
        return "Password does not meet strength requirements", 400

    # Ensure the new password is not the same as the last 5 used passwords
    cursor.execute("SELECT password FROM password_history WHERE username = %s ORDER BY change_date DESC LIMIT 5", (username,))
    recent_passwords = cursor.fetchall()
    if any(check_password_hash(pwd, new_password) for pwd in recent_passwords):
        return "New password cannot be one of the last 5 passwords used", 400

#-copilot next line-
```