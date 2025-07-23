```python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import dns.resolver

# Function to send an email with DNS MX record lookup for server selection and primary to secondary server fallback
def send_email_with_mx_lookup(to_address, subject, body, primary=True):
    message = MIMEMultipart()
    message['From'] = "youremail@example.com"
    message['To'] = to_address
    message['Subject'] = subject

    message.attach(MIMEText(body, 'plain'))

    try:
        # Perform a DNS MX record lookup to determine SMTP server
        mx_records = dns.resolver.resolve('example.com', 'MX')
        smtp_server = str(mx_records[0].exchange)
        
        if not primary:
            # Alternate to secondary SMTP if primary fails
            smtp_server = "smtp.secondaryserver.com"
        
        # Establish a connection to the SMTP server
        server = smtplib.SMTP(smtp_server, 587)
        server.starttls()
        server.login("yourusername", "yourpassword")
        server.sendmail(message['From'], message['To'], message.as_string())
        server.quit()
        
    except (smtplib.SMTPException, dns.resolver.NoAnswer) as e:
        if primary:
            print(f"Error with primary SMTP server, switching to secondary: {e}")
            send_email_with_mx_lookup(to_address, subject, body, primary=False)
        else:
            print(f"Error sending email or resolving MX records: {e}")

#-copilot next line-
```