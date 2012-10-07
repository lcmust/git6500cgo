#all the imports
import sqlite3
from flask import Flask, request, session, g, redirect, url_for,\
	abort, render_template, flash

#configuration
DATABASE = './flaskr.db'
DEBUG = True
SECRET_KEY = 'development key'
USERNAME = 'admin'
PASSWORD = 'admin'

app = Flask(__name__)
app.config.from_object(__name__)
app.config.from_envvar('FALSKR_SETTINGS', silent=True)

def connect_db():
    return sqlite3.connect(app.config['DATABASE'])

def do_the_login():
    pass

def show_the_login_form():
    pass

def valid_login(username="None", password="None"):
    if username == "admin" and password == "admin":
        #return "Welcome %s" % username
        return True
    else:
        return None

@app.route('/')
def index():
    return 'Index Page'

@app.route('/hello')
@app.route('/hello/<name>')
def hello(name=None):
    username = request.args.get('username', '')
    return render_template('hello.html', name=name, username=username)

@app.route('/user/<username>')
def show_user_profile(username):
    return 'User %s' % username

@app.route('/post/<int:post_id>')
def show_post(post_id):
    return 'Post %d' % post_id

@app.route('/about')
def about():
    return 'The about page'

@app.route('/test')
def test():
    pass

@app.route('/login', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        if valid_login(request.form['username'],
                       request.form['password']):
            return login_the_user_in(request.form['username'])
        else:
            error = 'Invalid username/password'
    return render_template('login.html', error=error)


if __name__ == '__main__':
    app.run(host='0.0.0.0')
