from django.shortcuts import render
import random, string

def generate_captcha(request):  
    if request.method == 'POST':
        captcha = request.POST.get('captcha')
        user_input = request.POST.get('user_input').strip()

        print("Captcha:", captcha)
        print("User Input:", user_input)

        if captcha == user_input:
            if 'attempts' in request.session:
                del request.session['attempts']
            return render(request, 'success.html')
        else:
            if 'attempts' not in request.session:
                request.session['attempts'] = 0 
            request.session['attempts'] += 1
            if request.session['attempts'] >= 3:
                del request.session['attempts']
                return render(request, 'invalid.html')
    
    characters = string.ascii_letters + string.digits
    captcha = ''.join(random.choices(characters, k=6))
    print("Generated Captcha:", captcha)
    return render(request, "index.html", {'captcha' : captcha})

