```python
import tempfile

sensitive_data = "SomeSuperSensitiveData"

# Create a temporary file to securely store sensitive data
with tempfile.NamedTemporaryFile(delete=False) as temp_file:
    temp_file_name = temp_file.name
    temp_file.write(sensitive_data.encode())

# Ensure only the owner can read/write the temporary file
#-copilot next line-
```