# coding=utf-8
# Create your views here.
from django.core.mail import send_mail
from django.http import Http404, HttpResponse,HttpResponseRedirect
from django.shortcuts import render_to_response
from django.template import Context,RequestContext,Template
from django.template.loader import get_template
from mysite.polls.models import Book
from django.contrib import auth
from django.contrib.auth.decorators import login_required
import datetime

def env(request):
    values = request.META.items()
    values.sort()
    html = ['<table border="1">']
    for k, v in values:
        html.append('<tr><td>%s</td><td>%s</td></tr>' % (k, v))
    from django.contrib.auth.models import User
    mysql_users = User.objects.all()
    for tmp in mysql_users:
        html.append('<tr><td>mysql_user:</td><td>%s<td></tr>' % tmp)
    html.append("</table>")
    return HttpResponse('<table>%s</table>' % '\n'.join(html))

def current_datetime(request):
    now_time = datetime.datetime.now()
    template = get_template('current_datetime.html')
    content = RequestContext(request, {
        'current_date':now_time,
    })
    return HttpResponse(template.render(content))

def hours_ahead(request, offset):
    try:
        offset = int(offset)
    except ValueError:
        raise Http404()
    now_time = datetime.datetime.now()
    dt = now_time + datetime.timedelta(hours=offset)
    template = get_template('hours_ahead.html')
    content = RequestContext(request, {
        'hour_offset':offset,
        'now':now_time,
        'next_time':dt,
    })
    return HttpResponse(template.render(content))

def now_furture(request, offset):
    try:
        offset = int(offset)
    except ValueError:
        raise Http404()
    now_time = datetime.datetime.now()
    furture_time = now_time + datetime.timedelta(hours=offset)
    t = get_template('now_furture.html')
    content = RequestContext(request,{
        'current_date':now_time,
        'now':now_time,
        'offset':int(offset),
        'furture':furture_time,
    })
    html = t.render(content)
    return HttpResponse(html)

def main_page(request):
    template = get_template('main_page.html')
    variables = RequestContext(request,{
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
    from django.contrib.auth.models import User
    template = get_template('home1.html')
    now = datetime.datetime.now()
    user = username(request)
    if user != 'guest' and user:
        user_id = User.objects.get(username=user).id
    else:
        user_id = None
    body = RequestContext(request, {
        'title':'home1',
        'username':user,
        'user_id':user_id or None,
        'body1':user,
        'body2':now,
    })
    output = template.render(body)
    return HttpResponse(output)
#   return HttpResponse(user)


@login_required(login_url='/login')
def search1(request):
    #if not request.user.is_authenticated():
    #    return HttpResponseRedirect('/login')
    template = get_template('search1.html')
    user = username(request)
    body = RequestContext(request, {
        'title':'search1',
        'username':user,
        'body1':'body1_search1',
        'body2':'body2_search1',
    })
    output = template.render(body)
    return HttpResponse(output)


@login_required(login_url='/login')
def result1(request):
    #if not request.user.is_authenticated():
    #    return HttpResponseRedirect('/login')
    user = username(request)
    if 'q' in request.GET and request.GET['q']:
        template = get_template('result1.html')
        q = request.GET['q']
        books = Book.objects.filter(title__icontains=q)
        body = RequestContext(request, {
            'title':'result1',
            'username':user,
            'books':books,
            'query':q,
        })
    else:
        template = get_template('result0.html')
        body = RequestContext(request, {
            'title':'result1',
            'username':user,
            'books':None,
            'query':None,
        })
    output = template.render(body)
    return HttpResponse(output)

@login_required(login_url='/login')
def program1(request):
    #if not request.user.is_authenticated():
    #    return HttpResponseRedirect('/login')
    user = username(request)
    template = get_template('program1.html')
    body = RequestContext(request, {
        'title':'program1',
        'username':user,
        'body1':'body1_program1',
        'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def about1(request):
    template = get_template('about1.html')
    user = username(request)
    tmp = request.META.items()
    tmp.sort()
    body = RequestContext(request, {
        'title':'about1',
        'username':user,
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
    body = RequestContext(request,{
        'title':'thanks',
        'body1':'thanks for invit',
        'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def login(request):
    template = get_template("login.html")
    #to_where = request.META.get('HTTP_REFERER', 'home1')
    #to_where = request.POST.get('next', '')
    to_where = request.GET.get('next', '')
    #return HttpResponse(to_where)
    body = RequestContext(request,{
        'title':'login',
        'body1':'',
        'next':to_where,
    })
    output = template.render(body)
    return HttpResponse(output)

def login_auth(request):
    UserName = request.POST.get('username', '')
    PassWord = request.POST.get('password', '')
    ToWhere = request.POST.get('next', 'home1')
    AuthUser = auth.authenticate(username=UserName, password=PassWord)
    #to_where = request.META.get('HTTP_REFERER', 'home1')
    if AuthUser is not None and AuthUser.is_active:
        auth.login(request,AuthUser)
        #return HttpResponse(to_where)
        return HttpResponseRedirect(ToWhere)
    else:
        return HttpResponse('welcome %s' % (UserName))
        return HttpResponseRedirect("/thanks/")

def logout(request):
    auth.logout(request)
    return HttpResponseRedirect("/thanks")

def register(request):
    template = get_template('register.html')
    body = RequestContext(request,{
        'title':'register',
        'body1':'thanks for invit',
        'body2':'body2_program1',
    })
    output = template.render(body)
    return HttpResponse(output)

def django_user_all(request):
    from django.contrib.auth.models import User
    entry_list = User.objects.all()
    html = []
    for tmp in entry_list:
        html.append('<tr><td>user:</td><td>%s</td></tr>' % tmp )
    output = ('<html><head><title>user_all</title></head><body><table>%s</table></body></html>' % '\n'.join(html))
    return HttpResponse(output)
