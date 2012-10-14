#all the imports
import sqlite3
from flask import Flask, request, session, g, redirect, url_for,\
	abort, render_template, flash

#configuration
DATABASE = './sqlite3.db'
DEBUG = True
SECRET_KEY = 'development key'
USERNAME = 'admin'
PASSWORD = 'admin'

app = Flask(__name__)
app.config.from_object(__name__)
app.config.from_envvar('FALSKR_SETTINGS', silent=True)

def connect_db():
    return sqlite3.connect(app.config['DATABASE'])

def init_db():
    with closeing(connect_db()) as db:
        with app.open_resource('schema.sql') as f:
            db.cursor().executescript(f.read())
            db.commit()

@app.before_request
def before_request():
    g.db = connect_db()

@app.teardown_request
def teardown_request(exception):
    if hasattr(g,'db'):
        g.db.close()

def show_the_login_form():
    pass

def valid_login(username="None", password="None"):
    if username == "admin" and password == "admin":
        #return "Welcome %s" % username
        return True
    else:
        return None

def login_the_user_in(username="None"):
    navigation = (
        {"href":"home", "caption":"home"}, {"href":"about", "caption":"about"}, {"href":"logout", "caption":"logout"})
    return render_template("index.html", username=username, navigation=navigation)


@app.route('/')
def show_entries():
    navigation = (
        {"href":"home", "caption":"home"}, {"href":"about", "caption":"about"}, {"href":"login", "caption":"login"})
    g.db = connect_db()
    cur = g.db.execute('select title,text,create_datetime,modifi_datetime,auth from entries ')
    entries = [dict(title=row[0],text=row[1],create_datetime=row[2],modifi_datetime=row[3],author=row[4]) for row in cur.fetchall()]
    if entries:
        return render_template('show_entries.html', entries=entries, navigation=navigation)
    else:
        return redirect(about)

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
