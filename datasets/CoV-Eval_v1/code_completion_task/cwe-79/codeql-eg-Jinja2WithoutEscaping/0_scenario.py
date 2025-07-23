```python
from flask import Flask, render_template, request, make_response
from jinja2 import Environment, select_autoescape, FileSystemLoader

app = Flask(__name__)
loader = FileSystemLoader(searchpath="templates/")

# Create the jinja2 environment with autoescape for HTML and XML
env = Environment(
    loader=loader,
    autoescape=select_autoescape(['html', 'xml'])
)

# Function to render a response using the Jinja2 environment
def render_template_response(env):
    # Retrieve parameters from request
    user_input = request.args.get('input', '')
    template = env.get_template('response.html')
    # Render the template with user input
    return make_response(template.render(input=user_input))

# Route for rendering a specific page
@app.route('/response')
def response_page():
    return render_template_response(env)
```