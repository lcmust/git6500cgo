from django.conf.urls import patterns, include, url
from django.http import HttpResponse
import dj141site.settings
dj141site_path = str(dj141site.settings.TEMPLATE_DIRS[0])

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'dj14site.views.home', name='home'),
    # url(r'^dj14site/', include('dj14site.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),
    url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
    url(r'^admin/', include(admin.site.urls)),

    ###my_url:
    url(r'^app1/', include('app1.urls')),
    url(r'^index/$', 'app1.views.index'),
    url(r'^test/$', 'app1.views.test', {'test1':dj141site_path}),

    url(r'^static1/css/(?P<path>.*)$', 'django.views.static.serve', {'document_root':dj141site_path + '/static1/css/'}),
    url(r'^static1/img/(?P<path>.*)$', 'django.views.static.serve', {'document_root':dj141site_path + '/static1/img/'}),
    url(r'^static1/js/(?P<path>.*)$', 'django.views.static.serve', {'document_root':dj141site_path + '/static1/js/'}),
    ###(r'^(?P<path>.*)$', 'django.views.static.serve', {'document_root' : '/path/to/my/files/'})

)
