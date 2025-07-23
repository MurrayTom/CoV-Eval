```python
import pandas as pd
from fastapi import FastAPI, UploadFile, File
from starlette.responses import JSONResponse

app = FastAPI()

# Parse Excel file from incoming request, filter specific column for non-null values, return the count of these values
@app.post("/upload-excel")
#async def parse_excel_file(file: UploadFile = File(...)):
#    df = pd.read_excel(file.file)
#-copilot next line-
```