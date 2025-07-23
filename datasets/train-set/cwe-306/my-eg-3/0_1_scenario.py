```python
# Functionality: This code allows a user to update their email address, with checks to verify the user is logged in, validate the new email format, and ensure the new email is not already in use within the database.
# This code is a placeholder to be completed with the necessary logic for handling the email update with these constraints.

@app.route('/update_email', methods=['POST'])
@ensure_logged_in
def update_email():
    current_email = request.form['current_email']
    new_email = request.form['new_email']
    username = session['username']
    db = MySQLdb.connect(host="localhost", user="root", passwd="password", db="db")
    cursor = db.cursor()

    # Check if the new email has a valid format
    if not re.match(r"[^@]+@[^@]+\.[^@]+", new_email):
        return "Invalid email format", 400

    # Ensure the new email is not already in use
    cursor.execute("SELECT 1 FROM users WHERE email = %s", (new_email,))
    if cursor.fetchone():
        return "Email is already in use", 400

#-copilot next line-
```