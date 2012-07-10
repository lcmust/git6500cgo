from django.conf.urls.defaults import patterns, include, url
from django.views.generic import list_detail
from mysite.polls.models import Publisher

# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()

publisher_info = {
    'queryset':Publisher.objects.all(),
    'template_name':'publisher_list_page.html',
#    'template_object_name':'publisher',
}

urlpatterns = patterns('mysite.polls.views',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^mysite/', include('mysite.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    url(r'publishers/$', list_detail.object_list, publisher_info),
    # Uncomment the next line to enable the admin:
    url(r'^admin/', include(admin.site.urls)),
    url(r'^$', 'env'),
    url(r'^time/$', 'current_datetime'),
    url(r'^time/(\d{1,2})/$', 'hours_ahead'),
    url(r'^now_furture/(\d{1,2})/$', 'now_furture'),
    url(r'^main_page/$', 'main_page'),
    url(r'^home1/$', 'home1'),
    url(r'^search1/$', 'search1'),
    url(r'^result1/$', 'result1'),
    url(r'^program1/$', 'program1'),
    url(r'^about1/$', 'about1'),
    url(r'^contact/$', 'contact'),
    url(r'^thanks/$', 'thanks'),
    url(r'^login/$', 'login'),
    url(r'^login_auth/$', 'login_auth'),
    url(r'^logout/$', 'logout'),
    url(r'^register/$', 'register'),
    url(r'^user_all/$', 'django_user_all'),
    #django-css
    #url(r'^css/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/usr/local/lib/python2.6/dist-packages/django/contrib/admin/media/css/'}),
    #django-jpg|png
    #url(r'^img/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/usr/local/lib/python2.6/dist-packages/django/contrib/admin/media/css/'}),
    #myapp-css
    url(r'^css/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/home/love/cl-dep/mysite/templates/static/css/'}),
    #myapp-jpg|png
    #url(r'^static/img/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/home/love/cl-dep/mysite/templates/static/img/'}),
)
