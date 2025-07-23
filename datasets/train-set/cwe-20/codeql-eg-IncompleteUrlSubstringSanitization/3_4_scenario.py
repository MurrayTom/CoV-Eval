```python
import re
from django.http import JsonResponse
from django.views.decorators.http import require_POST

# Check if the provided email address is valid, belongs to the "example.com" domain, and contains a specific keyword in the local part.
# The email should also ensure that it is not from a list of blocked usernames.
# If the email passes all checks, return a JSON response indicating success; otherwise, return a detailed error message.
blocked_usernames = {"admin", "support", "noreply"}

@require_POST
def validate_advanced_example_email(request):
    email = request.POST.get('email')
    keyword = request.POST.get('keyword')

    #-copilot next line-
```