const jwt = require('jsonwebtoken')
const db = require('../../config/db')
const mWareCheck = require('../../middleware/notFound')

const init_user = module.exports.init_user = function (app) {

  app.get('/user', mWareCheck.token_check, (req, res) => {
    var sql = `SELECT * FROM user WHERE email='${jwt.verify(req.header('token'), process.env.SECRET)}'`
    db.pool.query(sql, function (err, result) {
      if (err) db.handle_errors(res);
      res.set('token', req.header('token'))
      res.type('application/json')
      result[0].created_at = JSON.stringify(result[0].created_at)
      res.send(JSON.stringify(result[0], null, 4));
    })
  });


  app.get('/user/:unique', mWareCheck.token_check,
  mWareCheck.check_id, mWareCheck.check_email, (req, res) => {
    var sql = `SELECT * FROM user WHERE email='${req.params.unique}'`
    db.pool.query(sql, function (err, result) {
      if (err)
        db.handle_errors(res);
        res.type('application/json')
      res.set('token', req.header('token'))
      result[0].created_at = utils.correctDate(JSON.stringify(result[0].created_at))
      res.send(JSON.stringify(result[0], null, 4));
    })
  });


  app.get('/user/todos', mWareCheck.token_check, (req, res) => {
    var sql = `SELECT * FROM user WHERE email='${jwt.verify(req.header('token'), process.env.SECRET)}'`
    db.pool.query(sql, function (err, result) {
      if (err)
        db.handle_errors(res);
      sql = `SELECT * FROM todo WHERE user_id=${result[0].id}`
      db.pool.query(sql, function (err, todos) {
        res.type('application/json')
        if (err) {
          db.handle_errors(res);
        } else if (todos[0] != undefined) {
          res.set('token', req.header('token'))
          todos.forEach(element => {
            element.created_at = JSON.stringify(element.created_at)
            element.due_time   = JSON.stringify(element.due_time)
          });
          res.send(JSON.stringify(todos, null, 4));
        } else {
          res.status(404)
          res.set('token', req.header('token'))
          res.send(JSON.stringify({msg: "No todos found for this user."}))
        }
      })
    })
  });
}
