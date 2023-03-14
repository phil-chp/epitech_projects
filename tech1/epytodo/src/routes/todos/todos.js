const db = require('../../config/db')
const mWare = require('../../middleware/auth')
const mWareCheck = require('../../middleware/notFound')

const init_todo = module.exports.init_todo = function (app) {

  app.get('/todo', mWareCheck.token_check, function (req, res) {
    db.pool.query('SELECT * FROM todo', function (err, rows) {
      res.type('application/json')
      if (err) {
        db.handle_errors(res);
      } else if (rows.lenght === 0) {
        res.set('token', req.header('token'))
        res.send(JSON.stringify({msg: "Not Found"}, null, 4));
      } else {
        Object.keys(rows).forEach(function (key) {
          rows[key].due_time   = JSON.stringify(rows[key].due_time)
          rows[key].created_at = JSON.stringify(rows[key].created_at)
        })
        res.set('token', req.header('token'))
        res.send(JSON.stringify(rows, null, 4));
      }
    })
  });


  app.post('/todo', mWareCheck.token_check,  mWareCheck.check_todo, function (req, res) {
    var sql =  `INSERT INTO todo (title, description, due_time, status, user_id)
                VALUES ('${req.body.title}', '${req.body.description}',
                CAST('${req.body.due_time}' AS DATETIME),
                '${req.body.status}', ${req.body.user_id})`
    db.pool.query(sql, function(err, result) {
      if (err)
        db.handle_errors(res)
    })
    db.pool.query('SELECT LAST_INSERT_ID() AS last_id', function(err, result) {
      if (err)
        db.handle_errors(res)
      db.pool.query(`SELECT * FROM todo WHERE id=${result[0].last_id}`, function (err, rows) {
        res.type('application/json')
        if (err)
          db.handle_errors(res)
        rows[0].due_time   = JSON.stringify(rows[0].due_time)
        rows[0].created_at = JSON.stringify(rows[0].created_at)
        res.set('token', req.header('token'))
        res.send(JSON.stringify(rows[0], null, 4))
      })
    })
  });


  app.get('/todo/:id', mWareCheck.token_check, mWare.id_standalone, function(req, res) {
    var sql = `SELECT * FROM todo WHERE id=${req.params.id}`
    db.pool.query(sql, function (err, result) {
      res.type('application/json')
      if (err)
        db.handle_errors(res);
      result[0].due_time   = JSON.stringify(result[0].due_time)
      result[0].created_at = JSON.stringify(result[0].created_at)
      res.set('token', req.header('token'))
      res.send(JSON.stringify(result[0], null, 4));
    })
  });
}
