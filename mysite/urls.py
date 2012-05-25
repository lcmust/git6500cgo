from django.conf.urls.defaults import patterns, include, url
from django.views.generic import list_detail
from polls.models import Publisher

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()
###
from django.contrib import admin
###
admin.autodiscover()

publisher_info = {
    'queryset':Publisher.objects.all(),
    'template_name':'publisher_list_page.html',
#    'template_object_name':'publisher',
}

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^mysite/', include('mysite.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    url(r'publishers/$', list_detail.object_list, publisher_info),
    # Uncomment the next line to enable the admin:
    url(r'^admin/', include(admin.site.urls)),
    url(r'^$', 'polls.views.env'),
    url(r'^time/$', 'polls.views.current_datetime'),
    url(r'^time/(\d{1,2})/$', 'polls.views.hours_ahead'),
    url(r'^now_furture/(\d{1,2})/$', 'polls.views.now_furture'),
    url(r'^main_page/$', 'polls.views.main_page'),
    url(r'^home1/$', 'polls.views.home1'),
    url(r'^search1/$', 'polls.views.search1'),
    url(r'^result1/$', 'polls.views.result1'),
    url(r'^program1/$', 'polls.views.program1'),
    url(r'^about1/$', 'polls.views.about1'),
    url(r'^contact/$', 'polls.views.contact'),
    url(r'thanks/$', 'polls.views.thanks'),
    url(r'login/$', 'polls.views.login'),
    url(r'login_auth/$', 'polls.views.login_auth'),
    url(r'logout/$', 'polls.views.logout'),
    url(r'register/$', 'polls.views.register'),
    #css
    #    url(r'^css/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/mnt/sda2h/tools/git1/chengl6500/mysite/templates/static/admin/css/'}),
    url(r'^css/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/usr/local/lib/python2.6/dist-packages/django/contrib/admin/media/css/'}),
    #jpg|png
    #    url(r'^img/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/mnt/sda2h/tools/git1/chengl6500/mysite/templates/static/admin/js/'}),
    url(r'^img/(?P<path>.*)$', 'django.views.static.serve', {'document_root':'/usr/local/lib/python2.6/dist-packages/django/contrib/admin/media/css/'}),
)
##/mnt/sda2h/tools/git1/chengl6500/mysite/
