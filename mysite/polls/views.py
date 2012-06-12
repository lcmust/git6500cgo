# coding=utf-8
# Create your views here.
from django.core.mail import send_mail
from django.http import Http404, HttpResponse,HttpResponseRedirect
from django.shortcuts import render_to_response
from django.template import Context,RequestContext,Template
from django.template.loader import get_template
from polls.models import Book
from django.contrib import auth
import datetime

def env(request):
	values = request.META.items()
	values.sort()
	html = ['<table border="1">']
	for k, v in values:
		html.append('<tr><td>%s</td><td>%s</td></tr>' % (k, v))
	html.append("</table>")
	return HttpResponse('<table>%s</table>' % '\n'.join(html))

def list_client_url(request):
	try:
		client_url_all = request.META.items()
	except  KeyError:
		client_url_all = 'unknown'
	client_url_all.sort()
	html = []
	for k,v in client_url_all:
	    html.append('<tr><td>%s</td><td>%s</td></tr>' %(k,v))
	return client_url_all

def time(request):
	now = datetime.datetime.now()
	html = "<html><body> You're at the poll index. It's now %s </body></html>" %now
	return HttpResponse(html)

def current_datetime(request):
	now_time = datetime.datetime.now()
	furture_time = now_time + datetime.timedelta(hours=6)
	return render_to_response('current_datetime.html', {'current_date':now_time,'furture':furture_time})

def hours_ahead(request, offset):
	try:
	    offset = int(offset)
	except ValueError:
	    raise Http404()
	now_time = datetime.datetime.now()
	dt = now_time + datetime.timedelta(hours=offset)
	return render_to_response('hours_ahead.html', {'hour_offset':offset,'now':now_time, 'next_time':dt})

def now_furture(request, offset):
	try:
	    offset = int(offset)
	except ValueError:
	    raise Http404()
	now_time = datetime.datetime.now() 
	furture_time = now_time + datetime.timedelta(hours=offset)
	t = get_template('now_furture.html')
	content = Context({'current_datetime':now_time,'now':now_time,'furture':furture_time})
	html = t.render(content)
	return HttpResponse(html)

def main_page(request):
  template = get_template('main_page.html')
  variables = Context({
    'head_title': 'Django Bookmarks',
    'page_title': 'Welcome to Django Bookmarks',
    'page_body': 'Where you can store and share bookmarks!'
  })
  output = template.render(variables)
  return HttpResponse(output)

def username(request):
    #user用于欢迎界面，如果是未登录用户，则显示guest，否则显示登录名
    if request.user.is_anonymous():
      user = "guest"
    else:
      user = request.user
    return user  

def home1(request):
    template = get_template('home1.html')
    now = datetime.datetime.now()
    user = username(request) 
    body = Context({
      'username':user,
      'body1':user,
      'body2':now,
    })
    output = template.render(body)
    return HttpResponse(output)
#   return HttpResponse(user)


def search1(request):
    if not request.user.is_authenticated():
      return HttpResponseRedirect('/login')
    template = get_template('search1.html')
    user = username(request) 
    body = Context({
      'username':user,
      'body1':'body1_search1',
      'body2':'body2_search1',
    })
    output = template.render(body)
    return HttpResponse(output)

def result1(request):
    if not request.user.is_authenticated():
      return HttpResponseRedirect('/login')
    if 'q' in request.GET and request.GET['q']:
      template = get_template('result1.html')
      q = request.GET['q']
      books = Book.objects.filter(title__icontains=q)
      body = Context({
        'books':books,
        'query':q,
      })
    else:
      template = get_template('result0.html')
      body = Context({
        'books':None,
        'query':None,
      })
    output = template.render(body)
    return HttpResponse(output)

def program1(request):
    if not request.user.is_authenticated():
      return HttpResponseRedirect('/login')
    template = get_template('program1.html')
    body = Context({
      'body1':'body1_program1',
      'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def about1(request):
    template = get_template('about1.html')
    tmp = request.META.items()
    tmp.sort()
    body = RequestContext(request,{
	'body2':tmp,
    })
    output = template.render(body)
    return HttpResponse(output)

def contact(request):
    if not request.user.is_authenticated():
        return HttpResponseRedirect('/login')
    errors = []
    if request.method == 'POST':
       if not request.POST.get('subject',''):
           errors.append('\r\nEnter a subject.')
       if not request.POST.get('message',''):
           errors.append('Enter a message.')
       if not request.POST.get('email') and '@' not in request.POST['email']:
           errors.append('Enter a valid e-mail address.')
       if not errors:
           return HttpResponseRedirect('/thanks/')
       """tmp
       send_mail(
         request.POST['subject'],
         request.POST['message'],
         request.POST.get('email','abc@qq.com'),
         )
       tmp"""
    template = get_template('contact1.html')
    body = RequestContext(request,{
          'body1':errors,
	  'subject':request.POST.get('subject',''),
          'message':request.POST.get('message',''),
          'email':request.POST.get('email',''),
    })
    output = template.render(body)
    return HttpResponse(output)

def thanks(request):
    template = get_template('thanks1.html')
    body = Context({
      'body1':'thanks for invit',
      'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def login(request):
    template = get_template("login.html")
    body = RequestContext(request,{
      'body1':'',
    })
    output = template.render(body)
    return HttpResponse(output)

def login_auth(request):
    username = request.POST.get('username', '')
    password = request.POST.get('password', '')
    user = auth.authenticate(username=username, password=password)
    if user is not None and user.is_active:
      auth.login(request,user)
      return HttpResponseRedirect("/home1/")
    else:
      return HttpResponseRedirect("/thanks/")

def logout(request):
    auth.logout(request)
    return HttpResponseRedirect("/thanks")

def register(request):
    template = get_template('register.html')
    body = Context({
      'body1':'thanks for invit',
      'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def django_user_all(request):
    from django.contrib.auth.models import User
    entry_list = User.objects.all().values()[0]
    html = "<html><head></head><body> {%for tmp in entry_list%} {{tmp}}  {%endfor%} </body></html>" 
    t = Template(html)
    c = Context(entry_list)
    return t.render(c)
