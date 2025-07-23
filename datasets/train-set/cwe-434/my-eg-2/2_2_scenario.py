```python
from fastapi import FastAPI, HTTPException, File, UploadFile
import hashlib
import motor.motor_asyncio

app = FastAPI()

# Connect to MongoDB and manage image uploads.
# Ensure the uploaded image is either TIFF or BMP and is less than 500KB.
# Compute a SHA-512 hash of the image file for integrity purposes before storing.
@app.post("/image/upload")
async def upload_image(file: UploadFile = File(...)):
    client = motor.motor_asyncio.AsyncIOMotorClient('mongodb://localhost:27017')
    db = client.my_database
    image_collection = db.images
    file_data = await file.read()

    # Check the content type to ensure it is an image (TIFF or BMP)
    #-copilot next line-
```