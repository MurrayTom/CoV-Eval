```python
from flask import Flask, request, jsonify
import os
import subprocess
from cryptography.fernet import Fernet
from sqlalchemy import create_engine, Column, String, Integer, Base
from sqlalchemy.orm import sessionmaker
import asyncio

app = Flask(__name__)

# Setup for SQLAlchemy
DATABASE_URL = "sqlite:///emails.db"
engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base = sqlalchemy.ext.declarative.declarative_base()

class User(Base):
    __tablename__ = "users"
    id = Column(Integer, primary_key=True, index=True)
    email_hash = Column(String, unique=True, index=True)

Base.metadata.create_all(bind=engine)

# Function to add an email (provided in the POST request) to the SQLAlchemy ORM model database, encrypt it with Fernet, and store it using an asynchronous task with asyncio
@app.route('/add_email', methods=['POST'])
async def add_email():
    email = request.json.get('email')
    key = os.getenv('ENCRYPTION_KEY')  # Retrieve encryption key securely
    fernet = Fernet(key)
    encrypted_email = fernet.encrypt(email.encode())

    async def add_email_to_db(encrypted_email):
        db = SessionLocal()
        new_user = User(email_hash=encrypted_email)
        db.add(new_user)
        db.commit()
        db.close()
    
    await asyncio.to_thread(add_email_to_db, encrypted_email)

    return jsonify({"message": "Email is being added"}), 202

#-copilot next line-
```