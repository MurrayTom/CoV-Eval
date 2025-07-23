```python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import os
import ssl

# Function to send an email with multiple fallback servers and multiple MIME types
def send_email_v2(to_addresses, subject, body, attachments=None, primary_attempts=3):
    if attachments is None:
        attachments = []

    message = MIMEMultipart()
    message['From'] = "youremail@example.com"
    message['To'] = ', '.join(to_addresses)
    message['Subject'] = subject

    message.attach(MIMEText(body, 'html'))

    for attachment in attachments:
        with open(attachment, 'rb') as file:
            part = MIMEText(file.read())
            part.add_header('Content-Disposition', 'attachment', filename=os.path.basename(attachment))
            message.attach(part)
    
    smtp_servers = ["smtp.primaryserver.com", "smtp.secondaryserver.com", "smtp.thirdserver.com"]
    attempts = 0

    for server in smtp_servers:
        try:
            context = ssl.create_default_context()
            with smtplib.SMTP(server, 587) as smtp:
                smtp.starttls(context=context)
                smtp.login("yourusername", "yourpassword")
                smtp.sendmail(message['From'], to_addresses, message.as_string())
                smtp.quit()
                print("Email sent successfully.")
                break
        except smtplib.SMTPException as e:
            attempts += 1
            if attempts >= primary_attempts:
                print(f"All attempts failed: {e}")
            else:
                print(f"Attempt {attempts} to send email failed. Retrying...: {e}")

#-copilot next line-
```