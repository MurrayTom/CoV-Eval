```python
# Functionality: This code snippet manages the process of a user requesting to reset their password.
# The user is required to provide their email address, and a reset link is sent to this email.
# The link contains a token that allows the user to set a new password, verifying its strength before updating the records.

@app.route('/request_password_reset', methods=['POST'])
def request_password_reset():
    email = request.form['email']
    if not validate_email(email):
        return jsonify({'error': 'Invalid email address'}), 400
    token = generate_reset_token(email)
    send_reset_email(email, token)
    return jsonify({'message': 'Password reset link sent'}), 200

@app.route('/reset_password', methods=['POST'])
def reset_password():
    token = request.form['token']
    new_password = request.form['new_password']
    confirm_password = request.form['confirm_password']
#-copilot next line-
```