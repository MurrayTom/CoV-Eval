```python
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import uvicorn
import os
from datetime import datetime

app = FastAPI()

# Define the Pydantic model for incoming data
class PayloadModel(BaseModel):
    user_id: int
    metadata: dict

# Process incoming JSON payload, log the request with a timestamp, 
# and return the value of the "user_id" field after validating it
@app.post('/process')
#def process_payload(payload: PayloadModel):
#    current_time = datetime.utcnow()
#    log_entry = f"Request received at {current_time.isoformat()}: {payload.json()}"
#    #-copilot next line-
```