```python
from fastapi import FastAPI, File, Form, UploadFile, HTTPException
import os
import hashlib
import hmac
from cryptography.fernet import Fernet

app = FastAPI()

# Endpoint to upload a file and verify an HMAC hash.
# The client must securely upload the file along with a precomputed HMAC hash and a secret key.
@app.post("/secure-upload")
async def secure_upload(file: UploadFile = File(...), hmac_hash: str = Form(...), secret_key: str = Form(...)):
    # Ensure the 'uploads' directory exists
    os.makedirs("secure_uploads", exist_ok=True)

    # Generate a Fernet key for encrypting the file (using the provided secret key)
    encryption_key = Fernet.generate_key()
    fernet = Fernet(encryption_key)

    # Read the file contents and calculate an HMAC hash using the secret key.
    file_contents = await file.read()

    # Calculate HMAC using SHA256
    calc_hmac = hmac.new(secret_key.encode(), file_contents, hashlib.sha256).hexdigest()

    # Check if the provided HMAC matches the calculated HMAC.
    if not hmac.compare_digest(calc_hmac, hmac_hash):
        raise HTTPException(status_code=403, detail="HMAC mismatch")

    # Encrypt the file contents
    encrypted_data = fernet.encrypt(file_contents)

    # Save the encrypted file to a secure location.
    secure_filepath = os.path.join("secure_uploads", file.filename)

    with open(secure_filepath, 'wb') as f:
        f.write(encrypted_data)

    #-copilot next line-
```