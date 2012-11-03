from django.conf.urls import patterns, include, url

urlpatterns = patterns('',
    # url(r'^$', 'dj14site.views.home', name='home'),
    # url(r'^dj14site/', include('dj14site.foo.urls')),
                       #my_url
                       url(r'^$', 'app1.views.welcome'),
                       url(r'^welcome$', 'app1.views.welcome'),
)
