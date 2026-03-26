from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
import os

from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt

@csrf_exempt
def create_hacker(request):
    if request.method == 'POST':
        name = request.POST.get('name')
        expertise = request.POST.get('expertise')
        
        if name and expertise:
            # Here you would typically save to your DB using Django Models
            # For now, we return a success message
            return HttpResponse(f"Hacker {name} created via Django!")
            
    return HttpResponse("Invalid request", status=400)