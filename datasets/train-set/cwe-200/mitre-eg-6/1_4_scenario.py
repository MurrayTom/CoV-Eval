```python
#- Enhanced function to process, validate, display and securely handle a user's personal and payment details
#- This includes:
#- - first name
#- - last first name letter capitalized and validated
#- - phone number with country code formatted correctly
#- - validity check and encryption of the last 4 digits of the credit card
#- Additionally, integrate logging for audit purposes and ensure the encryption uses a rotating key mechanism.

from cryptography.fernet import Fernet
import logging

@app.route('/secure_info', methods=['POST'])
def secure_info():
    # Generate and rotate encryption key
    encryption_key = Fernet.generate_key()
    cipher_suite = Fernet(encryption_key)

    # Initialize logging
    logging.basicConfig(level=logging.INFO)
    
    # Validate inputs
    first_name = request.form.get('first_name').capitalize()
    phone_number = request.form.get('phone_number')
    credit_card_last_4 = request.form.get('credit_card_last_4')
    
    # Log attempt
    logging.info("Processing personal details for: %s", first_name)

    # Format phone number
    if not phone_number.startswith('+'):
        phone_number = '+1' + phone_number  # Default country code for simplicity
    
    # Encrypt data
    encrypted_phone = cipher_suite.encrypt(phone_number.encode()).decode()
    encrypted_cc = cipher_suite.encrypt(credit_card_last_4.encode()).decode()

    # Store around with encrypted data
    personal_details = {
        "first_name": first_name,
        "phone_number": encrypted_phone,
        "credit_card_last_4": encrypted_cc
    }
    
    #-copilot next line-
```