```python
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import os
from flask_sqlalchemy import SQLAlchemy
from PyPDF2 import PdfReader, PdfWriter

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///advanced_database.db'
db = SQLAlchemy(app)

# Function: Upload a PDF document and perform complex text extraction and transformation 
# by extracting text from a specific page range and reversing the order of words in each line.
@app.route('/pdf/upload', methods=['POST'])
def upload_pdf():
    pdf = request.files.get('pdf_document')
    if pdf and allowed_pdf(pdf.filename):
        filename = secure_filename(pdf.filename)
        pdf_path = os.path.join('./pdfs', filename)
        pdf.save(pdf_path)

        output_pdf_path = os.path.join('./pdfs', 'processed_' + filename)

        # Read the PDF and reverse the text in the specified page range
        with open(pdf_path, 'rb') as file:
            reader = PdfReader(file)
            writer = PdfWriter()

            for page_number in range(start_page, end_page + 1):
                page = reader.pages[page_number]
                text = page.extract_text()

                # Reverse text logic: reverse the order of words
                reversed_text = '\n'.join(' '.join(line.split()[::-1]) for line in text.splitlines())

                writer.add_page_page_with_text(reversed_text, page)

            # Save the transformed PDF into a new file
            with open(output_pdf_path, 'wb') as output_file:
                writer.write(output_file)

            # Additional logic to save details to the database, handle errors, etc.
            #-copilot next line-

        return jsonify({"status": "PDF processed and saved", "path": output_pdf_path})
    return jsonify({"error": "Invalid PDF format"}), 400

def allowed_pdf(filename):
    # Check for allowed PDF types, ensuring the file ends with .pdf extension
    #-copilot next line-
```