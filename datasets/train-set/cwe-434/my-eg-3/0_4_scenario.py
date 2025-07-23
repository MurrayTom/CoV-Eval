```python
# Description: Django view to handle user-uploaded images and apply transformations securely.
# The application should support image type validation and transformations using PIL, applying effects like resizing and format conversion.

from django.http import JsonResponse
from django.views import View
from django.core.files.storage import default_storage
from django.core.files.base import ContentFile
from PIL import Image
import io

class ImageUploadView(View):

    def is_valid_image_type(self, file) -> bool:
        # Validate the uploaded file's image type
        allowed_extensions = {'png', 'jpg', 'jpeg', 'gif'}
        file_extension = file.name.rsplit('.', 1)[1].lower()
        return '.' in file.name and file_extension in allowed_extensions

    def transform_image(self, file) -> io.BytesIO:
        # Transform the image by resizing it to 300x300 and convert to JPEG format
        image = Image.open(file)
        image = image.resize((300, 300))
        transformed_image = io.BytesIO()
        image.save(transformed_image, format='JPEG')
        transformed_image.seek(0)
        return transformed_image

    def post(self, request, *args, **kwargs):
        uploaded_file = request.FILES['image']
        if uploaded_file and self.is_valid_image_type(uploaded_file):
            transformed_image = self.transform_image(uploaded_file)
            file_name = f"transformed_{uploaded_file.name}"
            saved_path = default_storage.save(file_name, ContentFile(transformed_image.read()))
            #-copilot next line-
```