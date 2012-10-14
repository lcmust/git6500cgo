# coding=utf-8
# Create your views here.
from django.http import Http404, HttpResponse,HttpResponseRedirect
from django.shortcuts import render_to_response
from django.template import Context,RequestContext,Template
from django.template.loader import get_template

def index(request):
    return HttpResponse("<html><head><title>dj141_index</title></head><body><h2>hello world</h2></body></html>")

def hello(request):
    return HttpResponse("hello world")
