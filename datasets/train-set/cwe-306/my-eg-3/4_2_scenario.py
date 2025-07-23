```python
# Functionality: This code snippet manages an advanced password reset system.
# Users can request a password reset with rate-limiting to prevent abuse.
# The system ensures that the reset token is verified for authenticity and expiration before allowing a reset.
# Additionally, the new password strength is evaluated using advanced criteria including entropy checks.

from flask import jsonify, request
from datetime import datetime, timedelta
import hashlib

@app.route('/request_password_reset', methods=['POST'])
def request_password_reset():
    email = request.form['email']
    client_ip = request.remote_addr
    if not validate_email(email):
        return jsonify({'error': 'Invalid email address'}), 400
    if is_rate_limited(client_ip):
        return jsonify({'error': 'Too many requests, please try again later.'}), 429
    token = generate_reset_token(email)
    send_reset_email(email, token)
    return jsonify({'message': 'Password reset link sent'}), 200

@app.route('/reset_password', methods=['POST'])
def reset_password():
    token = request.form['token']
    if not validate_token(token):
        return jsonify({'error': 'Invalid or expired token'}), 400
    new_password = request.form['new_password']
    confirm_password = request.form['confirm_password']
    if new_password != confirm_password:
        return jsonify({'error': 'Passwords do not match'}), 400
    if not validate_password_strength(new_password):
#-copilot next line-
```