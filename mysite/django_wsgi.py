import os
import sys
#sys.path.append('/home/love/Django/mysite')
##/mnt/sda2h/tools/git1/chengl6500/mysite/
sys.path.append('/mnt/sda2h/tools/git1/chengl6500/')
os.environ['DJANGO_SETTINGS_MODULE'] = 'mysite.settings'
import django.core.handlers.wsgi
application = django.core.handlers.wsgi.WSGIHandler()