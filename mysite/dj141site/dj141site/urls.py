from django.conf.urls import patterns, include, url

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
    url(r'^$', include('app1.urls')),
    url(r'^test/$', 'app1.views.hello'),
    url(r'^a/$', 'app1.views.index'),

)
