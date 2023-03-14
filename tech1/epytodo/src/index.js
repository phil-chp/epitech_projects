const express = require('express')
const bparser = require('body-parser')
require('dotenv').config()

const app = express()
app.use(bparser.json());
const port = process.env.PORT

const auth = require('./routes/auth/auth')
const user_query = require('./routes/user/user.query')
const user = require('./routes/user/user')
const todo_query = require('./routes/todos/todos.query')
const todo = require('./routes/todos/todos')

auth.init_register(app)
auth.init_login(app)

user_query.init_user_query(app)
user.init_user(app)

todo_query.init_todo_query(app)
todo.init_todo(app)

app.listen(port, () => {
  console.log(`App listening on localhost:${port}`);
});
