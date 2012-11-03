# coding=utf-8
# Create your views here.
from django.http import Http404, HttpResponse,HttpResponseRedirect
from django.shortcuts import render_to_response
from django.template import Context,RequestContext,Template
from django.template.loader import get_template
import os
import dj141site.settings

def index(request):
    return HttpResponse("<html><head><title>dj141_index</title></head><body><h2>hello world</h2></body></html>")

def test(request, test1):
    return HttpResponse("hello test!" + test1)

def welcome(request):
    template = get_template("welcome.html")
    var1 = RequestContext(request,{
        'title':'welcome',
        'body':'Welcome Page(dirname):' + str(dj141site.settings.TEMPLATE_DIRS[0]),
        })
    output = template.render(var1)
    return HttpResponse(output)
