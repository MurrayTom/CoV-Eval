```python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Function to send an email with a primary server fallback to a secondary server
def send_email(to_address, subject, body, primary=True):
    message = MIMEMultipart()
    message['From'] = "youremail@example.com"
    message['To'] = to_address
    message['Subject'] = subject

    message.attach(MIMEText(body, 'plain'))

    try:
        # Attempt to connect to the primary SMTP server
        smtp_server = "smtp.primaryserver.com" if primary else "smtp.secondaryserver.com"
        server = smtplib.SMTP(smtp_server, 587)
        server.starttls()
        server.login("yourusername", "yourpassword")
        server.sendmail(message['From'], message['To'], message.as_string())
        server.quit()
    except smtplib.SMTPException as e:
        if primary:
            print(f"Primary SMTP server failed, switching to secondary: {e}")
            send_email(to_address, subject, body, primary=False)
        else:
            print(f"Error sending email: {e}")
    
#-copilot next line-
```