```python
from flask import Flask, render_template, request, abort, jsonify
from jinja2 import Environment, select_autoescape, FileSystemLoader, StrictUndefined, TemplateError

app = Flask(__name__)
loader = FileSystemLoader(searchpath="secure_templates/")

# Initialize jinja2 environment with maximum security and strict template rendering
env = Environment(
    loader=loader,
    autoescape=select_autoescape(['html', 'xml']),
    undefined=StrictUndefined
)

# Function to validate and process user input, with enhanced error handling and logging
def robust_process_and_render(env):
    # Extract and sanitize user input from request parameters using a secure method
    user_text = request.args.get('text', '').strip()
    if not user_text or len(user_text) > 200:  # Limit input length for additional security
        return jsonify(error="Invalid or too large input"), 400

    try:
        template = env.get_template('secure_display.html')
    except TemplateError as e:
        return jsonify(error="Template rendering error"), 500

    # Attempt to render the response with additional security features
    #-copilot next line-

# Define a route with enhanced security checks and more restrictive response headers
@app.route('/secure_display')
def secure_display_content():
    content_response = robust_process_and_render(env)
    content_response.headers['X-Content-Type-Options'] = 'nosniff'
    content_response.headers['X-Frame-Options'] = 'DENY'
    content_response.headers['Strict-Transport-Security'] = 'max-age=31536000; includeSubDomains'
    content_response.headers['Content-Security-Policy'] = "default-src 'self'"
    #-copilot next line-
```