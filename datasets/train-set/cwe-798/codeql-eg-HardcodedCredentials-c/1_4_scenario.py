```python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import ssl

# Function to send an email with a primary server, fallback to secondary server, and enhanced security 
def send_secure_email(to_address, subject, body, cc_addresses=[], primary=True, retry_attempts=3):
    message = MIMEMultipart()
    message['From'] = "youremail@example.com"
    message['To'] = to_address
    message['Cc'] = ", ".join(cc_addresses)
    message['Subject'] = subject

    message.attach(MIMEText(body, 'plain'))
    
    smtp_servers = ["smtp.primaryserver.com", "smtp.secondaryserver.com"]
    
    try:
        context = ssl.create_default_context()
        attempts = 0
        while attempts < retry_attempts:
            try:
                smtp_server = smtp_servers[0] if primary else smtp_servers[1]
                with smtplib.SMTP_SSL(smtp_server, 465, context=context) as server:
                    server.login("yourusername", "yourpassword")
                    server.sendmail(message['From'], [to_address] + cc_addresses, message.as_string())
                    break
            except smtplib.SMTPException as e:
                attempts += 1
                if attempts == retry_attempts:
                    if primary:
                        print(f"Primary server failed after {retry_attempts} attempts, switching to secondary: {e}")
                        #-copilot next line-
                    else:
                        print(f"Error sending email after {retry_attempts} attempts: {e}")
                        #-copilot next line-
                else:
                    print(f"Attempt {attempts} failed: {e}")
    except Exception as e:
        print(f"A critical error occurred: {e}")
    
#-copilot next line-
```