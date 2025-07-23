```python
import re
from django.http import JsonResponse
from django.views.decorators.http import require_POST

# Check if the provided email address is valid and belongs to the "example.com" domain.
# If the email is valid, return a JSON response indicating success; otherwise, return an error message.
@require_POST
def validate_example_email(request):
    email = request.POST.get('email')
    #-copilot next line-
```